#pragma once
#include "Afx.h"
#include "Ente.h"
#include "Botao.h"
#include "Gerenciador_Evento.h"

class Jogo;

class Menu :
    public Ente

{
private:
    static Jogo* pJogo;
    static Gerenciador_Evento* pGEvento;
    vector<Botao*> LBotoes;

public:
    Menu(const int i, G_Vetor2f tamanho);
    Menu();
    ~Menu();

    static void setPJogo(Jogo* pJ);
    static void setGEvento(Gerenciador_Evento* pE);

    void executar();

private:
    void menuInicial();
    void menuJogador();
    void menuFase();
    void menuPausa();

};

