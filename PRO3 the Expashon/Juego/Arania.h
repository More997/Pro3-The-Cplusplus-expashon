#ifndef ARANIA_H
#define ARANIA_H
#pragma once
#include "Enemigos.h"
class Arania :
	public Enemigos
{
private:
	float x;
	float y;
	bool activo;
public:
	Arania(float WSizeX, float WSizeY);
	~Arania();
	void setX(float _X);
	float getX();
	void setY(float _Y);
	float getY();
	void Movimiento(float xPJ, float yPJ, Time frameStabilizer);
	void setActivo(bool resp);
	bool getActivo();
};
#endif
