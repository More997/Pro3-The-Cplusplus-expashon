#include "Juego.h"



Juego::Juego()
	:
	findeljuego(false),
	texture()
{
	texture.loadFromFile("Tela.png");
	sprite.setTexture(texture);
}



Juego::~Juego()
{
	
}

int Juego::Play(/*RenderWindow &wndw*/)
{
	arania.Activando(true);
	puntaje = 0;
	float WSizeY = 600;
	float WSizeX = 800;
	RenderWindow wndw(VideoMode(WSizeX, WSizeY), "Pro the C++ Expashon");
	while (wndw.isOpen() || pj.getVivo() == true)
	{
		Time frameStabilizer = clock.restart();
		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				break;
		}
		pj.setVivo(arania.Colision(pj));
		arania.Movimiento(pj, frameStabilizer);
		pj.Movimiento(WSizeX, WSizeY,frameStabilizer);
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
		wndw.draw(sprite);
		wndw.draw(pj.getSprite());
		wndw.draw(arania.getSprite());
		wndw.display();
	}
	return 0;
}

int Juego::Menu()
{

	Dir.setHost("http://query.yahooapis.com");
	Req.setUri("v1/public/yql?q=select%20item.condition.code%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22Buenos%20Aires%2C%20arg%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
	Res = Dir.sendRequest(Req);
	data = json::parse(Res.getBody().c_str());
	string clima = data["query"]["results"]["channel"]["item"]["condition"]["code"];
	cout << clima << endl;
	climan = stoi(clima);
	if (!music.loadFromFile("Music.ogg"))
	{
		return -1;
	}

	sound.setBuffer(music);
	sound.setLoop(true);
	sound.play();
	Play(/*wndw*/);
	return 0;
}

int Juego::Creditos()
{
	return 0;
}