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
	Hormigas hrmgs[5];
	Enemigos bombas[10];
	bool byemenu;
	int climan;
	bool findeljuego;
	Texture texture;
	Sprite sprite;
public:
	Juego();
	~Juego();
	int Play();
	int Menu();
	int Creditos();
};
#endif

