#include "Entidade.h"

Entidade::Entidade(const int i, G_Vetor2f tamanho, G_Vetor2f pos) :
	Ente(i, tamanho), posicao(pos)
{
	body.setPosition(pos);
	body.setCenterOrigin(tamanho);
}

Entidade::Entidade() :
	Ente(), posicao(0.f, 0.f)
{
}

Entidade::~Entidade()
{
}

void Entidade::move(float x, float y)
{
	this->body.move(x, y);
}
