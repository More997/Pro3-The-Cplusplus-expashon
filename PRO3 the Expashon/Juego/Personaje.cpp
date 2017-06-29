#include "Personaje.h"



Personaje::Personaje()
:
X(400),
Y(300),
vivo(true),
texture()
{
	texture.loadFromFile("PJ.png");
	sprite.setTexture(texture);
}

void Personaje::Movimiento(float WSizeX, float WSizeY, Time frameStabilizer)
{
	if (Keyboard::isKeyPressed(Keyboard::Up)&& Y > 0)
	{
		Y -= 200 * frameStabilizer.asSeconds();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) && Y < WSizeY-40)
	{
		Y += 200 * frameStabilizer.asSeconds();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && X < WSizeX-40)
	{
		X += 200 * frameStabilizer.asSeconds();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) && X > 0)
	{
		X -= 200 * frameStabilizer.asSeconds();
	}
	sprite.setPosition(X, Y);
}
float Personaje::getX()
{
	return X;
}

float Personaje::getY()
{
	return Y;
}

bool Personaje::getVivo()
{
	return vivo;
}

void Personaje::setVivo(bool resp)
{
	if (resp == false) 
	{
		music.loadFromFile("Death.ogg");
		sound.setBuffer(music);
		sound.setLoop(false);
		sound.play();
	}
	vivo = resp;
}

Sprite Personaje::getSprite()
{
	return sprite;
}

void Personaje::setSprite(Sprite _Sprite)
{
	sprite = _Sprite;
}


void Personaje::setX(float _X)
{
	X = _X;
}

void Personaje::setY(float _Y)
{
	Y = _Y;
}


Personaje::~Personaje()
{
}
