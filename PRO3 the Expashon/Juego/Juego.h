#ifndef JUEGO_H
#define JUEGO_H
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Hormigas.h"
#include "SFML\Network.hpp"
#include "../json.hpp"
#include <string>
#include <list>
using namespace std;
using namespace sf;
using namespace nlohmann;

class Juego
{
private:
	Event evento;
	Personaje pj;
	Http::Request Req;
	Http::Response Res;
	Http Dir;
	json data;
	SoundBuffer music;
	Sound sound;
	Clock clock;
	bool Endgame;
	int climan;
	bool findeljuego;
	Texture texture;
	Sprite sprite;
	list<Hormigas*>hormigas;
	list<Hormigas*>::iterator iterB = hormigas.begin();
	list<Hormigas*>::iterator iterF = hormigas.end();
	list<Hormigas*>::iterator iterMove;
	float WSizeY;
	float WSizeX;
public:
	Juego();
	~Juego();
	int Play(RenderWindow &wndw);
	int Menu(RenderWindow &wndw);
	int Creditos();
};
#endif

