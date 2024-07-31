#include "Cavaleiro.h"

ListaEntidade* Cavaleiro::LEntidades = NULL;
void Cavaleiro::setLEntidades(ListaEntidade* pLE)
{
	if (pLE != NULL) {
		LEntidades = pLE;
	}
	else {
		cout << "Ponteiro Lista Entidade vazio." << endl;
	}
}

Cavaleiro::Cavaleiro(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Jogador(i, tamanho, pos, nv), delayAtaque(0)
{
	body.setTexture("Assets//Hero.png");
	body.setTextureRect(0, 0, 19, 18);
}

Cavaleiro::Cavaleiro() :
	Jogador(), delayAtaque(0)
{
	body.setTexture("Assets//Hero.png");
	body.setTextureRect(0, 0, 19, 18);
}

Cavaleiro::~Cavaleiro()
{
}

void Cavaleiro::setDelayAtaque(const int da)
{
	delayAtaque = da;
}

const int Cavaleiro::getDelayAtaque() const
{
	return delayAtaque;
}

void Cavaleiro::executar()
{
	this->move();
	this->imprimir_se();

	if (delayDano >= 1 && delayDano < 500) {
		delayDano++;
	}
	else if (delayDano >= 500) {
		delayDano = 0;
	}

	if (delayAtaque >= 1 && delayAtaque < 500)
	{
		delayAtaque++;
	}
	else if (delayAtaque >= 500)
	{
		delayAtaque = 0;
	}
}

void Cavaleiro::move()
{
	if (this->getNoAr()) {
		if (delayPulo >= 1) {
			this->pular();
		}
	}
	else {
		this->setDelayPulo(0);
	}
	if (pGEvento->keyPressed('W') && !(this->getNoAr())) {
		this->setDelayPulo(1);
		this->pular();
		this->setNoAr(true);
	}
	if (pGEvento->keyPressed('A')) {
		body.move(-0.7f, 0.f);
		body.setTextureRect(19, 0, 19, 18);
		faceRight = false;
	}
	if (pGEvento->keyPressed('D')) {
		body.move(0.7f, 0.f);
		body.setTextureRect(0, 0, 19, 18);
		faceRight = true;
	}
	if (pGEvento->keyPressed('S')) {
		body.move(0.f, 0.7f);
	}
	if (pGEvento->keyPressed('C')) {
		this->atacar();
		delayAtaque++;
	}
	body.move(0.f, (*pGravidade));
}

void Cavaleiro::atacar()
{
	if (delayAtaque == 0)
	{
		Projetil* pProj = new Projetil(9, G_Vetor2f(30.f, 15.f), this->getCorpo()->getPosition(), this->getId(), faceRight);
		if (pProj != NULL)
		{
			LEntidades->LEs.inserir(dynamic_cast<Entidade*>(pProj));
		}
		pProj = NULL;
	}
}
