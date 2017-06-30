#ifndef ARANITAS_H
#define ARANITAS_H
#pragma once
#include "Enemigos.h"
#include "SFML\Graphics.hpp"
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
