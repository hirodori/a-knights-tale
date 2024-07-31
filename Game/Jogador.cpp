#include "Jogador.h"

Gerenciador_Evento* Jogador::pGEvento = NULL;
void Jogador::setGEvento(Gerenciador_Evento* pE)
{
	if (pE != NULL) {
		pGEvento = pE;
	}
	else {
		cout << "Ponteiro Gerenciador Evento vazio." << endl;
	}
}

int Jogador::pontuacao = 0;

Jogador::Jogador(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Personagem(i, tamanho, pos, nv)
{
}

Jogador::Jogador() :
	Personagem()
{
}

Jogador::~Jogador()
{
}

void Jogador::operator++(int p)
{
	pontuacao += p;
}

const int Jogador::getPontuacao() const
{
	return pontuacao;
}
