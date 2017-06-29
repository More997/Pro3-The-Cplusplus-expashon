#include "Creditos.h"



Creditos::Creditos()
{
}


Creditos::~Creditos()
{
}

bool Creditos::Run(RenderWindow & wndw, Event & evento)
{
	wndw.clear(Color::Yellow);
	music.loadFromFile("Creditos.wav");
	sound.setBuffer(music);
	sound.setLoop(true);
	sound.play();
	wndw.display();
	while (!(Keyboard::isKeyPressed(Keyboard::Escape))) {
		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
			{
				wndw.close();
				return true;
			}
		}
	}
	sound.stop();
	return false;
}
