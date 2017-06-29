#include "Enemigos.h"



Enemigos::Enemigos(float WSizeX, float WSizeY)
{
	x = numRand(WSizeX);
	y = numRand(WSizeY);
}


Enemigos::~Enemigos()
{
}

float Enemigos::getX()
{
	return x;
}

float Enemigos::getY()
{
	return y;
}

void Enemigos::setX(float _x)
{
	x = _x;
}

void Enemigos::setY(float _y)
{
	y = _y;
}

Sprite& Enemigos::getSprite()
{
	return sprite;
}

void Enemigos::setSprite(Sprite _sprite)
{
	sprite = _sprite;
}

Texture Enemigos::getTexture()
{
	return texture;
}

int Enemigos::numRand(int pos)
{
	srand(time(NULL));
	num = rand() % pos;
	return num;
}
