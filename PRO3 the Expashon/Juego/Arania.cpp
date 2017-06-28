#include "Arania.h"



Arania::Arania(float WSizeX, float WSizeY):Enemigos(WSizeX, WSizeY)
{
	activo = false;
	getTexture().loadFromFile("Arania.png");
	getSprite().setTexture(getTexture());
}


Arania::~Arania()
{
}

void Arania::setX(float _X)
{
	x = _X;
}

float Arania::getX()
{
	return x;
}

void Arania::setY(float _Y)
{
	y = _Y;
}

float Arania::getY()
{
	return y;
}

void Arania::Movimiento(float xPJ, float yPJ, Time frameStabilizer)
{
	if (xPJ > x)
		x += 200 * frameStabilizer.asSeconds();
	else if (xPJ < x)
		x -= 200 * frameStabilizer.asSeconds();
	if (yPJ > y)
		y += 200 * frameStabilizer.asSeconds();
	else if (yPJ < y)
		y -= 200 * frameStabilizer.asSeconds();
}

void Arania::setActivo(bool resp)
{
	activo = resp;
}

bool Arania::getActivo()
{
	return activo;
}
