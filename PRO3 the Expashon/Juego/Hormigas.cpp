#include "Hormigas.h"



Hormigas::Hormigas()
{
	getTexture().loadFromFile("Enemigo.png");
	getIntRect().contains(20, 20);	
	getSprite().setTexture(getTexture());
	getSprite().setTextureRect(IntRect(0, 0, 20, 20));

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
