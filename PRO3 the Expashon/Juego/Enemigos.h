#ifndef ENEMIGO_H
#define ENEMIGO_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class Enemigos
{
private:
	int x;
	int y;
	Sprite sprite;
public:
	Enemigos();
	~Enemigos();
};
#endif // !ENEMIGO_H
