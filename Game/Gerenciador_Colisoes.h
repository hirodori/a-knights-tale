#pragma once
#include "Afx.h"
#include "Cavaleiro.h"
#include "Escudeiro.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Espinho.h"
#include "PinoEletrico.h"
#include "Projetil.h"
#include <SFML/Graphics.hpp>

class Gerenciador_Colisoes
{
private:
	Cavaleiro* pJogador1;
	Escudeiro* pJogador2;
	vector<Inimigo*> LIs;
	list<Obstaculo*> LOs;
	vector<Projetil*> LPs;

public:
	Gerenciador_Colisoes(Cavaleiro* pJogador1, Escudeiro* pJogador2);
	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();

	void setJogador1(Cavaleiro* pJogador1);
	void setJogador2(Escudeiro* pJogador2);

	void inserirInimigo(Inimigo* pIni);
	void inserirObstaculo(Obstaculo* pObs);
	void inserirProjetil(Projetil* pPro);

	void removerInimigo(Inimigo* pIni);
	void removerObstaculo(Obstaculo* pObs);
	void removerProjetil(Projetil* pPro);
	
	bool checaColisao(Entidade* primeiro, Entidade* segundo);
	bool determinaColisao(Entidade* primeiro, Entidade* segundo, float mov);

	void executar();
};

