#ifndef JUEGO_H
#define JUEGO_H
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Personaje.h"
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
	bool byemenu = false;
	bool findeljuego = false;
public:
	Juego();
	~Juego();
	int Play();
	int Menu();
	int Creditos();
};
#endif

