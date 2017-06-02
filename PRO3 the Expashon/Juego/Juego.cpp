#include "Juego.h"



Juego::Juego()
{
	
}


Juego::~Juego()
{
}

int Juego::Play()
{
	RenderWindow wndw(VideoMode(800, 600), "Pro the C++ Expashon");
	CircleShape shape(25.f);
	RectangleShape cuadrado(Vector2f(30, 30));
	Clock clock;
	shape.setFillColor(Color::Red);
	cuadrado.setFillColor(Color::Green);
	float xC = 0;
	float yC = 0;
	float xPJ = 25;
	float yPJ = 25;
	Event evento;
	//Time elapsed;
	//clock.restart();
	Texture texture;
	texture.loadFromFile("PJ.png");
	IntRect rectSourceSprite(40, 0, 40, 40);
	Sprite sprite(texture, IntRect(0, 0, 40, 40));
	SoundBuffer music;
	if (!music.loadFromFile("bensound-goinghigher.ogg"))
	{
		return -1;
	}
	Sound sound;
	sound.setBuffer(music);
	sound.setLoop(true);
	sound.play();
	while (wndw.isOpen())
	{

		//elapsed = clock.getElapsedTime();
		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				wndw.close();
		}

		//if (elapsed.asSeconds() == 2.0f)
		//{
		xC += 0.1f;
		//clock.restart();
		//}
		
		if (cuadrado.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
			xPJ = 50;
			yPJ = 50;
		}
		sprite.setTextureRect(rectSourceSprite);
		shape.setPosition(xC, yC);
		sprite.setPosition(xPJ, yPJ);
		wndw.clear();
		wndw.clear(Color::White);
		wndw.draw(shape);
		wndw.draw(cuadrado);
		wndw.draw(sprite);
		wndw.display();
	}
	return 0;
}