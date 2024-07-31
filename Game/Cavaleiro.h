#pragma once
#include "Jogador.h"
#include "ListaEntidade.h"
#include "Projetil.h"

class Cavaleiro :
    public Jogador
{
private:
    static ListaEntidade* LEntidades;
    int delayAtaque;

public:
    Cavaleiro(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Cavaleiro();
    ~Cavaleiro();

    static void setLEntidades(ListaEntidade* pLE);

    void setDelayAtaque(const int da);
    const int getDelayAtaque() const;

    void executar();
    void move();
    void atacar();
};