#include "Plataforma.h"

Plataforma::Plataforma(const int i, G_Vetor2f tamanho, G_Vetor2f pos) :
	Obstaculo(i, tamanho, pos)
{
	body.setTexture("Assets//Plataforma.png");
}

Plataforma::Plataforma():
	Obstaculo()
{
	body.setTexture("Assets//Plataforma.png");
}

Plataforma::~Plataforma()
{
}
