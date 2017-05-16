#include <iostream>
#include <SFML/Graphics.hpp>
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
	clock.restart();
	Time tiempo;
	Event evento;
	while (wndw.isOpen())
	{
		
		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				wndw.close();
		}	
		if (tiempo.asMicroseconds() == 2) 
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
			else if (evento.key.code == Keyboard::Down && yS != 600)
			{
				yS++;
			}
			else if (evento.key.code == Keyboard::Right && xS != 800) 
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
		wndw.draw(shape);
		wndw.draw(cuadrado);
		wndw.display();
		
		
	}

	return 0;
}