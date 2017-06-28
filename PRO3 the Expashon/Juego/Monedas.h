#ifndef MONEDAS_H
#define MONEDAS_H
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Monedas
{
private:
	float x;
	int num;
	float y;
	int puntos;
	Texture texture;
	Sprite sprite;
public:
	Monedas();
	~Monedas();
	float getX();
	float getY();
	void setX(float _x);
	void setY(float _y);
	Sprite getSprite();
	void setSprite(Sprite _sprite);
	Texture getTexture();
	void Colision(Sprite Jugador, int &puntaje);
	int numRand(int pos);
};
#endif

