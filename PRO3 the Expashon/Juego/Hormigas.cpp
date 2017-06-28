#include "Hormigas.h"



Hormigas::Hormigas(float WSizeX, float WSizeY) : Enemigos(WSizeX, WSizeY)
{
	getTexture().loadFromFile("Enemigo.png");
	getSprite().setTexture(getTexture());
}

void Hormigas::Movimiento(float WSizeX, float WSizeY, Time frameStabilizer)
{
	v1 = numRand(4);
	switch (v1) {
	case 0:
		setX(getX() + 200 * frameStabilizer.asSeconds());
		break;
	case 1:
		setX(getX() - 200 * frameStabilizer.asSeconds());
		break;
	case 2:
		setY(getY() + 200 * frameStabilizer.asSeconds());
		break;
	case 3:
		setY(getY() - 200 * frameStabilizer.asSeconds());
		break;
	default:
		break;
	}
}


Hormigas::~Hormigas()
{
}
