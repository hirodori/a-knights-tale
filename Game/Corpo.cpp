#include "Corpo.h"

Corpo::Corpo(G_Vetor2f tamanho):
	body(tamanho.vetorSFML()), text(), rect()
{
}

Corpo::Corpo(sf::Vector2f tamanho):
	body(tamanho), text(), rect()
{
}

Corpo::Corpo() :
	body(), text(), rect()
{
}

Corpo::~Corpo()
{
}

void Corpo::setSize(G_Vetor2f size)
{
	body.setSize(size.vetorSFML());
}

G_Vetor2f Corpo::getSize()
{
	return G_Vetor2f().conversaoG_Vetor2(body.getSize());
}

void Corpo::setTexture(const string nArquivo)
{
	if (!text.loadFromFile(nArquivo)) {
		cout << "ERRO TEXTURA " << nArquivo << endl;
	}
	this->body.setTexture(&text);
}

void Corpo::setTextureRect(int left, int top, int largura, int altura)
{
	rect.left = left;
	rect.top = top;
	rect.width = largura;
	rect.height = altura;

	body.setTextureRect(rect);
}

void Corpo::setPosition(G_Vetor2f posicao)
{
	body.setPosition(posicao.vetorSFML());
}

G_Vetor2f Corpo::getPosition()
{
	return G_Vetor2f().conversaoG_Vetor2(body.getPosition());
}

void Corpo::setCenterOrigin(G_Vetor2f tamanho)
{
	body.setOrigin(tamanho.getX() / 2, tamanho.getY() / 2);
}

G_Vetor2f Corpo::getCenterOrigin()
{
	return G_Vetor2f().conversaoG_Vetor2(body.getOrigin());
}

void Corpo::move(float x, float y)
{
	body.move(x, y);
}

void Corpo::move(G_Vetor2f mov)
{
	body.move(mov.vetorSFML());
}

sf::Drawable& Corpo::getDrawable()
{
	return dynamic_cast<sf::Drawable&>(body);
}
