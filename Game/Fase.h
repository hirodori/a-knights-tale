#pragma once
#include "Ente.h"
#include "ListaEntidade.h"
#include "Personagem.h"
#include "Cavaleiro.h"
#include "Escudeiro.h"
#include "Inimigo.h"
#include "Passaro.h"
#include "Esqueleto.h"
#include "Raposa.h"
#include "Obstaculo.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "PinoEletrico.h"
#include "Projetil.h"
#include "Gerenciador_Colisoes.h"

class Fase :
    public Ente
{
protected:
    ListaEntidade LEntidades;
    Cavaleiro* pJogador1;
    Escudeiro* pJogador2;

    Gerenciador_Colisoes gerenciadorColisao;

    float gravidade;
    int nJogadores;

    bool faseConcluida;


public:
    Fase(const int i, Cavaleiro* pJ1, Escudeiro* pJ2, G_Vetor2f tamanhoBack);
    Fase();
    ~Fase();

    virtual void inicializarMapa() = 0;
    virtual void executar() = 0;
    void gerenciar_colisoes();
    const bool getFaseConcluida() const;
    void setFaseConcluida(const bool fc);

};