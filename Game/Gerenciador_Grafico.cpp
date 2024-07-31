#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() :
	window(sf::VideoMode(800, 600), "AKnightsTale", sf::Style::Close | sf::Style::Titlebar),
	view(sf::Vector2f(0.f, 0.f), sf::Vector2f(800, 600))
{
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
}

sf::RenderWindow& Gerenciador_Grafico::getWindow()
{
	return window;
}

sf::View& Gerenciador_Grafico::getView()
{
	return view;
}

void Gerenciador_Grafico::windowClose()
{
	window.close();
}

bool Gerenciador_Grafico::windowIsOpen()
{
	return window.isOpen();
}

bool Gerenciador_Grafico::pollEvent(sf::Event* event)
{
	return window.pollEvent(*event);
}

void Gerenciador_Grafico::windowDisplay()
{
	window.display();
}

void Gerenciador_Grafico::windowClear()
{
	window.clear();
}

void Gerenciador_Grafico::draw(sf::Drawable* drawable)
{
	if (drawable != NULL) {
		window.draw(*drawable);
	}
}

void Gerenciador_Grafico::setWindowView(sf::View* nView)
{
	if (nView != NULL) {
		window.setView(*nView);
	}
}

void Gerenciador_Grafico::setWindowDefaultView()
{
	window.setView(window.getDefaultView());
}

void Gerenciador_Grafico::setViewCenter(sf::Vector2f posicao)
{
	view.setCenter(posicao);
}
