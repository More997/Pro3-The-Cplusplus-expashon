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
	void Movimiento(float WSizeX, float WSizeY, Time frameStabilizer);
	~Hormigas();
};

