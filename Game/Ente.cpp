#include "Ente.h"

Gerenciador_Grafico* Ente::pGGrafico = NULL;
void Ente::setGGrafico(Gerenciador_Grafico* pG)
{
	if (pG != NULL) {
		pGGrafico = pG;
	}
	else {
		cout << "Ponteiro Gerenciador Grafico vazio." << endl;
	}
}

Ente::Ente(const int i, G_Vetor2f tamanho) :
	id(i), body(tamanho)
{
}

Ente::Ente() :
	id(0), body()
{
}

Ente::~Ente()
{
}

const int Ente::getId() const
{
	return id;
}

Corpo* Ente::getCorpo()
{
	return &this->body;
}

void Ente::imprimir_se()
{
	pGGrafico->draw(&this->body.getDrawable());
}
