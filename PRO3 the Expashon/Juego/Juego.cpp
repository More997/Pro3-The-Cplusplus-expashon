#include "Juego.h"



Juego::Juego()
	:
	alive(true),
	texture(),
	texGO(),
	puntosArania(100)
{
	texture.loadFromFile("Tela.png");
	sprite.setTexture(texture);
	texGO.loadFromFile("GO.png");
	spriteGO.setTexture(texGO);
	font.loadFromFile("Crimson-Bold.ttf");
	puntajeTex.setFont(font);
	puntajeTex.setCharacterSize(15);
	
}



Juego::~Juego()
{
}

bool Juego::Play(RenderWindow &wndw,Event &evento, float WSizeX, float WSizeY, int climan, int &highScore, bool &supHS)
{
	
	//Para cuando vuelvo a jugar el juego no se quede los datos de la jugada anterior
	Arania* arania = new Arania();
	arania->Activando(false);
	pj.setVivo(true);
	alive = true;
	puntaje = 0;
	

	music.loadFromFile("Music.ogg");
	sound.setBuffer(music);
	sound.play();
	sound.setLoop(true);
	for (int i = 0; i < cantE; i++) {
		Aranitas* enemigo = new Aranitas();
		enemigosList.push_front(enemigo);
	}
	iterB = enemigosList.begin();
	iterF = enemigosList.end();
	iterMove = iterB;

	for (int i = 0; i < cantE; i++) {
		Monedas* coins = new Monedas();
		pickUpList.push_front(coins);
	}
	pickUpIterB = pickUpList.begin();
	pickUpIterF = pickUpList.end();
	pickUpIterMove = pickUpIterB;

	while (alive != false)
	{
		
		Time frameStabilizer = clock.restart();
		while (wndw.pollEvent(evento))
		{			
			if (evento.type == Event::Closed) 
			{
				while (enemigosList.empty() == false)
				{
					Aranitas* Del = enemigosList.back();
					enemigosList.pop_back();
					delete Del;
				}
				while (pickUpList.empty() == false)
				{
					Monedas* Del2 =	pickUpList.back();
					pickUpList.pop_back();
					delete Del2;
				}
				delete arania;
				wndw.close();
				return true;
			}
		}
		if (arania->getActivo() == true)
			arania->Movimiento(pj, frameStabilizer);
		for (iterMove = iterB; iterMove != iterF; iterMove++)
		{
			(*iterMove)->Movimiento(WSizeX,WSizeY,frameStabilizer);
			
		}
		iterB = enemigosList.begin();
		iterF = enemigosList.end();
		iterMove = iterB;
		pj.Movimiento(WSizeX, WSizeY, frameStabilizer);
		wndw.clear();
		switch (climan)
		{
		case Cloudy:
		case Cloudy2:
			wndw.clear(Color::Color(100, 0, 255, 0));
			puntajeTex.setFillColor(Color::Yellow);
			break;
		case Sunny:
		case Sunny2:
			wndw.clear(Color::Cyan);
			puntajeTex.setFillColor(Color::Black);
			break;
		case Rainy:
			wndw.clear(Color::Magenta);
			puntajeTex.setFillColor(Color::Blue);
		default:
			wndw.clear(Color::Green);
			puntajeTex.setFillColor(Color::Red);
			break;
		}
		wndw.draw(sprite);
		wndw.draw(pj.getSprite());
		if (arania->getActivo() == true)
		{
			wndw.draw(arania->getSprite());
			if (arania->getSprite().getGlobalBounds().intersects(pj.getSprite().getGlobalBounds())) 
			{
				pj.setVivo(false);
			}
		}

		for (iterMove = iterB; iterMove != iterF; iterMove++)
		{
			if ((*iterMove)->getSprite().getGlobalBounds().intersects(pj.getSprite().getGlobalBounds()))
				pj.setVivo(false);
		}
		iterB = enemigosList.begin();
		iterF = enemigosList.end();
		iterMove = iterB;

		for (pickUpIterMove = pickUpIterB; pickUpIterMove != pickUpIterF; pickUpIterMove++)
		{
			if ((*pickUpIterMove)->getSprite().getGlobalBounds().intersects(pj.getSprite().getGlobalBounds()))
				(*pickUpIterMove)->Colision(puntaje);
		}
		pickUpIterB = pickUpList.begin();
		pickUpIterF = pickUpList.end();
		pickUpIterMove = pickUpIterB;

		for (iterMove = iterB; iterMove != iterF; iterMove++)
		{
			(*iterMove)->Draw(wndw);

		}
		iterB = enemigosList.begin();
		iterF = enemigosList.end();
		iterMove = iterB;
		for (pickUpIterMove = pickUpIterB; pickUpIterMove != pickUpIterF; pickUpIterMove++)
		{
			wndw.draw((*pickUpIterMove)->getSprite());
		}
		pickUpIterB = pickUpList.begin();
		pickUpIterF = pickUpList.end();
		pickUpIterMove = pickUpIterB;
		puntajeTex.setPosition(0, 0);
		puntajeTex.setString(L"Puntos:");
		wndw.draw(puntajeTex);
		puntajeTex.setPosition(55, 0);
		puntos = to_string(puntaje);
		puntajeTex.setString(puntos);
		wndw.draw(puntajeTex);
		wndw.display();
		alive = pj.getVivo();
		if (puntaje == puntosArania)
		{
			arania->Activando(true);
		}
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
				while (enemigosList.empty() == false)
				{
					Aranitas* Del = enemigosList.back();
					enemigosList.pop_back();
					delete Del;
				}
				while (pickUpList.empty() == false)
				{
					Monedas* Del2 = pickUpList.back();
					pickUpList.pop_back();
					delete Del2;
				}
				delete arania;
				wndw.close();
				return true;
			}
		}
	}
	while (enemigosList.empty() == false)
	{
		Aranitas* Del = enemigosList.back();
		enemigosList.pop_back();
		delete Del;
	}
	delete arania;
	while (pickUpList.empty() == false)
	{
		Monedas* Del2 = pickUpList.back();
		pickUpList.pop_back();
		delete Del2;
	}
	if (puntaje > highScore)
	{
		highScore = puntaje;
		supHS = true;
	}
	return false;
	
}

