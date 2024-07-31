#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "ListaEntidade.h"

class Esqueleto :
    public Inimigo
{
private:
    static ListaEntidade* LEntidades;
    int delayProj;

public:
    Esqueleto(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Esqueleto();
    ~Esqueleto();

    static void setLEntidades(ListaEntidade* pLE);

    void setDelayProj(const int dp);
    const int getDelayProj() const;

    void executar();
    void move();
    void criarProjetil();
};
