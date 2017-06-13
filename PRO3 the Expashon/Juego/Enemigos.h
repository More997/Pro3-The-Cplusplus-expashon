#ifndef ENEMIGO_H
#define ENEMIGO_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class Enemigos
{
private:
	float x;
	int num;
	float y;
	Texture texture;
	IntRect rectSourceSprite;
	Sprite sprite;
public:
	Enemigos();
	~Enemigos();
	float getX();
	float getY();
	void setX(float _x);
	void setY(float _y);
	Sprite getSprite();
	void setSprite(Sprite _sprite);
	Texture getTexture();
	IntRect getIntRect(); 
	bool Colision(Sprite Jugador);
	int numRand(int pos); 

	
};
#endif // !ENEMIGO_H
