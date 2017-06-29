#ifndef ARANIA_H
#define ARANIA_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Personaje.h"
using namespace sf;
class Arania 
{
private:
	float x;
	float y;
	bool activo;
	Texture texture;
	Sprite sprite;

public:
	Arania();
	~Arania();
	void setX(float _X);
	float getX();
	void setY(float _Y);
	float getY();
	void Movimiento(Personaje &pj, Time frameStabilizer);
	void Activando(bool resp);
	bool getActivo();
	Sprite& getSprite();
	void setSprite(Sprite _sprite);
	Texture getTexture();
};
#endif
