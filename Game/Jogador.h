#pragma once
#include "Personagem.h"
#include "Gerenciador_Evento.h"

class Jogador :
    public Personagem
{
protected:
    static Gerenciador_Evento* pGEvento;
    static int pontuacao;

public:
    Jogador(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Jogador();
    ~Jogador();

    static void setGEvento(Gerenciador_Evento* pE);

    void operator++(const int p);
    const int getPontuacao() const;

    virtual void executar() = 0;
    virtual void move() = 0;
};

