#include "Aranitas.h"



Aranitas::Aranitas() : Enemigos()

{
	v1 = 0;
	texture.loadFromFile("Enemigos.png");
	sprite.setTexture(texture);
}

void Aranitas::Movimiento(float WSizeX, float WSizeY, Time frameStabilizer)
{
	v1 = rand()%(0-4);
	switch (v1) {
	case 0:
		setX((getX() + (200 * frameStabilizer.asMilliseconds())));
		break;
	case 1:
		setX((getX() - (200 * frameStabilizer.asMilliseconds())));
		break;
	case 2:
		setY((getY() + (200 * frameStabilizer.asMilliseconds())));
		break;
	case 3:
		setY((getY() - (200 * frameStabilizer.asMilliseconds())));
		break;
	default:
		break;
	}
	sprite.setPosition(getX(), getY());

}


Aranitas::~Aranitas()
{
}

Sprite & Aranitas::getSprite()
{
	return sprite;
}

void Aranitas::Draw(RenderWindow & wndw)
{
	wndw.draw(sprite);
}

void Aranitas::setSprite(Sprite _sprite)
{
	sprite = _sprite;
}

Texture Aranitas::getTexture()
{
	return texture;
}
