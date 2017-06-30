#include "Enemigos.h"



Enemigos::Enemigos():
x(0),
y(0)
{
	x = rand()% (0-600);
	y = rand()% (0-600);
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


