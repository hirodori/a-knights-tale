#include "Fase.h"

Fase::Fase(const int i, Cavaleiro* pJ1, Escudeiro* pJ2, G_Vetor2f tamanhoBack) :
	Ente(i, tamanhoBack), pJogador1(pJ1), pJogador2(pJ2), gerenciadorColisao(pJ1, pJ2), nJogadores(0), faseConcluida(false)
{
	gravidade = 0.4f;
	Personagem::setGravidade(&gravidade);
	Esqueleto::setLEntidades(&this->LEntidades);
	Cavaleiro::setLEntidades(&this->LEntidades);
}

Fase::Fase():
	Ente(), pJogador1(NULL), pJogador2(NULL), gerenciadorColisao(), nJogadores(0), faseConcluida(false)
{
	gravidade = 0.4f;
	Personagem::setGravidade(&gravidade);
	Esqueleto::setLEntidades(&this->LEntidades);
	Cavaleiro::setLEntidades(&this->LEntidades);

	this->getCorpo()->setSize(G_Vetor2f(2350.f, 2000.f));
}

Fase::~Fase()
{
}

void Fase::gerenciar_colisoes()
{
	gerenciadorColisao.executar();
}

const bool Fase::getFaseConcluida() const
{
	return faseConcluida;
}

void Fase::setFaseConcluida(const bool fc)
{
	faseConcluida = fc;
}
