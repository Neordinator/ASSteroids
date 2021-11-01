#pragma once

#include <SFML/Graphics.hpp>

#include "const.hpp"

using namespace sf;

class Actor
{
public:
	std::string name;
	bool life;

	Actor();
	virtual ~Actor();

	virtual void update();
	virtual void draw(RenderWindow& window);
	float getRadius();
	bool isCollide(Actor*);
	int getX();
	int getY();

protected:
	Sprite sprite;
	float angle, x, y, dx, dy, movementSpeed, radius;

	void torusImitation();
    
};