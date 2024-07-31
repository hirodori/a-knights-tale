#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Cavaleiro* pJogador1, Escudeiro* pJogador2) :
	pJogador1(pJogador1), pJogador2(pJogador2)
{
}

Gerenciador_Colisoes::Gerenciador_Colisoes() :
	pJogador1(NULL), pJogador2(NULL)
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	pJogador1 = nullptr;
	pJogador2 = nullptr;
}

void Gerenciador_Colisoes::setJogador1(Cavaleiro* pJogador1)
{
	this->pJogador1 = pJogador1;
}

void Gerenciador_Colisoes::setJogador2(Escudeiro* pJogador2)
{
	this->pJogador2 = pJogador2;
}

void Gerenciador_Colisoes::inserirInimigo(Inimigo* pIni)
{
	if (pIni != NULL) {
		LIs.push_back(pIni);
	}
	else {
		cout << "Ponteiro Inimigo vazio." << endl;
	}
}

void Gerenciador_Colisoes::inserirObstaculo(Obstaculo* pObs)
{
	if (pObs != NULL) {
		LOs.push_back(pObs);
	}
	else {
		cout << "Ponteiro Obstaculo vazio." << endl;
	}
}

void Gerenciador_Colisoes::inserirProjetil(Projetil* pPro)
{
	if (pPro != NULL) {
		LPs.push_back(pPro);
	}
	else {
		cout << "Ponteiro Projetil vazio." << endl;
	}
}

void Gerenciador_Colisoes::removerInimigo(Inimigo* pIni)
{
	if (pIni != NULL) {
		vector<Inimigo*>::iterator iti;
		iti = LIs.begin();

		while ((*iti != pIni) && (iti != LIs.end())) {
			++iti;
		}
		if (iti != LIs.end()) {
			LIs.erase(iti);
		}		

	}
	else {
		cout << "Ponteiro Inimigo vazio." << endl;
	}
}

void Gerenciador_Colisoes::removerObstaculo(Obstaculo* pObs)
{
	if (pObs != NULL) {
		list<Obstaculo*>::iterator ito;
		ito = LOs.begin();

		while ((*ito != pObs) && (ito != LOs.end())) {
			++ito;
		}
		if (ito != LOs.end()) {
			LOs.erase(ito);
		}

	}
	else {
		cout << "Ponteiro Obstaculo vazio." << endl;
	}

}

void Gerenciador_Colisoes::removerProjetil(Projetil* pPro)
{
	if (pPro != NULL) {
		vector<Projetil*>::iterator itp;
		itp = LPs.begin();

		while ((*itp != pPro) && (itp != LPs.end())) {
			++itp;
		}
		if (itp != LPs.end()) {
			LPs.erase(itp);
		}

	}
	else {
		cout << "Ponteiro Projetil vazio." << endl;
	}
}

bool Gerenciador_Colisoes::checaColisao(Entidade* primeiro, Entidade* segundo)
{
	G_Vetor2f otherPosition = primeiro->getCorpo()->getPosition();
	G_Vetor2f otherHalfSize = G_Vetor2f(primeiro->getCorpo()->getSize().getX() / 2, primeiro->getCorpo()->getSize().getY() / 2);
	G_Vetor2f thisPosition = segundo->getCorpo()->getPosition();
	G_Vetor2f thisHalfSize = G_Vetor2f(segundo->getCorpo()->getSize().getX() / 2, segundo->getCorpo()->getSize().getY() / 2);

	float deltaX = otherPosition.getX() - thisPosition.getX();
	float deltaY = otherPosition.getY() - thisPosition.getY();
	float intersectX = abs(deltaX) - (otherHalfSize.getX() + thisHalfSize.getX());
	float intersectY = abs(deltaY) - (otherHalfSize.getY() + thisHalfSize.getY());

	if (intersectX < 0.0f && intersectY < 0.0f) {
		return true;
	}
	return false;
}

