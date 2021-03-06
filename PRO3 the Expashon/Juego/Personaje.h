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
	Sprite sprite;
	SoundBuffer music;
	Sound sound;
	float WidthS;
	float HeightS;
public:
	Personaje();
	void Movimiento(float WSizeX, float WSizeY, Time frameStabilizer);
	float getX();
	float getY();
	bool getVivo();
	void setVivo(bool resp); 
	Sprite getSprite();
	void setSprite(Sprite _Sprite);
	void setX(float _X);
	void setY(float _Y);
	~Personaje();
};
#endif
