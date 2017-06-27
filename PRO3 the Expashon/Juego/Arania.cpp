#include "Arania.h"



Arania::Arania():
	activo(false)
{
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
	else
		x -= 200 * frameStabilizer.asSeconds();
	if (yPJ > y)
		y += 200 * frameStabilizer.asSeconds();
	else
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
