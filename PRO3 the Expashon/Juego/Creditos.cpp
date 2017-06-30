#include "Creditos.h"



Creditos::Creditos():
	texture()
{
	texture.loadFromFile("Assets/Bichito.png");
	sprite.setTexture(texture);
	font.loadFromFile("Assets/Crimson-Bold.ttf");
	credits.setFont(font);
	credits.setFillColor(Color::Black);
}


Creditos::~Creditos()
{
}

bool Creditos::Run(RenderWindow & wndw, Event & evento)
{
	music.loadFromFile("Assets/Creditos.wav");
	sound.setBuffer(music);
	sound.setLoop(true);
	sound.play();
	
	while (!(Keyboard::isKeyPressed(Keyboard::Escape))) {
		wndw.clear(Color::Color(0,51,102));
		credits.setCharacterSize(20);
	
		credits.setPosition(200, 10);
		credits.setString(L"Programmer: Morena Montero");
		wndw.draw(credits);

		credits.setPosition(200, 90);
		credits.setString(L"Graphics by: Morena Montero");
		wndw.draw(credits);

		credits.setPosition(200, 50);
		credits.setString(L"Used Libraries : SFML 2.4.2 & JSON");
		wndw.draw(credits);

		credits.setPosition(200, 130);
		credits.setString(L"Graphics made in: http://www.piskelapp.com/");
		wndw.draw(credits);

		credits.setPosition(200, 170);
		credits.setString(L"Sounds By: SAMAMM101 & Cyclon8472");
		wndw.draw(credits);

		credits.setPosition(300, 200);
		credits.setString(L"in https://freesound.org/");
		wndw.draw(credits);

		credits.setPosition(200, 250);
		credits.setString(L"Music: 8-Bit Detective-Puzzle Theme1-Retro1 140 ");
		wndw.draw(credits);

		credits.setPosition(300, 280);
		credits.setString(L"By https://www.dl-sounds.com/");
		wndw.draw(credits);

		credits.setPosition(200, 320);
		credits.setString(L"Font: Crimson-Bold by Sebastian Kosch");
		wndw.draw(credits);

		credits.setPosition(300, 500);
		credits.setString(L"Thank you for Playing");
		wndw.draw(credits);

		credits.setCharacterSize(15);
		credits.setPosition(0, 0);
		credits.setString(L"Press ESC to go back");
		wndw.draw(credits);

		sprite.setPosition(550, 440);
		wndw.draw(sprite);
		
		wndw.display();
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
