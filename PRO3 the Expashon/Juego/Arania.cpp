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

void Arania::movimiento(float xPJ, float yPJ)
{
	if (xPJ > x)
		x += 0.1f;
	else
		x -= 0.1f;
	if (yPJ > y)
		y += 0.1f;
	else
		y -= 0.1f;
}

void Arania::setActivo(bool resp)
{
	activo = resp;
}

bool Arania::getActivo()
{
	return activo;
}
