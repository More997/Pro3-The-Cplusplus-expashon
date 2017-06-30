#ifndef ARANITAS_H
#define ARANITAS_H
#pragma once
#include "Enemigos.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace sf;
class Aranitas :
	public Enemigos
{
private:
//	int v1;
	Texture texture;
	Sprite sprite;
public:
	Aranitas(); 
	//void Movimiento(float WSizeX, float WSizeY, Time frameStabilizer);
	~Aranitas();
	Sprite& getSprite();
	void Draw(RenderWindow &wndw);
	void setSprite(Sprite _sprite);
	Texture getTexture();
};
#endif 
