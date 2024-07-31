#include "Projetil.h"

Projetil::Projetil(const int i, G_Vetor2f tamanho, G_Vetor2f pos, const int donoId, const bool fR) :
	Entidade(i, tamanho, pos), idDono(donoId), faceRight(fR), colidiu(false)
{
	if (idDono == 1)
	{
		body.setTexture("Assets//Espada.png");
		body.setTextureRect(0, 0, 12, 6);
	}
	else if (idDono == 4)
	{
		body.setTexture("Assets//EsqueletoOsso.png");
	}
}

Projetil::Projetil() :
	Entidade(), idDono(0), faceRight(true), colidiu(false)
{
	body.setTexture("Assets//EsqueletoOsso.png");
}

Projetil::~Projetil()
{
}

void Projetil::executar()
{
	this->move();
	this->imprimir_se();
}

void Projetil::move()
{
	if (idDono == 1)
	{
		if (faceRight)
		{
			this->body.move(1.0f, 0.f);
			body.setTextureRect(0, 0, 12, 6);
		}
		else
		{
			this->body.move(-1.0f, 0.f);
			body.setTextureRect(12, 0, 12, 6);
		}
	}
	else if (idDono == 4)
	{
		if (faceRight)
		{
			this->body.move(1.0f, 0.f);
		}
		else
		{
			this->body.move(-1.0f, 0.f);
		}
	}
}

const int Projetil::getIdDono()
{
	return idDono;
}

void Projetil::setColidiu(bool C)
{
	colidiu = C;
}

const bool Projetil::getColidiu() const
{
	return colidiu;
}

void Projetil::setFaceRight(const bool fc)
{
	faceRight = fc;
}

const bool Projetil::getFaceRight() const
{
	return faceRight;
}
