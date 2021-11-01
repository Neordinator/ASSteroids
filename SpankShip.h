#pragma once

#include "Actor.h"

class SpankShip : public Actor
{
public:
	bool thrust = false;

	SpankShip(Texture&);

	void turnLeft();
	void turnRight();
	void update();
	void draw(RenderWindow& window);
	Sprite& getSprite();
	float getAngle();

private:
	int maxSpeed;
};