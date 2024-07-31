#include "Espinho.h"

Espinho::Espinho(const int i, G_Vetor2f tamanho, G_Vetor2f pos) :
	Obstaculo(i, tamanho, pos)
{
	body.setTexture("Assets//Espinho.png");
}

Espinho::Espinho():
	Obstaculo()
{
	body.setTexture("Assets//Espinho.png");
}

Espinho::~Espinho()
{
}
