#pragma once
#include "Personagem.h"

class Inimigo :
    public Personagem
{
protected:
    int direcao;
    int conta_tempo;

public:
    Inimigo(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Inimigo();
    ~Inimigo();

    void setDirecao(const int d);
    const int getDirecao() const;
    void setContaTempo(const int ct);
    const int getContaTempo() const;

    virtual void move() = 0;
};

