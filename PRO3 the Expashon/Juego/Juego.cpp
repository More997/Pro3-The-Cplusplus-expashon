#include "Juego.h"



Juego::Juego()
	:
	alive(true),
	texture(),
	texGO()
{
	texture.loadFromFile("Tela.png");
	sprite.setTexture(texture);
	texGO.loadFromFile("GO.png");
	spriteGO.setTexture(texGO);
}



Juego::~Juego()
{
	
}

bool Juego::Play(RenderWindow &wndw,Event &evento, float WSizeX, float WSizeY, int climan)
{
	arania.Activando(true);
	pj.setVivo(true);
	alive = true;
	puntaje = 0;
	music.loadFromFile("Music.ogg");
	sound.setBuffer(music);
	sound.play();
	sound.setLoop(true);
	for (int i = 0; i < cantE; i++) {
		
	}
	while (alive != false)
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
		case Cloudy:
		case Cloudy2:
			wndw.clear(Color::Color(100, 0, 255, 0));
			break;
		case Sunny:
		case Sunny2:
			wndw.clear(Color::Cyan);
			break;
		case Rainy:
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
	wndw.clear();
	wndw.draw(spriteGO);
	wndw.display();
 	while (!(Keyboard::isKeyPressed(Keyboard::N))) 
	{
 		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
			{
				wndw.close();
				return true;
			}
		}
	}
	return false;
}

int Juego::Creditos()
{
	return 0;
}