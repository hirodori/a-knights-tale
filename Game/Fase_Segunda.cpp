#include "Fase_Segunda.h"

Fase_Segunda::Fase_Segunda(const int i, Cavaleiro* pJ1, Escudeiro* pJ2, G_Vetor2f tamanhoBack) :
	Fase(i, pJ1, pJ2, tamanhoBack)
{
	body.setTexture("Assets//Fase02.png");

	if (pJ1 != NULL)
	{
		LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pJ1));
		nJogadores++;
	}
	if (pJ2 != NULL)
	{
		LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pJ2));
		nJogadores++;
	}

	inicializarMapa();

}

Fase_Segunda::Fase_Segunda() :
	Fase()
{
	body.setTexture("Assets//Fase02.png");
}

Fase_Segunda::~Fase_Segunda()
{
	Entidade* aux = NULL;
	int total = LEntidades.LEs.getTotal();

	for (int i = total - 1; i > nJogadores - 1; i--) {
		aux = LEntidades.LEs.getInfo(i);
		delete(aux);
	}
}

void Fase_Segunda::inicializarMapa()
{
	//Criação de Obstaculos e Inimigos
	//Random
	int nObsA = 0, nObsB = 0;
	int nIniA = 0, nIniB = 0;


	for (int i = 0; i < 25; i++) { //altura
		for (int j = 0; j < 32; j++) { //largura

			if (faseMapa[i][j] == ' ') {
				continue;
			}
			else if (faseMapa[i][j] == 'c' && pJogador1 != NULL) {
				pJogador1->getCorpo()->setPosition(G_Vetor2f(425.f + 50 * j, 425.f + 50.f * i));
			}
			else if (faseMapa[i][j] == 'd' && pJogador2 != NULL) {
				pJogador2->getCorpo()->setPosition(G_Vetor2f(425.f + 50 * j, 425.f + 50.f * i));
			}
			else if (faseMapa[i][j] == '#') {
				Plataforma* pPlat = new Plataforma(6, G_Vetor2f(50.f, 50.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i));
				LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPlat));
				gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pPlat));;
				pPlat = NULL;
			}
			else if (faseMapa[i][j] == '^') {
				Espinho* pEsp = new Espinho(7, G_Vetor2f(50.f, 40.f), G_Vetor2f(425.f + (50.f * j) + 10.f, 425.f + (50.f * i) + 10));
				LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pEsp));
				gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pEsp));
				pEsp = NULL;
			}
			else if (faseMapa[i][j] == '*') {
				PinoEletrico* pPin = new PinoEletrico(8, G_Vetor2f(20.f, 30.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i + 10.f));
				LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPin));
				gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pPin));
				pPin = NULL;
			}
			else if (faseMapa[i][j] == 'p') {
				Passaro* pPas = new Passaro(3, G_Vetor2f(75.f, 75.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 1);
				LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPas));
				gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pPas));
				pPas = NULL;
			}
			else if (faseMapa[i][j] == 'e') {
				Esqueleto* pEsq = new Esqueleto(4, G_Vetor2f(50.f, 50.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 3);
				LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pEsq));
				gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pEsq));
				pEsq = NULL;
			}
			else if (faseMapa[i][j] == 'r') {
				Raposa* pRap = new Raposa(5, G_Vetor2f(100.f, 100.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 10);
				LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pRap));
				gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pRap));
				pRap = NULL;
			}
			else if (faseMapa[i][j] == '?') { //Inimigo aleatorio
				bool decidido = false;
				int r = rand() % 2 + 1;

				while (!decidido) {

					if (nIniA >= 3 && nIniB >= 3) { //se o minimo já foi atingido
						r = rand() % 3 + 1; //chance de não ser adicionado nenhum

						if (r == 1) { //Passaro
							Passaro* pPas = new Passaro(3, G_Vetor2f(75.f, 75.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 1);
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPas));
							gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pPas));
							pPas = NULL;
							nIniA++;
						}
						else if (r == 2) { //Esqueleto
							Esqueleto* pEsq = new Esqueleto(4, G_Vetor2f(50.f, 50.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 3);
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pEsq));
							gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pEsq));
							pEsq = NULL;
							nIniB++;
						}
						decidido = true;
					}
					else {
						if (r == 1 && nIniA < 3) { //Passaro
							Passaro* pPas = new Passaro(3, G_Vetor2f(75.f, 75.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 1);
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPas));
							gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pPas));
							pPas = NULL;
							nIniA++;
							decidido = true;
						}
						else if (r == 2 && nIniB < 3) { //Esqueleto
							Esqueleto* pEsq = new Esqueleto(4, G_Vetor2f(50.f, 50.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i), 3);
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pEsq));
							gerenciadorColisao.inserirInimigo(dynamic_cast<Inimigo*>(pEsq));
							pEsq = NULL;
							nIniB++;
							decidido = true;
						}
						else {
							r = rand() % 2 + 1;
						}
					}

				}

			}
			else if (faseMapa[i][j] == '%') { //Obstaculo aleatorio
				bool decidido = false;
				int r = rand() % 2 + 1;

				while (!decidido) {

					if (nObsA >= 3 && nObsB >= 3) { //se o minimo já foi atingido
						r = rand() % 3 + 1; //chance de não ser adicionado nenhum

						if (r == 1) { //Espinho
							Espinho* pEsp = new Espinho(7, G_Vetor2f(50.f, 40.f), G_Vetor2f(425.f + (50.f * j) + 10.f, 425.f + (50.f * i) + 10.f));
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pEsp));
							gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pEsp));
							pEsp = NULL;
							nObsA++;
						}
						else if (r == 2) { //PinoEletrico
							PinoEletrico* pPin = new PinoEletrico(8, G_Vetor2f(20.f, 30.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i + 10.f));
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPin));
							gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pPin));
							pPin = NULL;
							nObsB++;
						}
						decidido = true;
					}
					else {
						if (r == 1 && nObsA < 3) { //Espinho
							Espinho* pEsp = new Espinho(7, G_Vetor2f(50.f, 40.f), G_Vetor2f(425.f + (50.f * j) + 10.f, 425.f + (50.f * i) + 10.f));
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pEsp));
							gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pEsp));
							pEsp = NULL;
							nObsA++;
							decidido = true;
						}
						else if (r == 2 && nObsB < 3) { //PinoEletrico
							PinoEletrico* pPin = new PinoEletrico(8, G_Vetor2f(20.f, 30.f), G_Vetor2f(425.f + 50.f * j, 425.f + 50.f * i + 10.f));
							LEntidades.LEs.inserir(dynamic_cast<Entidade*>(pPin));
							gerenciadorColisao.inserirObstaculo(dynamic_cast<Obstaculo*>(pPin));
							pPin = NULL;
							nObsB++;
							decidido = true;
						}
						else {
							r = rand() % 2 + 1;
						}
					}

				}

			}
		}

	}

}

