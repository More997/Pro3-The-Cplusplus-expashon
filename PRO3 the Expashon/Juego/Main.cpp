#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
int main()
{
	RenderWindow wndw(VideoMode(800, 600), "Pro the C++ Expashon");
	CircleShape shape(25.f);
	RectangleShape cuadrado(Vector2f(30, 30));
	Clock clock;
	shape.setFillColor(Color::Red);
	cuadrado.setFillColor(Color::Green);
	int xC = 0;
	int yC = 0;
	int xS = 0;
	int yS = 0;
	Event evento;
	Time elapsed;
	clock.restart();
	Texture texture;
	texture.loadFromFile("ball.png");
	Sprite sprite;
	sprite.setTexture(texture);
	Music music;
	if (!music.openFromFile("bensound-goinghigher.mp3"))
		return -1; 
	music.play();
	while (wndw.isOpen())
	{
		 elapsed = clock.getElapsedTime();
		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				wndw.close();
		}
		
		if (elapsed.asSeconds() == 2.0f)
		{
			xC++;
			clock.restart();
		}
		if (evento.type == Event::KeyPressed)
		{
				if (evento.key.code == Keyboard::Up && yS != 0)
				{
					yS--;
				}
				else if (evento.key.code == Keyboard::Down && yS != 585)
				{
					yS++;
				}
				else if (evento.key.code == Keyboard::Right && xS != 785) 
				{
					xS++;
				}
				else if (evento.key.code == Keyboard::Left && xS != 0)
				{
					xS--;
				}
			}
		
		shape.setPosition(xC, yC);
		cuadrado.setPosition(xS, yS);
		wndw.clear();
		wndw.clear(Color::White);
		wndw.draw(shape);
		wndw.draw(cuadrado);
		wndw.draw(sprite);
		wndw.display();
		
		
	}
	return 0;
}

	