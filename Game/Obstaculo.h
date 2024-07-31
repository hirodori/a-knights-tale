#pragma once
#include "Entidade.h"

class Obstaculo :
    public Entidade
{
private:

public:
	Obstaculo(const int i, G_Vetor2f tamanho, G_Vetor2f pos);
	Obstaculo();
	~Obstaculo();

	virtual void executar();
	void move();
	void move(float x, float y);
};

