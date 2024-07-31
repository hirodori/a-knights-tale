#include "Passaro.h"

Passaro::Passaro(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Inimigo(i, tamanho, pos, nv)
{
	body.setTexture("Assets//Passaro.png");
	body.setTextureRect(0, 0, 47, 40);
}

Passaro::Passaro():
	Inimigo()
{
	body.setTexture("Assets//Passaro.png");
	body.setTextureRect(0, 0, 47, 40);
}

Passaro::~Passaro()
{
}

void Passaro::move()
{
	
	if (conta_tempo == 0) {
		direcao = rand() % 2 + 1;
	}
	if (direcao == 1) {
		this->body.move(0.6f, 0.f + (*pGravidade));
		body.setTextureRect(0, 0, 47, 40);
		faceRight = true;
	}
	else if (direcao == 2) {
		this->body.move(-0.6f, 0.f + (*pGravidade));
		body.setTextureRect(47, 0, 47, 40);
		faceRight = false;
	}

	conta_tempo++;

	if (conta_tempo >= 500) {
		direcao = rand() % 2 + 1;
		conta_tempo = 1;
	}
}

