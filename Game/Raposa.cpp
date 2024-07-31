#include "Raposa.h"

Raposa::Raposa(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Inimigo(i, tamanho, pos, nv)
{
	body.setTexture("Assets//Raposa.png");
	body.setTextureRect(0, 0, 64, 57);
}

Raposa::Raposa() :
	Inimigo()
{
	body.setTexture("Assets//Raposa.png");
	body.setTextureRect(0, 0, 64, 57);
}

Raposa::~Raposa()
{
}

void Raposa::move()
{
	if (conta_tempo == 0) {
		direcao = rand() % 2 + 1;
	}
	if (this->getNoAr()) {
		if (delayPulo >= 1) {
			this->pular();
		}
	}
	else {
		this->setDelayPulo(0);
	}
	if (direcao == 1) {
		if (!(this->getNoAr())) {
			this->setDelayPulo(1);
			this->pular();
			this->setNoAr(true);
		}
		this->body.move(0.8f, 0.f + (*pGravidade));
		body.setTextureRect(0, 0, 64, 57);
	}
	else if (direcao == 2) {
		if (!(this->getNoAr())) {
			this->setDelayPulo(1);
			this->pular();
			this->setNoAr(true);
		}
		this->body.move(-0.8f, 0.f + (*pGravidade));
		body.setTextureRect(64, 0, 64, 57);
	}

	conta_tempo++;

	if (conta_tempo >= 500) {
		direcao = rand() % 2 + 1;
		conta_tempo = 1;
	}
}
