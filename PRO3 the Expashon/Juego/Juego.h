#ifndef JUEGO_H
#define JUEGO_H
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Hormigas.h"
#include "Arania.h"
#include "SFML\Network.hpp"
#include "../json.hpp"
#include <string>
using namespace std;
using namespace sf;
using namespace nlohmann;
#define cantE 5
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
	float WSizeY;
	float WSizeX;
	int puntaje;
public:
	Juego();
	~Juego();
	int Play(/*RenderWindow &wndw*/);
	int Menu();
	int Creditos();
};
#endif

