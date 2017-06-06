#ifndef PERSONAJE_H
#define PERSONAJE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class Personaje
{
private:
	float X;
	float Y;
	bool vivo;
	Texture texture;
	IntRect rectSourceSprite;
	Sprite sprite;

public:
	Personaje();
	void Movimiento(Event evento);
	void Animacion();
	float getX();
	float getY();
	Sprite getSprite();
	IntRect getIntRect();
	void setX(float _X);
	void setY(float _Y);
	~Personaje();
};
#endif
