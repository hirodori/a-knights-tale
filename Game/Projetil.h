#pragma once
#include "Entidade.h"

class Projetil : 
    public Entidade
{
private:
    const int idDono;
    bool faceRight;
    bool colidiu;

public:
    Projetil(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int donoId, const bool faceRight);
    Projetil();
    ~Projetil();

    void executar();
    void move();
    const int getIdDono();
    void setColidiu(const bool C);
    const bool getColidiu() const;
    void setFaceRight(const bool fc);
    const bool getFaceRight() const;
};

