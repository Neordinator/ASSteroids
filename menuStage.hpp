#pragma once

#include <time.h>
#include <SFML/Graphics.hpp>

using namespace sf;

int playMenuStage(RenderWindow& window)
{
	srand(time(0));
	int screenWidthCenter = window.getDefaultView().getCenter().x;
	int screenHeightCenter = window.getDefaultView().getCenter().y;
	Clock clock;
	unsigned int time = 0;
	Font font;	//переменная шрифта
	font.loadFromFile("src/fonts/CyrilicOld.ttf");	//переменной шрифта передаём файл шрифта

	Text title(L"Не угоди в ASSteroid !!!", font, 30);
	title.setOutlineColor(Color::White);
	title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	title.setPosition(50, screenHeightCenter);

	Text textStart(L"1 - Начать игру", font, 20);
	textStart.setOutlineColor(Color::White);
	textStart.setStyle(sf::Text::Bold | sf::Text::Underlined);
	textStart.setPosition(50, screenHeightCenter + 100);

	Text textEscape(L"0 - Выйти", font, 20);
	textEscape.setOutlineColor(Color::White);
	textEscape.setStyle(sf::Text::Bold | sf::Text::Underlined);
	textEscape.setPosition(50, screenHeightCenter + 200);
	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMilliseconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			return 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num0))
		{
			return 0;
		}

		window.clear(Color::Black);

		window.draw(title);
		window.draw(textStart);
		window.draw(textEscape);

		window.display();
	}
	return 0;
}