#include "Botao.h"

Gerenciador_Evento* Botao::pGEvento = NULL;
void Botao::setGEvento(Gerenciador_Evento* pE)
{
	if (pE != NULL) {
		pGEvento = pE;
	}
	else {
		cout << "Ponteiro Gerenciador_Evento vazio." << endl;
	}

}

Botao::Botao(float sizeX, float sizeY)
{
	button.setSize(sf::Vector2f(sizeX, sizeY));
}

Botao::Botao()
{
	button.setSize(sf::Vector2f(50.f, 50.f));
}

Botao::~Botao()
{
}

void Botao::setPosition(float x, float y)
{
	button.setPosition(x, y);
}

bool Botao::mouseOnButton()
{
	float xMouse = (float)pGEvento->mouseGetPosition().x;
	float yMouse = (float)pGEvento->mouseGetPosition().y;

	float xButton = button.getPosition().x;
	float yButton = button.getPosition().y;

	float xMaxB = xButton + button.getLocalBounds().width;
	float yMaxB = yButton + button.getLocalBounds().height;

	if (((xMouse > xButton) && (xMouse < xMaxB)) && ((yMouse > yButton) && (yMouse < yMaxB))) {
		return true;
	}
	else {
		return false;
	}
}
