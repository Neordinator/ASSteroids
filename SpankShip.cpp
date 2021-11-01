#include "SpankShip.h"

SpankShip::SpankShip(Texture& texture)
{
	life = true;
	this->sprite = Sprite(texture, IntRect(2, 6, 108, 182));
	this->x = W / 2;
	this->y = H / 2;
	this->name = "player";
	this->movementSpeed = 0;
	this->maxSpeed = 15;
	this->dx = 0;
	this->dy = 0;
	this->angle = 270.0;
	this->sprite.setPosition(this->x, this->y);
	this->sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	this->radius = 30.0;
	this->sprite.setScale(0.35, 0.35);
}

Sprite& SpankShip::getSprite()
{
	return this->sprite;
}
float SpankShip::getAngle()
{
	return this->angle;
}
void SpankShip::turnLeft()
{
	this->angle -= 3;
	this->sprite.rotate(-3);
}

void SpankShip::turnRight()
{
	this->angle += 3;
	this->sprite.rotate(3);
}

void SpankShip::draw(RenderWindow& window)
{
	window.draw(this->sprite);
}

void SpankShip::update()
{
	if (thrust)
	{
		this->dx += cos(angle * DEGTORAD) * 0.2;
		this->dy += sin(angle * DEGTORAD) * 0.2;
	}
	else
	{
		this->dx *= 0.99;
		this->dy *= 0.99;
	}
	this->torusImitation();
	this->movementSpeed = sqrt(this->dx * this->dx + this->dy * this->dy);
	if (this->movementSpeed > this->maxSpeed)/*ограничение скорости*/
	{
		this->dx *= this->maxSpeed / this->movementSpeed;
		this->dy *= this->maxSpeed / this->movementSpeed;
	}
	this->y += this->dy;
	this->x += this->dx;
	this->sprite.setPosition(this->x, this->y);
}