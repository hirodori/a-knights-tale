#include "Escudeiro.h"

Escudeiro::Escudeiro(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Jogador(i, tamanho, pos, nv)
{
	body.setTexture("Assets//Escudeiro.png");
	body.setTextureRect(0, 0, 19, 20);
}

Escudeiro::Escudeiro() :
	Jogador()
{
	body.setTexture("Assets//Escudeiro.png");
	body.setTextureRect(0, 0, 19, 20);
}

Escudeiro::~Escudeiro()
{
}

void Escudeiro::executar()
{
	this->move();
	this->imprimir_se();
	if (delayDano >= 1 && delayDano < 250) {
		delayDano++;
	}
	else if (delayDano >= 250) {
		delayDano = 0;
	}
}

void Escudeiro::move()
{
	if (this->getNoAr()) {
		if (delayPulo >= 1) {
			this->pular();
		}
	}
	else {
		this->setDelayPulo(0);
	}
	if (pGEvento->keyPressed('I') && !(this->getNoAr())) {
		this->setDelayPulo(1);
		this->pular();
		this->setNoAr(true);
	}
	if (pGEvento->keyPressed('J')) {
		body.move(-0.7f, 0.f);
		body.setTextureRect(19, 0, 19, 20);
		faceRight = false;
	}
	if (pGEvento->keyPressed('L')) {
		body.move(0.7f, 0.f);
		body.setTextureRect(0, 0, 19, 20);
		faceRight = true;
	}
	if (pGEvento->keyPressed('K')) {
		body.move(0.f, 0.5f);
	}
	body.move(0.f, (*pGravidade));
}
