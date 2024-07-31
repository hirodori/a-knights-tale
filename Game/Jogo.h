#pragma once
#include "Afx.h"
#include "G_Vetor2.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Evento.h"
#include "Botao.h" //setGEvento
#include "Jogador.h"
#include "Cavaleiro.h"
#include "Escudeiro.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "Menu.h"

class Jogo
{
private:
	Gerenciador_Grafico gerenciadorGrafico;
	Gerenciador_Evento gerenciadorEvento;
	Menu menu;
	Cavaleiro* jogador1;
	Escudeiro* jogador2;
	Fase_Primeira* faseUm;
	Fase_Segunda* faseDois;

	bool bJogador1;
	bool bJogador2;
	bool bFase1;
	bool bFase2;
	bool bConfigurado;
	bool bPausado;

public:
	Jogo();
	~Jogo();

	void executar();

	void setBJogador1(const bool jogador1);
	void setBJogador2(const bool jogador2);
	void setBFase1(const bool fase1);
	void setBFase2(const bool fase2);
	void setBConfigurado(const bool configurado);
	void setBPausado(const bool pausado);

	const bool getBJogador1();
	const bool getBJogador2();
	const bool getBFase1();
	const bool getBFase2();
	const bool getBConfigurado();
	const bool getBPausado();

	void checagemJogadores();
};
