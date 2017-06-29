#include "Juego.h"



Juego::Juego()
	:
	alive(false),
	texture()
{
	texture.loadFromFile("Tela.png");
	sprite.setTexture(texture);
}



Juego::~Juego()
{
	
}

bool Juego::Play(RenderWindow &wndw,Event &evento, float WSizeX, float WSizeY, int climan)
{
	arania.Activando(false);
	puntaje = 0;
	music.loadFromFile("Music.ogg");
	sound.setBuffer(music);
	sound.play();
	sound.setLoop(true);
	for (int i = 0; i < cantE; i++) {
		
	}
	while (wndw.isOpen() || alive != false)
	{
		
		Time frameStabilizer = clock.restart();
		while (wndw.pollEvent(evento))
		{			
			if (evento.type == Event::Closed) 
			{
				wndw.close();
				return true;
			}
		}
		if (arania.getActivo() == true)
			arania.Movimiento(pj, frameStabilizer);
		pj.Movimiento(WSizeX, WSizeY, frameStabilizer);
		wndw.clear();
		switch (climan)
		{
		case 30:
		case 26:
			wndw.clear(Color::Color(100, 0, 255, 0));
			break;
		case 31:
		case 32:
			wndw.clear(Color::Cyan);
			break;
		case 10:
			wndw.clear(Color::Magenta);
		default:
			wndw.clear(Color::Green);
			break;
		}
		wndw.draw(sprite);
		wndw.draw(pj.getSprite());
		if (arania.getActivo() == true)
		{
			wndw.draw(arania.getSprite());
			if (arania.getSprite().getGlobalBounds().intersects(pj.getSprite().getGlobalBounds())) 
			{
				pj.setVivo(false);
			}
		}
		wndw.display();
		alive = pj.getVivo();
	}
	sound.stop();
}

int Juego::Creditos()
{
	return 0;
}