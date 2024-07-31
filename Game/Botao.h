#pragma once
#include "Afx.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Evento.h"

class Botao
{
private:
	static Gerenciador_Evento* pGEvento;
	sf::RectangleShape button;

public:
	Botao(float sizeX, float sizeY);
	Botao();
	~Botao();

	static void setGEvento(Gerenciador_Evento* pE);

	void setPosition(float x, float y);
	bool mouseOnButton();
};

