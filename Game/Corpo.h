#pragma once
#include "Afx.h"
#include "G_Vetor2.h"
#include <SFML/Graphics.hpp>

class Corpo
{
private:
	sf::RectangleShape body;
	sf::Texture text;
	sf::IntRect rect;

public:
	Corpo(G_Vetor2f tamanho);
	Corpo(sf::Vector2f tamanho);
	Corpo();
	~Corpo();

    void setSize(G_Vetor2f size);
    G_Vetor2f getSize();

	void setTexture(const string nArquivo);
	void setTextureRect(int left, int top, int largura, int altura);

	void setPosition(G_Vetor2f posicao);
	G_Vetor2f getPosition();
	void setCenterOrigin(G_Vetor2f posicao);
	G_Vetor2f getCenterOrigin();

	void move(float x, float y);
	void move(G_Vetor2f mov);

	sf::Drawable& getDrawable();
	
};

