#include "Arania.h"



Arania::Arania() : 
	x (-1000),
	y (-1000)
{
	texture.loadFromFile("Assets/Arania.png");
	sprite.setTexture(texture);
}


Arania::~Arania()
{
}

void Arania::setX(float _X)
{
	x = _X;
}

float Arania::getX()
{
	return x;
}

void Arania::setY(float _Y)
{
	y = _Y;
}

float Arania::getY()
{
	return y;
}

void Arania::Movimiento(Personaje &pj, Time frameStabilizer)
{
	
	if (pj.getX() > x)
		x += 50 * frameStabilizer.asSeconds();
	else if (pj.getX() < x)
		x -= 50 * frameStabilizer.asSeconds();
	if (pj.getY()> y)
		y += 50 * frameStabilizer.asSeconds();
	else if (pj.getY() < y)
		y -= 50 * frameStabilizer.asSeconds();
	sprite.setPosition(x, y);
}

void Arania::Activando()
{
	music.loadFromFile("Assets/Arania.wav");
	sound.setBuffer(music);
	sound.play();
	sound.setLoop(false);
}




Sprite & Arania::getSprite()
{
	return sprite;
}

void Arania::setSprite(Sprite _sprite)
{
	sprite = _sprite;
}

Texture Arania::getTexture()
{
	return texture;
}


