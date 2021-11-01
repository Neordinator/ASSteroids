#pragma once

#include <time.h>
#include <list>

#include "SpankShip.h"
#include "ASSteroid.h"
#include "Bullet.h"

void playMainStage(RenderWindow& window, const int resolutionX, const int resolutionY)
{
	Texture T_background;
	Texture T_bigASSteroid;
	//Texture T_smallASSteroid;
	Texture T_spankShip;
	//Texture T_turbineFire;
	//Texture T_explosionRock;
	//Texture T_explosionShip;
	Texture T_plasmBullet;

	// загрузка всех текстур *.png
	T_background.loadFromFile("src/cosmoBillyFone.png");
	T_bigASSteroid.loadFromFile("src/bigASSteroid.png");
	//T_smallASSteroid.loadFromFile("src/smallASSteroid.png");
	T_spankShip.loadFromFile("src/spankShip.png");
	//T_turbineFire.loadFromFile("src/turbineFire.png");
	//T_explosionRock.loadFromFile("src/explosions/type_A.png");
	//T_explosionShip.loadFromFile("src/explosions/type_B.png");
	T_plasmBullet.loadFromFile("src/plasmBullet.png");

	Sprite background(T_background);
	background.setScale(float(resolutionX) / T_background.getSize().x, float(resolutionY) / T_background.getSize().y);

	std::list<Actor*> actors;

	SpankShip* player = new SpankShip(T_spankShip);
	actors.push_back(player);

	srand(time(0));
	Clock clock;
	unsigned int time = 0;

	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMilliseconds();
		if (time >= 5000)
		{
			ASSteroid* big = new ASSteroid(T_bigASSteroid, rand() % 7, rand() % 7, rand() % W, rand() % H, rand() % 360, rand() % 11, rand() % (-15), 0.8);
			actors.push_back(big);
			clock.restart();
			time = 0;
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					Bullet* bullet = new Bullet(T_plasmBullet, rand() % 3, rand() % 2, player->getSprite(), player->getAngle());
					actors.push_back(bullet);
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player->turnRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player->turnLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player->thrust = true;
		} else {
			player->thrust = false;
		}

		for (auto element : actors)
		{
			element->update();
		}
		for (auto actor1 : actors)
		{
			for (auto actor2 : actors)
			{
				if (actor1->name == "player" && (actor2->name == "big" ||  actor2->name == "small"))
				{
					if (actor1->isCollide(actor2))
					{
						actor1->life = false;
						goto GARBAGE; //отвратительно, я знаю)
					}
				}
				if (actor1->name == "big" && actor2->name == "bullet")
				{
					if (actor1->isCollide(actor2))
					{
						actor1->life = false;
						actor2->life = false;
						ASSteroid* small1 = new ASSteroid(T_bigASSteroid, rand() % 7, rand() % 7, actor1->getX(), actor1->getY(), rand() % 360, rand() % 11, rand() % (-15), 0.33);
						actors.push_back(small1);
						ASSteroid* small2 = new ASSteroid(T_bigASSteroid, rand() % 7, rand() % 7, actor1->getX(), actor1->getY(), rand() % 360, rand() % 11, rand() % (-15), 0.33);
						actors.push_back(small2);
					}
				}
				if (actor1->name == "small" && actor2->name == "bullet")
				{
					if (actor1->isCollide(actor2))
					{
						actor1->life = false;
						actor2->life = false;
					}
				}
			}
		}
		window.clear(Color::Black);

		window.draw(background);
		for (auto i = actors.begin(); i != actors.end();)
		{
			Actor* actor = *i;
			if (!actor->life)
			{
				i = actors.erase(i);
				delete actor;
			} else {
				actor->draw(window);
				i++;
			}
		}
		window.display();
	}
GARBAGE://это временно)
	for (auto i = actors.begin(); i != actors.end();)
	{
		Actor* actor = *i;
		i = actors.erase(i);
		delete actor;
	}
}