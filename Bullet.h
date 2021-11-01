#pragma once

#include "Actor.h"

class Bullet : public Actor
{
public:
	Bullet(Texture&, unsigned int, unsigned int, Sprite&, float);

	void rotate();
	void update();
	void draw(RenderWindow& window);
private:
	CircleShape* circle;
	float rotationSpeed, destX, destY;
	//int radius;

	void spawnPlace(Sprite&);
};