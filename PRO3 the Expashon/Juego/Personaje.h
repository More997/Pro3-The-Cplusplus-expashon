#ifndef PERSONAJE_H
#define PERSONAJE_H
#pragma once
#include "Juego.h"
class Personaje
{
private:
	float X;
	float Y;
	bool vivo;
public:
	Personaje();
	void Movimiento(Event evento);
	void Animacion();
	~Personaje();
};
#endif
