#pragma once
#include "Obstaculo.h"

class Espinho :
    public Obstaculo
{
private:

public:
    Espinho(const int i, G_Vetor2f tamanho, G_Vetor2f pos);
    Espinho();
    ~Espinho();
};