void Fase_Segunda::executar()
{

	imprimir_se();

	//executar das entidades presentes na lista
	Entidade* aux = NULL;
	int total = LEntidades.LEs.getTotal();
	for (int i = total - 1; i >= 0; i--) {
		aux = LEntidades.LEs.getInfo(i);
		if (aux != NULL) {
			aux->executar();
		}
		aux = NULL;
	}

	//Verifica se foi criado um Projétil
	if (total < LEntidades.LEs.getTotal())
	{
		int total2 = LEntidades.LEs.getTotal();
		for (int j = total; j < total2; j++)
		{
			aux = LEntidades.LEs.getInfo(j);
			if (aux != NULL)
			{
				gerenciadorColisao.inserirProjetil(dynamic_cast<Projetil*>(aux));
				aux->executar();
			}
			aux = NULL;
		}
	}

	total = LEntidades.LEs.getTotal();

	gerenciar_colisoes();


	for (int k = total - 1; k >= 0; k--) {
		aux = LEntidades.LEs.getInfo(k);
		if (aux != NULL) {
			if (aux->getId() == 1) { //jogador1-cavaleiro
				if (!dynamic_cast<Cavaleiro*>(aux)->aindaVivo()) {
					gerenciadorColisao.setJogador1(NULL);
					LEntidades.LEs.excluir(aux);
					nJogadores--;
				}
			}
			else if (aux->getId() == 2) { //jogador2-Escudeiro
				if (!dynamic_cast<Escudeiro*>(aux)->aindaVivo()) {
					gerenciadorColisao.setJogador2(NULL);
					LEntidades.LEs.excluir(aux);
					nJogadores--;
				}
			}
			else if (aux->getId() >= 3 && aux->getId() <= 5) { //Inimigos
				if (!dynamic_cast<Inimigo*>(aux)->aindaVivo()) {
					if (pJogador1->aindaVivo()) {
						if (dynamic_cast<Passaro*>(aux)) {
							pJogador1->operator++(1);
						}
						else if (dynamic_cast<Esqueleto*>(aux)) {
							pJogador1->operator++(3);
						}
						else if (dynamic_cast<Raposa*>(aux)) {
							pJogador1->operator++(10);
						}
					}
					else if (pJogador2->aindaVivo()) {
						if (dynamic_cast<Passaro*>(aux)) {
							pJogador2->operator++(1);
						}
						else if (dynamic_cast<Esqueleto*>(aux)) {
							pJogador2->operator++(3);
						}
						else if (dynamic_cast<Raposa*>(aux)) {
							pJogador2->operator++(10);
							this->setFaseConcluida(true);
						}
					}
					gerenciadorColisao.removerInimigo(dynamic_cast<Inimigo*>(aux));
					LEntidades.LEs.excluir(aux);
				}
			}
			else if (aux->getId() == 8) { //PinoEletrico
				if (dynamic_cast<PinoEletrico*>(aux)->getDesativado()) {
					gerenciadorColisao.removerObstaculo(dynamic_cast<Obstaculo*>(aux));
					LEntidades.LEs.excluir(aux);
				}
			}
			else if (aux->getId() == 9) { //Projetil
				if (dynamic_cast<Projetil*>(aux)->getColidiu()) {
					gerenciadorColisao.removerProjetil(dynamic_cast<Projetil*>(aux));
					LEntidades.LEs.excluir(aux);
				}
			}
		}
		aux = NULL;
	}
}