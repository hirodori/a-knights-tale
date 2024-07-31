#pragma once
#include "Afx.h"
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico
{
private:
	sf::RenderWindow window;
	sf::View view;

public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	sf::RenderWindow& getWindow();
	sf::View& getView();

	void windowClose();
	bool windowIsOpen();
	bool pollEvent(sf::Event* event = NULL);
	void windowDisplay();
	void windowClear();
	void draw(sf::Drawable* drawable = NULL);

	void setWindowView(sf::View* nView);
	void setWindowDefaultView();
	void setViewCenter(sf::Vector2f posicao);
};

