#include "Bullet.h"
Bullet::Bullet(Texture& texture, unsigned int row, unsigned int column,
	Sprite& ship, float newAngle)
{
	life = true;
	this->sprite = Sprite(texture, IntRect(0 + row * 182, 206 + column * 206, 182, 206));//0 ~ 3, 0 ~ 1
	//this->circle = new CircleShape(this->radius);
	this->angle = newAngle;
	this->spawnPlace(ship);
	this->name = "bullet";
	this->movementSpeed = 25; // 0 ~ 10
	this->destX = cos(angle * DEGTORAD);
	this->destY = sin(angle * DEGTORAD);
	this->dx = this->destX * movementSpeed;
	this->dy = this->destY * movementSpeed;
	this->sprite.setPosition(this->x, this->y);
	this->sprite.setOrigin(this->sprite.getTextureRect().width / 2, this->sprite.getTextureRect().height / 2);
	this->radius = 10.0;
	this->sprite.setScale(0.2, 0.2);
}

void Bullet::draw(RenderWindow& window)
{
	window.draw(this->sprite);
}

void Bullet::rotate()
{
	this->angle += this->rotationSpeed;
	this->sprite.setRotation(angle);
}

void Bullet::update()
{
	this->x += this->dx;
	this->y += this->dy;
	this->rotate();
	this->sprite.setPosition(this->x, this->y);
	if (x > W || x < 0 || y > H || y < 0)
	{
		this->life = 0;
	}
}

void Bullet::spawnPlace(Sprite& ship)
{
	this->x = ship.getPosition().x;
	this->y = ship.getPosition().y;
}