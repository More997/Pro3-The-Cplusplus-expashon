#include "Menu.h"



Menu::Menu():
	texture(),
	climan(-1)
{
	texture.loadFromFile("Menu.png");
	sprite.setTexture(texture);
	font.loadFromFile("Crimson-Bold.ttf");
	TocaSpace.setFont(font);
	TocaSpace.setCharacterSize(15);
	TocaSpace.setFillColor(Color::White);
	
}


Menu::~Menu()
{
}

void Menu::Start()
{
	float WSizeY = 600;
	float WSizeX = 800;
	RenderWindow wndw(VideoMode(WSizeX, WSizeY), "The Pro C++ Expashon");
	Dir.setHost("http://query.yahooapis.com");
	Req.setUri("v1/public/yql?q=select%20item.condition.code%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22Buenos%20Aires%2C%20arg%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
	Res = Dir.sendRequest(Req);
	data = json::parse(Res.getBody().c_str());
	string clima = data["query"]["results"]["channel"]["item"]["condition"]["code"];
	cout << clima << endl;
	climan = stoi(clima);
	music.loadFromFile("Menu.wav");
	sound.setBuffer(music);
	sound.setLoop(true);
	sound.play();
	while (wndw.isOpen())
	{
		wndw.clear();
		wndw.draw(sprite);
		TocaSpace.setPosition(200, 150);
		TocaSpace.setString(L"PRESS SPACE TO START");
		wndw.draw(TocaSpace);
		TocaSpace.setPosition(400, 150);
		TocaSpace.setString(L"PRESS C TO SEE THE CREDITS");
		wndw.draw(TocaSpace);
		TocaSpace.setPosition(0, 0);
		switch (climan)
		{
		case Cloudy:
		case Cloudy2:
			TocaSpace.setString("The Weather today is Cloudy");
			break;
		case Sunny:
		case Sunny2:
			TocaSpace.setString("The Weather today is Sunny");
			break;
		case Rainy:
			TocaSpace.setString("The Weather today is Rainy");
		default:
			TocaSpace.setString("Sorry, but the Weather today is a Mystery");
			break;
		}	
		wndw.draw(TocaSpace);
		wndw.display();
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			sound.stop();
			cerrar = game.Play(wndw, evento, WSizeX, WSizeY, climan);
			sound.play();
		}
		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			sound.stop();
			cerrar = credits.Run(wndw, evento);
			sound.play();
		}
		if (cerrar == true)
		{
			wndw.close();
		}
		while (wndw.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				wndw.close();
		}
	}
}

