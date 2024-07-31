#include "Personagem.h"

float* Personagem::pGravidade = NULL;
void Personagem::setGravidade(float* gravidade)
{
	
	if (gravidade != NULL) {
		pGravidade = gravidade;
	}
	else {
		cout << "Ponteiro Gravidade vazio" << endl;
	}
}

Personagem::Personagem(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int nv) :
	Entidade(i, tamanho, pos), num_vidas(nv), vivo(true), faceRight(true), delayDano(0), noAr(false), delayPulo(0)
{
	if (nv > 0) {
		vivo = true;
	}
	else {
		vivo = false;
	}
}

Personagem::Personagem():
	Entidade(), num_vidas(0), vivo(true), faceRight(true), delayDano(0), noAr(false), delayPulo(0)
{
}

Personagem::~Personagem()
{
}

void Personagem::setNVidas(const int nv)
{
	num_vidas = nv;
	if (nv > 0) {
		vivo = true;
	}
	else {
		vivo = false;
	}
}

const int Personagem::getNVidas() const
{
	return num_vidas;
}

const bool Personagem::aindaVivo() const
{
	return vivo;
}

void Personagem::setFaceRight(const bool fc)
{
	faceRight = fc;
}

const bool Personagem::getFaceRight() const
{
	return faceRight;
}

void Personagem::setDelayDano(const int dd)
{
	delayDano = dd;
}

const int Personagem::getDelayDano() const
{
	return delayDano;
}

void Personagem::setNoAr(const bool na)
{
	noAr = na;
}

const bool Personagem::getNoAr() const
{
	return noAr;
}

void Personagem::setDelayPulo(const int dp)
{
	delayPulo = dp;
}

const int Personagem::getDelayPulo() const
{
	return delayPulo;
}

void Personagem::operator--()
{
	num_vidas -= 1;
	if (num_vidas <= 0) {
		vivo = false;
	}
}

void Personagem::executar()
{
	this->move();
	this->imprimir_se();
	if (delayDano >= 1 && delayDano < 500) {
		delayDano++;
	}
	else if (delayDano >= 500) {
		delayDano = 0;
	}
}

void Personagem::pular()
{
	if (delayPulo >= 1 && delayPulo < 200) {
		this->body.move(0.f, -0.9f);
		delayPulo++;
	}
	else if (delayPulo >= 200) {
		delayPulo = 0;
	}
}
