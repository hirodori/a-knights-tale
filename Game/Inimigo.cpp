#include "Inimigo.h"

Inimigo::Inimigo(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Personagem(i, tamanho, pos, nv), direcao(0), conta_tempo(0)
{
}

Inimigo::Inimigo():
	Personagem(), direcao(0), conta_tempo(0)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::setDirecao(const int d)
{
	direcao = d;
}

const int Inimigo::getDirecao() const
{
	return direcao;
}

void Inimigo::setContaTempo(const int ct)
{
	conta_tempo = ct;
}

const int Inimigo::getContaTempo() const
{
	return conta_tempo;
}
