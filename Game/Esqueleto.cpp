#include "Esqueleto.h"

ListaEntidade* Esqueleto::LEntidades = NULL;
void Esqueleto::setLEntidades(ListaEntidade* pLE)
{
	if (pLE != NULL) {
		LEntidades = pLE;
	}
	else {
		cout << "Ponteiro Lista Entidade vazio." << endl;
	}
}

void Esqueleto::setDelayProj(const int dp)
{
	delayProj = dp;
}

const int Esqueleto::getDelayProj() const
{
	return delayProj;
}

Esqueleto::Esqueleto(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Inimigo(i, tamanho, pos, nv), delayProj(0)
{
	body.setTexture("Assets//Esqueleto.png");
	body.setTextureRect(0, 0, 15, 18);
}

Esqueleto::Esqueleto() :
	Inimigo(), delayProj(0)
{
	body.setTexture("Assets//Esqueleto.png");
	body.setTextureRect(0, 0, 15, 18);
}

Esqueleto::~Esqueleto()
{
}

void Esqueleto::executar()
{
	this->move();
	this->criarProjetil();
	this->imprimir_se();
	if (delayDano >= 1 && delayDano < 500) {
		delayDano++;
	}
	else if (delayDano >= 500) {
		delayDano = 0;
	}
}

void Esqueleto::move()
{
	if (conta_tempo == 0) {
		direcao = rand() % 2 + 1;
	}
	if (direcao == 1) {
		this->body.move(0.5f, 0.f + (*pGravidade));
		body.setTextureRect(0, 0, 15, 18);
		faceRight = true;
	}
	else if (direcao == 2) {
		this->body.move(-0.5f, 0.f + (*pGravidade));
		body.setTextureRect(15, 0, 15, 18);
		faceRight = false;
	}

	conta_tempo++;

	if (conta_tempo >= 500) {
		direcao = rand() % 2 + 1;
		conta_tempo = 1;
	}
}

void Esqueleto::criarProjetil()
{
	int atacar = rand() % 500 + 1;

	if (atacar == 1 && delayProj == 0)
	{
		Projetil* pProj = new Projetil(9, G_Vetor2f(30.f, 15.f), this->getCorpo()->getPosition(), 4, faceRight);
		if (pProj != NULL)
		{
			LEntidades->LEs.inserir(dynamic_cast<Entidade*>(pProj));
		}
		pProj = NULL;
		delayProj++;
	}
	else if (delayProj >= 1)
	{
		delayProj++;
	}

	if (delayProj >= 1000) {
		delayProj = 0;
	}
}

