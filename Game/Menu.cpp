#include "Menu.h"
#include "Jogo.h"

Jogo* Menu::pJogo = NULL;
void Menu::setPJogo(Jogo* pJ)
{
	if (pJ != NULL) {
		pJogo = pJ;
	}
	else {
		cout << "Ponteiro Jogo vazio." << endl;
	}
}

Gerenciador_Evento* Menu::pGEvento = NULL;
void Menu::setGEvento(Gerenciador_Evento* pE)
{
	if (pE != NULL) {
		pGEvento = pE;
	}
	else {
		cout << "Ponteiro Gerenciador_Evento vazio." << endl;
	}

}

Menu::Menu(const int i, G_Vetor2f tamanho) :
	Ente(i, tamanho)
{
	this->body.setTexture("Assets//MenuInicial.png");

	Botao* aux = NULL;
	for (int i = 0; i < 4; i++) {
		aux = new Botao(50.f, 60.f);
		if (aux != NULL) {
			LBotoes.push_back(aux);
		}
		aux = NULL;
	}
}

Menu::Menu() :
	Ente()
{
	this->body.setTexture("Assets//MenuInicial.png");
	Botao* aux = NULL;
	for (int i = 0; i < 4; i++) {
		aux = new Botao(50.f, 60.f);
		if (aux != NULL) {
			LBotoes.push_back(aux);
		}
		aux = NULL;
	}
}

Menu::~Menu()
{
}

void Menu::executar()
{
	if (!pJogo->getBConfigurado()) {
		this->menuInicial();
	}
	else if (pJogo->getBPausado()) {
		this->menuPausa();
	}
}

void Menu::menuInicial()
{
	this->body.setTexture("Assets//MenuInicial.png");

	LBotoes[0]->setPosition(105.f, 234.f);
	LBotoes[1]->setPosition(280.f, 234.f);
	LBotoes[2]->setPosition(456.f, 234.f);
	LBotoes[3]->setPosition(646.f, 234.f);


	while (!pJogo->getBConfigurado()) {

		pGGrafico->windowClear();
		this->imprimir_se();

		while (pGGrafico->pollEvent(pGEvento->getEvent())) {

			if (pGEvento->windowClosed()) {
				pGGrafico->windowClose();
				pJogo->setBConfigurado(true);
			}
			if (pGEvento->mouseButtonPressed()) {

				if (LBotoes[0]->mouseOnButton()) {
					//jogar
					this->menuJogador();
					this->menuFase();
					pJogo->setBConfigurado(true);

				}
				else if (LBotoes[1]->mouseOnButton()) {
					//carregar jogo - NÃO IMPLEMENTADO
					cout << "Opcao nao implementada." << endl;
				}
				else if (LBotoes[2]->mouseOnButton()) {
					//ranking - NÃO IMPLEMENTADO
					cout << "Opcao nao implementada." << endl;
				}
				else if (LBotoes[3]->mouseOnButton()) {
					//sair
					pGGrafico->windowClose();
					pJogo->setBConfigurado(true);
				}

			}

		}
		pGGrafico->windowDisplay();
	}

}

void Menu::menuJogador()
{
	this->body.setTexture("Assets//MenuJogador.png");

	LBotoes[0]->setPosition(105.f, 234.f);
	LBotoes[1]->setPosition(646.f, 234.f);

	while (!(pJogo->getBJogador1() || pJogo->getBJogador2())) {
		pGGrafico->windowClear();
		this->imprimir_se();

		while (pGGrafico->pollEvent(pGEvento->getEvent())) {

			if (pGEvento->windowClosed()) {
				pGGrafico->windowClose();
			}
			if (pGEvento->mouseButtonPressed()) {

				if (LBotoes[0]->mouseOnButton()) {
					//jogador1
					pJogo->setBJogador1(true);

				}
				else if (LBotoes[1]->mouseOnButton()) {
					//jogador1 & jogador2
					pJogo->setBJogador1(true);
					pJogo->setBJogador2(true);
				}

			}

		}
		pGGrafico->windowDisplay();

	}

}

void Menu::menuFase()
{
	this->body.setTexture("Assets//MenuFase.png");

	LBotoes[0]->setPosition(228.f, 234.f);
	LBotoes[1]->setPosition(515.f, 234.f);

	while (!(pJogo->getBFase1() || pJogo->getBFase2())) {
		pGGrafico->windowClear();
		this->imprimir_se();

		while (pGGrafico->pollEvent(pGEvento->getEvent())) {

			if (pGEvento->windowClosed()) {
				pGGrafico->windowClose();
			}
			if (pGEvento->mouseButtonPressed()) {

				if (LBotoes[0]->mouseOnButton()) {
					//fase1
					pJogo->setBFase1(true);
					pJogo->setBFase2(false);

				}
				else if (LBotoes[1]->mouseOnButton()) {
					//fase2
					pJogo->setBFase2(true);
					pJogo->setBFase1(false);
				}

			}

		}
		pGGrafico->windowDisplay();

	}

}

void Menu::menuPausa()
{
	this->body.setTexture("Assets//MenuPausa.png");
	LBotoes[0]->setPosition(105.f, 234.f);
	LBotoes[1]->setPosition(371.f, 234.f);
	LBotoes[2]->setPosition(646.f, 234.f);

	while (pJogo->getBPausado()) {
		pGGrafico->windowClear();
		this->imprimir_se();

		while (pGGrafico->pollEvent(pGEvento->getEvent())) {

			if (pGEvento->windowClosed()) {
				pGGrafico->windowClose();
			}
			if (pGEvento->mouseButtonPressed()) {

				if (LBotoes[0]->mouseOnButton()) {
					//continuar
					pJogo->setBPausado(false);
				}
				else if (LBotoes[1]->mouseOnButton()) {
					//salvar - NÃO IMPLEMENTADA
					cout << "Opcao nao implementada." << endl;
				}
				else if (LBotoes[2]->mouseOnButton()) {
					//sair
					pGGrafico->windowClose();
					pJogo->setBPausado(false);
				}
			}

		}
		pGGrafico->windowDisplay();
	}

}