bool Gerenciador_Colisoes::determinaColisao(Entidade* primeiro, Entidade* segundo, float mov)
{
	G_Vetor2f otherPosition = primeiro->getCorpo()->getPosition();
	G_Vetor2f otherHalfSize = G_Vetor2f(primeiro->getCorpo()->getSize().getX() / 2, primeiro->getCorpo()->getSize().getY() / 2);
	G_Vetor2f thisPosition = segundo->getCorpo()->getPosition();
	G_Vetor2f thisHalfSize = G_Vetor2f(segundo->getCorpo()->getSize().getX() / 2, segundo->getCorpo()->getSize().getY() / 2);

	float deltaX = otherPosition.getX() - thisPosition.getX();
	float deltaY = otherPosition.getY() - thisPosition.getY();
	float intersectX = abs(deltaX) - (otherHalfSize.getX() + thisHalfSize.getX());
	float intersectY = abs(deltaY) - (otherHalfSize.getY() + thisHalfSize.getY());

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		mov = std::min(std::max(mov, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f) //ESQUERDA PARA DIREITA
			{
				segundo->move(intersectX * (1.0f - mov), 0.0f); //OBSTÁCULO ou INIMIGO
				primeiro->move(-intersectX * mov, 0.0f); //PLAYER ou INIMIGO
			}
			else //DIREITA PARA ESQUERDA
			{
				segundo->move(-intersectX * (1.0f - mov), 0.0f); //OBSTÁCULO ou INIMIGO
				primeiro->move(intersectX * mov, 0.0f); //PLAYER ou INIMIGO
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				segundo->move(0.0f, intersectY * (1.0f - mov));
				primeiro->move(0.0f, -intersectY * mov);
			}
			else
			{
				segundo->move(0.0f, -intersectY * (1.0f - mov));
				primeiro->move(0.0f, intersectY * mov);

				//Primeiro bate por baixo

				if (dynamic_cast<Personagem*>(primeiro)) {
					dynamic_cast<Personagem*>(primeiro)->setNoAr(false);
				}
			}
		}

		return true;
	}

	return false;
}

