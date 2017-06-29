#ifndef MENU_H
#define MENU_H
#pragma once
#include "SFML\Network.hpp"
#include "../json.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Juego.h"
using namespace std;
using namespace sf;
using namespace nlohmann;
class Menu
{
private:
	float WSizeY;
	float WSizeX;
	Event evento;
	Http::Request Req;
	Http::Response Res;
	Http Dir;
	json data;
	int climan;
	SoundBuffer music;
	Sound sound;
	Juego game;
	int cerrar;
	Texture texture;
	Sprite sprite;
public:
	Menu();
	~Menu();
	void Start();
};
#endif

