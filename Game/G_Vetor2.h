#pragma once
#include <SFML/System/Vector2.hpp>

template<class T>
class G_Vetor2
{
private:
	T x;
	T y;

public:
	G_Vetor2<T>(T _x, T _y);
	G_Vetor2<T>();
	~G_Vetor2<T>();

	T getX();
	T getY();

	G_Vetor2<T> conversaoG_Vetor2(sf::Vector2<T> vet);
	sf::Vector2<T> vetorSFML();

	void criar(T _x, T _y);
};

typedef G_Vetor2<float> G_Vetor2f;
typedef G_Vetor2<int> G_Vetor2i;
typedef G_Vetor2<unsigned int> G_Vetor2u;

template<class T>
inline G_Vetor2<T>::G_Vetor2(T _x, T _y):
	x(_x), y(_y)
{
}

template<class T>
inline G_Vetor2<T>::G_Vetor2():
	x(0), y(0)
{
}

template<class T>
inline G_Vetor2<T>::~G_Vetor2()
{
}

template<class T>
inline T G_Vetor2<T>::getX()
{
	return this->x;
}

template<class T>
inline T G_Vetor2<T>::getY()
{
	return this->y;
}

template<class T>
inline G_Vetor2<T> G_Vetor2<T>::conversaoG_Vetor2(sf::Vector2<T> vet)
{
	return G_Vetor2<T>(vet.x, vet.y);
}

template<class T>
inline sf::Vector2<T> G_Vetor2<T>::vetorSFML()
{
	return sf::Vector2<T>(this->x, this->y);
}

template<class T>
inline void G_Vetor2<T>::criar(T _x, T _y)
{
	this->x = _x;
	this->y = _y;
}

