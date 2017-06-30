#ifndef JUEGO_H
#define JUEGO_H
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Aranitas.h"
#include "Arania.h"
#include "Monedas.h"
#include "Weather.h"
#include <string>
#include <list>
using namespace std;
using namespace sf;
#define cantE 4
class Juego
{
private:
	Personaje pj;
	Clock clock;
	bool alive;
	Texture texture;
	Sprite sprite;
	SoundBuffer music;
	Sound sound;
	int puntaje;
	
	list<Monedas*>pickUpList;
	list<Monedas*>::iterator pickUpIterB = pickUpList.begin();
	list<Monedas*>::iterator pickUpIterF = pickUpList.end();
	list<Monedas*>::iterator pickUpIterMove;

	list<Aranitas*>enemigosList;
	list<Aranitas*>::iterator iterB = enemigosList.begin();
	list<Aranitas*>::iterator iterF = enemigosList.end();
	list<Aranitas*>::iterator iterMove;

	Texture texGO;
	Sprite spriteGO;
	Font font;
	Text puntajeTex;
	string puntos;
	int puntosArania;
public:
	Juego();
	~Juego();
	bool Play(RenderWindow &wndw, Event &evento, float WSizeX, float WSizeY, int climan);
};
#endif

