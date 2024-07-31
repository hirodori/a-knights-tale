#pragma once
#include "Inimigo.h"

class Raposa :
    public Inimigo
{
private:

public:
    Raposa(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Raposa();
    ~Raposa();

    void move();
};

