#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{	
	RenderWindow wndws(VideoMode(800, 600), "Pro3 C++", Style::Close||Style::Titlebar);
	while (wndws.isOpen())
	{
		Event evento;
		while (wndws.pollEvent(evento)) 
		{
			if (evento.type == evento.Closed)
				wndws.close();
		}
	}
	return 0;
}