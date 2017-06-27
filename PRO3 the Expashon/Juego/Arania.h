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
	Arania();
	~Arania();
	void setX(float _X);
	float getX();
	void setY(float _Y);
	float getY();
	void movimiento(float xPJ, float yPJ);
	void setActivo(bool resp);
	bool getActivo();
};

