#pragma once
#include "Entidade.h"

class Personagem :
    public Entidade
{
protected:
    int num_vidas;
    static float* pGravidade;
    bool vivo;
    bool faceRight;
    int delayDano;
    bool noAr;
    int delayPulo;

public:
    Personagem(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv);
    Personagem();
    ~Personagem();

    static void setGravidade(float* gravidade);

    void setNVidas(const int nv);
    const int getNVidas() const;
    const bool aindaVivo() const;
    void setFaceRight(const bool fc);
    const bool getFaceRight() const;
    void setDelayDano(const int dd);
    const int getDelayDano() const;
    void setNoAr(const bool na);
    const bool getNoAr() const;
    void setDelayPulo(const int dp);
    const int getDelayPulo() const;

    void operator--();

    virtual void executar();
    virtual void move() = 0;
    virtual void pular();
};

