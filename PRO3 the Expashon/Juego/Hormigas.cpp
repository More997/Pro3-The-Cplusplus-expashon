#include "Hormigas.h"



Hormigas::Hormigas()
{
	getTexture().loadFromFile("Enemigo.png");
	getIntRect().contains(20, 20);	
	getSprite().setTexture(getTexture());
	getSprite().setTextureRect(IntRect(0, 0, 20, 20));

}

void Hormigas::Movimiento()
{
	v1 = numRand(4);
	switch (v1) {
	case 0:
		setX(getX() + 0.1f);
		break;
	case 1:
		setX(getX() - 0.1f);
		break;
	case 2:
		setY(getY() + 0.1f);
		break;
	case 3:
		setY(getY() - 0.1f);
		break;
	default:
		break;
	}
}


Hormigas::~Hormigas()
{
}
