#pragma once
#include "Ente.h"

class Entidade :
	public Ente
{
protected:
	G_Vetor2f posicao;

public:
	Entidade(const int i, G_Vetor2f tamanho, G_Vetor2f pos);
	Entidade();
	~Entidade();

	virtual void executar() = 0;
	virtual void move() = 0;
	virtual void move(float x, float y);
};

