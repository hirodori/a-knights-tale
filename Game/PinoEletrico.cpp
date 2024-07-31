#include "PinoEletrico.h"

PinoEletrico::PinoEletrico(const int i, G_Vetor2f tamanho, G_Vetor2f pos) :
	Obstaculo(i, tamanho, pos), desativado(false), brilho(0)
{
	body.setTexture("Assets//PinoEletrico.png");
	body.setTextureRect(0, 0, 12, 20);
}

PinoEletrico::PinoEletrico() :
	Obstaculo(), desativado(false), brilho(0)
{
	body.setTexture("Assets//PinoEletrico.png");
	body.setTextureRect(0, 0, 12, 20);
}

PinoEletrico::~PinoEletrico()
{
}

void PinoEletrico::setDesativado(const bool des)
{
	desativado = des;
}

const bool PinoEletrico::getDesativado() const
{
	return desativado;
}

void PinoEletrico::setBrilho(const int b)
{
	brilho = b;
}

const int PinoEletrico::getBrilho() const
{
	return brilho;
}

void PinoEletrico::executar()
{
	imprimir_se();

	brilho++;
	if (brilho == 10) {
		body.setTextureRect(12, 0, 12, 20);
	}
	else if (brilho == 20) {
		body.setTextureRect(0, 0, 12, 20);
	}
	else if (brilho == 30) {
		brilho = 0;
	}

}
