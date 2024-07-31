#pragma once
#include "Afx.h"

template<class TL>
class Lista
{
private:

	template<class TE>
	class Elemento
	{
	private:
		Elemento<TE>* pProximo;
		TE* pInfo;

	public:
		Elemento();
		~Elemento();

		void setProx(Elemento<TE>* pElProx);
		Elemento<TE>* getProx();
		void setInfo(TE* info);
		TE* getInfo();
	};

	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	unsigned int total;

public:
	Lista();
	~Lista();

	int getTotal();
	void inserir(TL* pInfo);
	TL* getInfo(int pos);
	void excluir(TL* pInfo);
};

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>::Elemento()
{
	pProximo = nullptr;
	pInfo = nullptr;
}

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>::~Elemento()
{
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pElProx)
{
	this->pProximo = pElProx;
}

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>* Lista<TL>::Elemento<TE>::getProx()
{
	return pProximo;
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setInfo(TE* info)
{
	this->pInfo = info;
}

template<class TL>
template<class TE>
TE* Lista<TL>::Elemento<TE>::getInfo()
{
	return this->pInfo;
}

template<class TL>
Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	total = 0;
}

template<class TL>
Lista<TL>::~Lista()
{
}

template<class TL>
int Lista<TL>::getTotal()
{
	return total;
}

template<class TL>
void Lista<TL>::inserir(TL* pInfo)
{
	if (pInfo != nullptr) {
		if (pPrimeiro == nullptr) {
			pPrimeiro = new Elemento<TL>();
			pPrimeiro->setInfo(pInfo);
			pPrimeiro->setProx(nullptr);
			pUltimo = pPrimeiro;
		}
		else {
			Elemento<TL>* aux = new Elemento<TL>();
			aux->setInfo(pInfo);
			pUltimo->setProx(aux);
			aux->setProx(nullptr);
			pUltimo = aux;
		}
		total++;
	}
}

template<class TL>
TL* Lista<TL>::getInfo(int pos)
{
	Elemento<TL>* aux = pPrimeiro;
	if (pos == 0) {
		return aux->getInfo();
	}
	else {
		for (int i = 0; i < pos; i++) {
			aux = aux->getProx();
		}
		return aux->getInfo();
	}
}

template<class TL>
void Lista<TL>::excluir(TL* pInfo)
{
	if (pInfo != nullptr) {
		Elemento<TL>* aux = pPrimeiro;
		Elemento<TL>* bAux = nullptr;
		while (aux->getInfo() != pInfo) {
			bAux = aux;
			aux = aux->getProx();
		}
		if (aux == pPrimeiro) {
			pPrimeiro = aux->getProx();
		}
		else if (aux == pUltimo) {
			bAux->setProx(nullptr);
			pUltimo = bAux;
		}
		else {
			bAux->setProx(aux->getProx());
		}
		delete aux;
		total--;
	}
}