void Gerenciador_Colisoes::executar()
{	
	
	list<Obstaculo*>::iterator ito;
	vector<Inimigo*>::iterator iti;
	vector<Projetil*>::iterator itp;

	Obstaculo* oAux = NULL;
	Inimigo* iAux = NULL;
	Projetil* pAux = NULL;

	float deltaX = 0;
	float deltaY = 0;

	if (pJogador1 != NULL) {
		dynamic_cast<Personagem*>(pJogador1)->setNoAr(true);
	}
	if (pJogador2 != NULL) {
		dynamic_cast<Personagem*>(pJogador2)->setNoAr(true);
	}

	//Colisão dos Inimigos
	for (iti = LIs.begin(); iti != LIs.end(); iti++) {
		iAux = *iti;

		if (iAux != NULL) {
			//Colisão entre Jogador1 e Inimigos
			if (pJogador1 != NULL) {
				deltaX = pJogador1->getCorpo()->getPosition().getX() - iAux->getCorpo()->getPosition().getX();
				deltaY = pJogador1->getCorpo()->getPosition().getY() - iAux->getCorpo()->getPosition().getY();
				if ((deltaX <= 90.f && deltaX >= -90.f) && (deltaY <= 90.f && deltaY >= -90.f)) {
					if (determinaColisao(dynamic_cast<Entidade*>(pJogador1), dynamic_cast<Entidade*>(iAux), 0.8f) && pJogador1->getDelayDano() == 0) {
						pJogador1->setDelayDano(1);
						pJogador1->operator--();
					}
				}
			}

			//Colisão entre Jogador2 e Inimigos
			if (pJogador2 != NULL) {
				deltaX = pJogador2->getCorpo()->getPosition().getX() - iAux->getCorpo()->getPosition().getX();
				deltaY = pJogador2->getCorpo()->getPosition().getY() - iAux->getCorpo()->getPosition().getY();

				if ((deltaX <= 90.f && deltaX >= -90.f) && (deltaY <= 90.f && deltaY >= -90.f)) {
					if (determinaColisao(dynamic_cast<Entidade*>(pJogador2), dynamic_cast<Entidade*>(iAux), 0.2f) && pJogador2->getDelayDano() == 0) {
						if (pJogador2->getFaceRight() && !(deltaX <= 0.f)) {
							pJogador2->setDelayDano(1);
							pJogador2->operator--();
						}
						else if (!pJogador2->getFaceRight() && !(deltaX > 0.f)) {
							pJogador2->setDelayDano(1);
							pJogador2->operator--();
						}
					}
				}
			}
		}
		iAux = NULL;
	}

	//Colisão dos Projéteis
	for (itp = LPs.begin(); itp != LPs.end(); itp++) {
		pAux = *itp;

		if (pAux != NULL) {
			if (pAux->getIdDono() == 4)
			{
				//Colisão entre Jogador1 e Projéteis
				if (pJogador1 != NULL) {
					deltaX = pJogador1->getCorpo()->getPosition().getX() - pAux->getCorpo()->getPosition().getX();
					deltaY = pJogador1->getCorpo()->getPosition().getY() - pAux->getCorpo()->getPosition().getY();

					if ((deltaX <= 60.f && deltaX >= -60.f) && (deltaY <= 60.f && deltaY >= -60.f)) {
						if (determinaColisao(dynamic_cast<Entidade*>(pJogador1), dynamic_cast<Entidade*>(pAux), 0.f)) {
							pAux->setColidiu(true);
							pJogador1->operator--();
						}
					}
				}

				//Colisão entre Jogador2 e Projéteis
				if (pJogador2 != NULL) {
					deltaX = pJogador2->getCorpo()->getPosition().getX() - pAux->getCorpo()->getPosition().getX();
					deltaY = pJogador2->getCorpo()->getPosition().getY() - pAux->getCorpo()->getPosition().getY();

					if ((deltaX <= 60.f && deltaX >= -60.f) && (deltaY <= 60.f && deltaY >= -60.f)) {
						if (determinaColisao(dynamic_cast<Entidade*>(pJogador2), dynamic_cast<Entidade*>(pAux), 0.f)) {
							if (pJogador2->getFaceRight() && !(deltaX <= 0.f)) {
								pJogador2->operator--();
							}
							else if (!pJogador2->getFaceRight() && !(deltaX > 0.f)) {
								pJogador2->operator--();
							}
							pAux->setColidiu(true);
						}
					}
				}
			}

			//Colisão entre Inimigos e Projéteis
			if (pAux->getIdDono() == 1)
			{
				for (iti = LIs.begin(); iti != LIs.end(); iti++) {
					iAux = *iti;

					if (iAux != NULL) {
						deltaX = iAux->getCorpo()->getPosition().getX() - pAux->getCorpo()->getPosition().getX();
						deltaY = iAux->getCorpo()->getPosition().getY() - pAux->getCorpo()->getPosition().getY();

						if ((deltaX <= 80.f && deltaX >= -80.f) && (deltaY <= 80.f && deltaY >= -80.f)) {
							if (determinaColisao(dynamic_cast<Entidade*>(iAux), dynamic_cast<Entidade*>(pAux), 0.f)) {
								pAux->setColidiu(true);
								iAux->operator--();
							}
						}
					}
					iAux = NULL;
				}
			}
		}
		pAux = NULL;
	}

	for(ito = LOs.begin(); ito != LOs.end(); ito++) {
		oAux = *ito;

		if (oAux != NULL) {
			if (pJogador1 != NULL) {
				//Colisão entre Jogador1 e Obstáculos
				deltaX = pJogador1->getCorpo()->getPosition().getX() - oAux->getCorpo()->getPosition().getX();
				deltaY = pJogador1->getCorpo()->getPosition().getY() - oAux->getCorpo()->getPosition().getY();

				if ((deltaX <= 100.f && deltaX >= -100.f) && (deltaY <= 100.f && deltaY >= -100.f)) {

					if (determinaColisao(dynamic_cast<Entidade*>(pJogador1), dynamic_cast<Entidade*>(oAux), 1.f)) {
						if (dynamic_cast<Espinho*>(oAux) && pJogador1->getDelayDano() == 0) {
							pJogador1->setDelayDano(1);
							pJogador1->operator--();
						}
						else if (dynamic_cast<PinoEletrico*>(oAux)) {
							while (pJogador1->getNVidas() > 0)
							{
								pJogador1->operator--();
							}
							dynamic_cast<PinoEletrico*>(oAux)->setDesativado(true);
						}
					}

				}
			}

			//Colisão entre Jogador2 e Obstáculos
			if (pJogador2 != NULL) {
				deltaX = pJogador2->getCorpo()->getPosition().getX() - oAux->getCorpo()->getPosition().getX();
				deltaY = pJogador2->getCorpo()->getPosition().getY() - oAux->getCorpo()->getPosition().getY();

				if ((deltaX <= 100.f && deltaX >= -100.f) && (deltaY <= 100.f && deltaY >= -100.f)) {

					if (determinaColisao(dynamic_cast<Entidade*>(pJogador2), dynamic_cast<Entidade*>(oAux), 1.f)) {
						if (dynamic_cast<Espinho*>(oAux) && pJogador2->getDelayDano() == 0) {
							pJogador2->setDelayDano(1);
							pJogador2->operator--();
						}
						else if (dynamic_cast<PinoEletrico*>(oAux)) {
							while (pJogador2->getNVidas() > 0)
							{
								pJogador2->operator--();
							}
							dynamic_cast<PinoEletrico*>(oAux)->setDesativado(true);
						}
					}
				}
			}

			//Colisão entre Inimigos e Obstáculos
			if (!(dynamic_cast<PinoEletrico*>(oAux))) {
				for (iti = LIs.begin(); iti != LIs.end(); iti++) {
					iAux = *iti;

					if (iAux != NULL) {
						deltaX = iAux->getCorpo()->getPosition().getX() - oAux->getCorpo()->getPosition().getX();
						deltaY = iAux->getCorpo()->getPosition().getY() - oAux->getCorpo()->getPosition().getY();

						if ((deltaX <= 80.f && deltaX >= -80.f) && (deltaY <= 80.f && deltaY >= -80.f)) {
							if (determinaColisao(dynamic_cast<Entidade*>(iAux), dynamic_cast<Entidade*>(oAux), 1.f)) {
								if (dynamic_cast<Espinho*>(oAux) && iAux->getDelayDano() == 0) {
									if (pJogador2 != NULL) {
										if (checaColisao(dynamic_cast<Entidade*>(pJogador2), dynamic_cast<Entidade*>(iAux))) {
											iAux->setDelayDano(1);
											iAux->operator--();
										}
									}
								}
							}
						}
					}

					iAux = NULL;
				}

				//Colisão entre Projeteis e Obstaculos
				if (!(dynamic_cast<Espinho*>(oAux))) {
					for (itp = LPs.begin(); itp != LPs.end(); itp++) {
						pAux = *itp;

						if (pAux != NULL) {
							deltaX = pAux->getCorpo()->getPosition().getX() - oAux->getCorpo()->getPosition().getX();
							deltaY = pAux->getCorpo()->getPosition().getY() - oAux->getCorpo()->getPosition().getY();

							if ((deltaX <= 50.f && deltaX >= -50.f) && (deltaY <= 50.f && deltaY >= -50.f)) {
								if (determinaColisao(dynamic_cast<Entidade*>(pAux), dynamic_cast<Entidade*>(oAux), 1.f)) {
									pAux->setColidiu(true);
								}
							}
						}

						pAux = NULL;
					}
				}
			}
		}
		oAux = NULL;
	}

}
