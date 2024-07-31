#pragma once
#include "Afx.h"
#include "G_Vetor2.h"
#include "Corpo.h"
#include "Gerenciador_Grafico.h"

class Ente
{
protected:
	const int id;
	static Gerenciador_Grafico* pGGrafico;
	Corpo body;

public:

	Ente(const int i, G_Vetor2f tamanho);
	Ente();
	~Ente();

	static void setGGrafico(Gerenciador_Grafico* pG);

	const int getId() const;

	Corpo* getCorpo();

	virtual void imprimir_se();
	virtual void executar() = 0;
};