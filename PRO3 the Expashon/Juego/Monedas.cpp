#include "Monedas.h"



Monedas::Monedas() :
	puntos(10)
{
	texture.loadFromFile("Puntos.png");
	sprite.setTexture(texture);
	x = rand() % (0 - 800);
	y = rand() % (0 - 600);
}


Monedas::~Monedas()
{
}

float Monedas::getX()
{
	return x;
}

float Monedas::getY()
{
	return y;
}

void Monedas::setX(float _x)
{
	x = _x;
}

void Monedas::setY(float _y)
{
	y = _y;
}

Sprite Monedas::getSprite()
{
	return sprite;
}

void Monedas::setSprite(Sprite _sprite)
{
	sprite = _sprite;
}

Texture Monedas::getTexture()
{
	return texture;
}

void Monedas::Colision(int & puntaje)
{
	x = rand() % (0 - 800);
	y = rand() % (0 - 600);
	puntaje += puntos;

}


