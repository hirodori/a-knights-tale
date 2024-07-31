#include "Gerenciador_Evento.h"

Gerenciador_Grafico* Gerenciador_Evento::pGGrafico = NULL;
void Gerenciador_Evento::setGGrafico(Gerenciador_Grafico* pG)
{
	if (pG != NULL) {
		pGGrafico = pG;
	}
	else {
		cout << "Ponteiro Gerenciador_Grafico vazio." << endl;
	}
}

Gerenciador_Evento::Gerenciador_Evento():
	event()
{
	keyboard = {
		{ 'A',sf::Keyboard::Key::A }, { 'B',sf::Keyboard::Key::B }, { 'C',sf::Keyboard::Key::C },
		{ 'D',sf::Keyboard::Key::D }, { 'E',sf::Keyboard::Key::E }, { 'F',sf::Keyboard::Key::F },
		{ 'G',sf::Keyboard::Key::G }, { 'H',sf::Keyboard::Key::H }, { 'I',sf::Keyboard::Key::I },
		{ 'J',sf::Keyboard::Key::J }, { 'K',sf::Keyboard::Key::K }, { 'L',sf::Keyboard::Key::L },
		{ 'M',sf::Keyboard::Key::M }, { 'N',sf::Keyboard::Key::N }, { 'O',sf::Keyboard::Key::O },
		{ 'P',sf::Keyboard::Key::P }, { 'Q',sf::Keyboard::Key::Q }, { 'R',sf::Keyboard::Key::R },
		{ 'S',sf::Keyboard::Key::S }, { 'T',sf::Keyboard::Key::T }, { 'U',sf::Keyboard::Key::U },
		{ 'V',sf::Keyboard::Key::V }, { 'W',sf::Keyboard::Key::W }, { 'X',sf::Keyboard::Key::X },
		{ 'Y',sf::Keyboard::Key::Y }, { 'Z',sf::Keyboard::Key::Z }
	};

}

Gerenciador_Evento::~Gerenciador_Evento()
{
}

sf::Event* Gerenciador_Evento::getEvent()
{
	return &event;
}

bool Gerenciador_Evento::windowClosed()
{
	if (event.type == sf::Event::Closed) {
		return true;
	}
	return false;
}

bool Gerenciador_Evento::keyPressed(char key)
{
	if (sf::Keyboard::isKeyPressed(keyboard.at(key))) {
		return true;
	}
	return false;
}

sf::Vector2i Gerenciador_Evento::mouseGetPosition()
{
	return sf::Mouse::getPosition(pGGrafico->getWindow());
}

bool Gerenciador_Evento::mouseButtonPressed()
{
	if (event.type == sf::Event::MouseButtonPressed) {
		return true;
	}
	return false;
}
