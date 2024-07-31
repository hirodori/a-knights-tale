#pragma once
#include "Inimigo.h"

class Passaro :
    public Inimigo
{
private:

public:
    Passaro(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Passaro();
    ~Passaro();

    void move();
};

