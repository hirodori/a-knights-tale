#include "Obstaculo.h"

Obstaculo::Obstaculo(const int i, G_Vetor2f tamanho, G_Vetor2f pos) :
	Entidade(i, tamanho, pos)
{
}

Obstaculo::Obstaculo():
	Entidade()
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::executar()
{
	imprimir_se();
}

void Obstaculo::move()
{
	body.move(0.f, 0.f);
}

void Obstaculo::move(float x, float y)
{
	x = 0.f;
	y = 0.f;
	body.move(x, y);
}

