#ifndef ARANIA_H
#define ARANIA_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Personaje.h"
class Arania 
{
private:
	float x;
	float y;
	Texture texture;
	Sprite sprite;
	SoundBuffer music;
	Sound sound;
public:
	Arania();
	~Arania();
	void setX(float _X);
	float getX();
	void setY(float _Y);
	float getY();
	void Movimiento(Personaje &pj, Time frameStabilizer);
	void Activando();
	Sprite& getSprite();
	void setSprite(Sprite _sprite);
	Texture getTexture();
};
#endif
