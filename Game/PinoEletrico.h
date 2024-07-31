#pragma once
#include "Obstaculo.h"

class PinoEletrico :
    public Obstaculo
{
private:
    bool desativado;
    int brilho;

public:
    PinoEletrico(const int i, G_Vetor2f tamanho, G_Vetor2f pos);
    PinoEletrico();
    ~PinoEletrico();

    void setDesativado(const bool des);
    const bool getDesativado() const;
    void setBrilho(const int b);
    const int getBrilho() const;

    void executar();
};

