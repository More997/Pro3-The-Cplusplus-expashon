#include "Juego.h"



Juego::Juego()
:
byemenu(false),
findeljuego(false)
{
	
}


Juego::~Juego()
{
}

int Juego::Play()
{
	Dir.setHost("http://query.yahooapis.com");
	Req.setUri("v1/public/yql?q=select%20item.condition.code%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22Buenos%20Aires%2C%20arg%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
	Res = Dir.sendRequest(Req);
	data = json::parse(Res.getBody().c_str());
	string clima = data["query"]["results"]["channel"]["item"]["condition"]["code"];
	cout << clima << endl;
	climan = stoi(clima);

	RenderWindow wndw(VideoMode(800, 600), "Pro the C++ Expashon");
	CircleShape shape(25.f);
	RectangleShape cuadrado(Vector2f(30, 30));
	shape.setFillColor(Color::Red);
	cuadrado.setFillColor(Color::Green);
	float xC = 0;
	float yC = 0;
	

	
	/*Texture texture;
	texture.loadFromFile("PJ.png");
	IntRect rectSourceSprite(40, 0, 40, 40);
	Sprite sprite(texture, IntRect(0, 0, 40, 40));*/
	
	if (!music.loadFromFile("bensound-goinghigher.ogg"))
	{
		return -1;
	}
	
	sound.setBuffer(music);
	sound.setLoop(true);
	sound.play();
	while (wndw.isOpen())
	{
		Time frameStabilizer = clock.restart();

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
		
		pj.Movimiento();
		pj.getSprite().setTextureRect(pj.getIntRect());
		shape.setPosition(xC, yC);
		pj.getSprite().setPosition(pj.getX(), pj.getY());
		wndw.clear();	
	switch (climan)
		{
		case 30:
		case 26:
			wndw.clear(Color::Color(100,0,255,0));
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
		//wndw.clear(Color::White);
		wndw.draw(shape);
		wndw.draw(cuadrado);
		wndw.draw(pj.getSprite());
		wndw.display();
	}
	return 0;
}

int Juego::Menu()
{
	while (byemenu == false) {
		Play();
		byemenu = true;
	}
	return 0;
}

int Juego::Creditos()
{
	return 0;
}