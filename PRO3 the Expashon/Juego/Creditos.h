#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
class Creditos
{
private: 
	SoundBuffer music;
	Sound sound;
public:
	Creditos();
	~Creditos();
	bool Run(RenderWindow &wndw, Event &evento);
};

