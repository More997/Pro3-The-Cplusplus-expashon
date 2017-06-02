#include "Personaje.h"



Personaje::Personaje()
{
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
}

void Personaje::Animacion()
{
}


Personaje::~Personaje()
{
}
