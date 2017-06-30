#ifndef ENEMIGO_H
#define ENEMIGO_H
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemigos
{
private:
	float x;
	float y;
	Texture texture;
	Sprite sprite;
public:
	Enemigos();
	~Enemigos();
	float getX();
	float getY();
	void setX(float _x);
	void setY(float _y);
	
};
#endif // !ENEMIGO_H
