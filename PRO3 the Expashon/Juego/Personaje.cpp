#include "Personaje.h"



Personaje::Personaje()
{
	texture.loadFromFile("PJ.png");
	//IntRect rectSourceSprite (40,0,40,0); Left top width height 
	/*rectSourceSprite.left(40);
	rectSourceSprite.top(0);
	rectSourceSprite.width(40);
	rectSourceSprite.top(0);*/
	rectSourceSprite.contains(40, 40);
	//sprite(texture, IntRect(0, 0, 40, 40));
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 40, 40));
}

void Personaje::Movimiento(Event evento)
{
	if (evento.type == Event::KeyPressed)
	{
		if (evento.key.code == Keyboard::Up)
		{
			Y -= 0.1f;
			//rectSourceSprite.left = 0;
			//rectSourceSprite.top = 0;
		}
		else if (evento.key.code == Keyboard::Down)
		{
			Y += 0.1f;
			//rectSourceSprite.top = 40;
			//rectSourceSprite.left = 0;

		}
		else if (evento.key.code == Keyboard::Right)
		{
			X += 0.1f;
			//rectSourceSprite.left = 40;
			//rectSourceSprite.top = 40;
		}
		else if (evento.key.code == Keyboard::Left)
		{
			X -= 0.1f;
			//rectSourceSprite.left = 40;
			//rectSourceSprite.top = 0;
		}
	}
	Animacion();
}

void Personaje::Animacion()
{
}

float Personaje::getX()
{
	return X;
}

float Personaje::getY()
{
	return Y;
}

Sprite Personaje::getSprite()
{
	return sprite;
}

IntRect Personaje::getIntRect()
{
	return rectSourceSprite;
	;
}

void Personaje::setX(float _X)
{
	X = _X;
}

void Personaje::setY(float _Y)
{
	Y = _Y;
}


Personaje::~Personaje()
{
}
