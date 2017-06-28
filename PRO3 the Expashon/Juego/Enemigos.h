#ifndef ENEMIGO_H
#define ENEMIGO_H
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemigos
{
private:
	float x;
	int num;
	float y;
	Texture texture;
	Sprite sprite;
public:
	Enemigos(float WSizeX, float WSizeY);
	~Enemigos();
	float getX();
	float getY();
	void setX(float _x);
	void setY(float _y);
	Sprite& getSprite();
	void setSprite(Sprite _sprite);
	Texture getTexture();
	bool Colision(Sprite Jugador);
	int numRand(int pos); 

	
};
#endif // !ENEMIGO_H
