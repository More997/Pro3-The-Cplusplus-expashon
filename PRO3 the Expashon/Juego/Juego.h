#ifndef JUEGO_H
#define JUEGO_H
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Hormigas.h"
#include "Arania.h"
#include "Monedas.h"
#include <string>
#include <list>
using namespace std;
using namespace sf;
#define cantE 5
class Juego
{
private:
	Personaje pj;
	Clock clock;
	bool Endgame;
	bool alive;
	Texture texture;
	Sprite sprite;
	SoundBuffer music;
	Sound sound;
	int puntaje;
	Arania arania;
	list<Hormigas*>enemigos;
	list<Enemigos*>bombas;
	list<Monedas*>Pickups;
public:
	Juego();
	~Juego();
	bool Play(RenderWindow &wndw, Event &evento, float WSizeX, float WSizeY, int climan);
	int Creditos();
};
#endif

