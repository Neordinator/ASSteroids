#pragma once

#include "Actor.h"

class ASSteroid : public Actor
{
public:
	ASSteroid(Texture&, unsigned int, unsigned int, unsigned int, unsigned int,
		float, float, float, float);

	void rotate();
	void update();
	void draw(RenderWindow& window);

private:
	float rotationSpeed, destX, destY;

	void spawnBorder(unsigned int, unsigned int);
};