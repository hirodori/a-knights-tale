#pragma once
#include "Afx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Gerenciador_Grafico.h"

class Gerenciador_Evento
{
private:
	static Gerenciador_Grafico* pGGrafico;
	sf::Event event;
	std::map<char, sf::Keyboard::Key> keyboard;

public:
	Gerenciador_Evento();
	~Gerenciador_Evento();

	static void setGGrafico(Gerenciador_Grafico* pG);

	sf::Event* getEvent();
	bool windowClosed();

	bool keyPressed(char key);

	sf::Vector2i mouseGetPosition();
	bool mouseButtonPressed();
};

