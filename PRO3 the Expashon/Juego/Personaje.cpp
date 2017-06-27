#include "Personaje.h"



Personaje::Personaje()
:
X(0),
Y(0),
vivo(true),
texture()
{
	texture.loadFromFile("PJ.png");
	sprite.setTexture(texture);
}

void Personaje::Movimiento()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		Y -= 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Y += 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		X += 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		X -= 0.1f;
	}
	sprite.setPosition(X, Y);
}
float Personaje::getX()
{
	return X;
}

float Personaje::getY()
{
	return Y;
}

Sprite Personaje::getSprite()
{
	return sprite;
}

void Personaje::setSprite(Sprite _Sprite)
{
	sprite = _Sprite;
}


void Personaje::setX(float _X)
{
	X = _X;
}

void Personaje::setY(float _Y)
{
	Y = _Y;
}


Personaje::~Personaje()
{
}
