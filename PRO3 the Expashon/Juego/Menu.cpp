#include "Menu.h"



Menu::Menu():
	texture(),
	climan(-1)
{
	texture.loadFromFile("Menu.png");
	sprite.setTexture(texture);
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
	
		wndw.display();
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			sound.stop();
			cerrar = game.Play(wndw, evento, WSizeX, WSizeY, climan);
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

