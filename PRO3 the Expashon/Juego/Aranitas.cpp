#include "Aranitas.h"



Aranitas::Aranitas() : Enemigos()

{
	//v1 = 0;
	texture.loadFromFile("Assets/Enemigos.png");
	sprite.setTexture(texture);
}

/*void Aranitas::Movimiento(float WSizeX, float WSizeY, Time frameStabilizer)
{
	v1 = rand()%(0-4);
	switch (v1) {
	case 0:
		getSprite().move((frameStabilizer.asSeconds() * 200), 0);
		//	setX((getX() + (200 * frameStabilizer.asSeconds())));
		break;
	case 1:
		getSprite().move(-(frameStabilizer.asSeconds() * 200), 0);
		//setX((getX() - (200 * frameStabilizer.asSeconds())));
		break;
	case 2:
		getSprite().move(0, -(frameStabilizer.asSeconds() * 200));
		//setY((getY() + (200 * frameStabilizer.asSeconds())));
		break;
	case 3:
		getSprite().move(0, -(frameStabilizer.asSeconds() * 200));
		//setY((getY() - (200 * frameStabilizer.asSeconds())));
		break;
	default:
		break;
	}
	sprite.setPosition(getX(), getY());

}
*/

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
