#include <iostream>
#include <vld.h>
#include "Juego.h"


int main()
{
	float WSizeY=600;
	float WSizeX = 700;
	RenderWindow wndw(VideoMode(WSizeX, WSizeY), "Pro the C++ Expashon");
	Juego juego;
	juego.Menu(wndw);
	return 0;
}

	