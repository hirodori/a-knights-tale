#pragma once
#include "Obstaculo.h"

class Plataforma :
    public Obstaculo
{
private:

public:
    Plataforma(const int i, G_Vetor2f tamanho, G_Vetor2f pos);
    Plataforma();
    ~Plataforma();

};

