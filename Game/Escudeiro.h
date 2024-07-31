#pragma once
#include "Jogador.h"
class Escudeiro :
    public Jogador
{
private:

public:
    Escudeiro(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Escudeiro();
    ~Escudeiro();

    void executar();
    void move();
};

