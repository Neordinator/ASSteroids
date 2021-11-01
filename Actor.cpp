#include "Actor.h"

Actor::Actor()
{
	this->life = true;
}
Actor::~Actor() {};
void Actor::update() {};
void Actor::draw(RenderWindow& window) {};
int Actor::getX()
{
	return this->x;
}
int Actor::getY()
{
	return this->y;
}
float Actor::getRadius()
{
	return this->radius;
}
void Actor::torusImitation()
{
	if (this->x > W)
	{
		this->x = 0;
	}
	if (this->x < 0)
	{
		this->x = W;
	}
	if (this->y > H)
	{
		this->y = 0;
	}
	if (this->y < 0)
	{
		this->y = H;
	}
}
bool Actor::isCollide(Actor* other)
{
	/*return
	(this->x - other->x) * (this->x - other->x) + (this->y - other->y) * (this->y - other->y)
		< (other->radius + this->radius) * (other->radius + this->radius);*/
	return
		(other->x - this->x) * (other->x - this->x) + (other->y - this->y) * (other->y - this->y)
		< (this->radius + other->radius) * (this->radius + other->radius);
}