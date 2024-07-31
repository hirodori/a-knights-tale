#include "Jogo.h"

Jogo::Jogo() :
    gerenciadorGrafico(), gerenciadorEvento(), menu(10, G_Vetor2f(800.f, 600.f)), jogador1(NULL), jogador2(NULL),
    faseUm(NULL), faseDois(NULL)
{
    Gerenciador_Evento::setGGrafico(&gerenciadorGrafico);
    Ente::setGGrafico(&gerenciadorGrafico);
    Jogador::setGEvento(&gerenciadorEvento);
    Botao::setGEvento(&gerenciadorEvento);
    Menu::setPJogo(this);
    Menu::setGEvento(&gerenciadorEvento);

    //Inicializa bools
    bJogador1 = false;
    bJogador2 = false;
    bFase1 = false;
    bFase2 = false;
    bConfigurado = false;
    bPausado = false;

    executar();
}

Jogo::~Jogo()
{
    if (this->getBJogador1()) {
        delete(jogador1);
    }
    if (this->getBJogador2()) {
        delete(jogador2);
    }
    if (this->getBFase1()) {
        delete(faseUm);
    }
    if (this->getBFase2()) {
        delete(faseDois);
    }
}

void Jogo::executar()
{
    srand((unsigned int)time(NULL));

    while (!this->getBConfigurado())
    {
        menu.executar();

        if (this->getBJogador1()) {
            jogador1 = new Cavaleiro(1, G_Vetor2f(50.f, 50.f), G_Vetor2f(100.f, 100.f), 3);
        }
        if (this->getBJogador2()) {
            jogador2 = new Escudeiro(2, G_Vetor2f(60.f, 60.f), G_Vetor2f(300.f, 100.f), 3);
        }

        if (this->getBFase1()) {
             faseUm = new Fase_Primeira(11, jogador1, jogador2, G_Vetor2f(2350.f, 2000.f));
        }
        else if (this->getBFase2()) {
           faseDois = new Fase_Segunda(12, jogador1, jogador2, G_Vetor2f(2350.f, 2000.f));
        }
    }

    while (gerenciadorGrafico.windowIsOpen())
    {

        while (gerenciadorGrafico.pollEvent(gerenciadorEvento.getEvent()))
        {
            if (gerenciadorEvento.windowClosed()) {
                gerenciadorGrafico.windowClose();
            }
            if (gerenciadorEvento.keyPressed('P')) {
                gerenciadorGrafico.setWindowDefaultView();
                this->setBPausado(true);
                menu.executar();
            }
        }

        gerenciadorGrafico.windowClear();

        if (this->getBFase1()) {
            faseUm->executar();
        }
        else if (this->getBFase2()) {
            faseDois->executar();
        }

        this->checagemJogadores();

        if (this->getBJogador1()) {
            gerenciadorGrafico.setViewCenter(jogador1->getCorpo()->getPosition().vetorSFML());
        }
        else if (this->getBJogador2()) {
            gerenciadorGrafico.setViewCenter(jogador2->getCorpo()->getPosition().vetorSFML());
        }
        else {
            gerenciadorGrafico.setWindowDefaultView();
        }
        gerenciadorGrafico.setWindowView(&gerenciadorGrafico.getView());

        if (!(this->getBJogador1()) && !(this->getBJogador2())) {
            cout << "Game Over!" << endl;
            gerenciadorGrafico.windowClose();
        }

        if (this->getBFase1()) {
            if (faseUm->getFaseConcluida()) {
                this->setBFase1(false);
                delete(faseUm);
                faseUm = NULL;
                this->setBFase2(true);
                faseDois = new Fase_Segunda(12, jogador1, jogador2, G_Vetor2f(2350.f, 2000.f));
            }
        }
        else if (this->getBFase2()) {
            if (faseDois->getFaseConcluida()) {
                cout << "VOCE GANHOU!!!" << endl;
                if (this->getBJogador1()) {
                    cout << "Total de pontos: " << jogador1->getPontuacao() << endl;
                }
                else if (this->getBJogador2()) {
                    cout << "Total de pontos: " << jogador2->getPontuacao() << endl;
                }
                this->setBFase2(false);
                delete(faseDois);
                faseDois = NULL;
            }
        }


        gerenciadorGrafico.windowDisplay();
    }

}

void Jogo::setBJogador1(const bool jogador1)
{
    bJogador1 = jogador1;
}

void Jogo::setBJogador2(const bool jogador2)
{
    bJogador2 = jogador2;
}

void Jogo::setBFase1(const bool fase1)
{
    bFase1 = fase1;
}

void Jogo::setBFase2(const bool fase2)
{
    bFase2 = fase2;
}

void Jogo::setBConfigurado(const bool configurado)
{
    bConfigurado = configurado;
}

void Jogo::setBPausado(const bool pausado)
{
    bPausado = pausado;
}

const bool Jogo::getBJogador1()
{
    return bJogador1;
}

const bool Jogo::getBJogador2()
{
    return bJogador2;
}

const bool Jogo::getBFase1()
{
    return bFase1;
}

const bool Jogo::getBFase2()
{
    return bFase2;
}

const bool Jogo::getBConfigurado()
{
    return bConfigurado;
}

const bool Jogo::getBPausado()
{
    return bPausado;
}

void Jogo::checagemJogadores()
{
    if (jogador1 && this->getBJogador1()) {
        if (!jogador1->aindaVivo()) {
            if (jogador2 && this->getBJogador2()) {
                if (!jogador2->aindaVivo()) {
                    cout << "Total de pontos: " << jogador1->getPontuacao() << endl;
                    this->setBJogador1(false);
                    this->setBJogador2(false);
                    delete(jogador1);
                    delete(jogador2);
                    jogador1 = NULL;
                    jogador2 = NULL;
                }
                else {
                    this->setBJogador1(false);
                    delete(jogador1);
                    jogador1 = NULL;
                }
            }
            else {
                cout << "Total de pontos: " << jogador1->getPontuacao() << endl;
                this->setBJogador1(false);
                delete(jogador1);
                jogador1 = NULL;
            }
        }
        else {
            if (jogador2 && this->getBJogador2()) {
                if (!jogador2->aindaVivo()) {
                    this->setBJogador2(false);
                    delete(jogador2);
                    jogador2 = NULL;
                }
            }
        }
    }
    else if (jogador2 && this->getBJogador2()) {
        if (!jogador2->aindaVivo()) {
            cout << "Total de pontos: " << jogador1->getPontuacao() << endl;
            this->setBJogador2(false);
            delete(jogador2);
            jogador2 = NULL;
        }
    }

}
