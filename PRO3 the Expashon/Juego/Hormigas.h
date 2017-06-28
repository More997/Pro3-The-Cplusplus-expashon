#ifndef HORMIGAS_H
#define HORMIGAS_H
#pragma once
#include "Enemigos.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace sf;
class Hormigas :
	public Enemigos
{
	int v1;
public:
	Hormigas(); 
	Hormigas(float WSizeX, float WSizeY);
	void Movimiento(float WSizeX, float WSizeY, Time frameStabilizer);
	~Hormigas();
};
#endif 
