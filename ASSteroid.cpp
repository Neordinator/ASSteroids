#include "ASSteroid.h"

ASSteroid::ASSteroid(Texture& texture, unsigned int row, unsigned int column,
	unsigned int posX, unsigned int posY, float newAngle, float newMvSp, float newRtSp,
	float newScale)
{
	life = true;
	this->sprite = Sprite(texture, IntRect(0 + row * 128 , 0 + column * 128, 128, 128));//0 ~ 7
	if (newScale > 0.6)
	{
		this->name = "big";
		this->spawnBorder(posX, posY);
	}
	else {
		this->name = "small";
		this->x = posX;
		this->y = posY;
	}
	this->movementSpeed = newMvSp; // 0 ~ 10
	this->rotationSpeed = newRtSp; // -15 ~ 15
	this->angle = newAngle;
	this->destX = cos(angle * DEGTORAD);
	this->destY = sin(angle * DEGTORAD);
	this->dx = this->destX * movementSpeed;
	this->dy = this->destY * movementSpeed;
	this->sprite.setPosition(this->x, this->y);
	this->sprite.setOrigin(this->sprite.getTextureRect().width / 2, this->sprite.getTextureRect().height / 2);
	this->radius = 50.0 * newScale;
	this->sprite.setScale(newScale, newScale);
}

void ASSteroid::draw(RenderWindow& window)
{
	window.draw(this->sprite);
}

void ASSteroid::rotate()
{
	this->angle += this->rotationSpeed;
	this->sprite.setRotation(angle);
}

void ASSteroid::update()
{
	this->x += this->dx;
	this->y += this->dy;
	this->rotate();
	this->torusImitation();
	this->sprite.setPosition(this->x, this->y);
}

void ASSteroid::spawnBorder(unsigned int generatedX, unsigned int generatedY)
{
	if (generatedX > W * 0.15 && generatedX < W * 0.85)
	{
		if (generatedY > H * 0.15 && generatedY < H * 0.85)
		{
			if (generatedX >= W / 2)
			{
				this->x = W;
			} else {
				this->x = 0;
			}
			this->y = generatedY;
			return;
		} else {
			this->x = generatedX;
			this->y = generatedY;
			return;
		}
	}
	this->x = generatedX;
	this->y = generatedY;
}