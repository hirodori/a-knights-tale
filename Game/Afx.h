#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
using namespace std;

#include <time.h>

/*


==============================================
-> Personagem
 //Vari�vel noAr e m�todos setNoAr e getNoAr
-> Modifica��es em Gerenciador_Colisoes
-> Personagem
 //Fun��o virtual void pular e int delayPulo
 //setDelayPulo
* 
----------------------------
-> Fase_Primeira
	//limpei os comentarios na construtora
	//prototipo de conferir quem est� vivo ou n�o
	//prototipo de aleatoriedade
	//mapa de teste de aleatoriedade
-> Fase
	//inclui PinoEletrico
-> Obstaculo
	//executar agr � virtual void
-> PinoEletrico
	//int brilho
	//m�todos (q n�o ser�o usados) do int brilho
	//TextureRect do Pino
	//Possivelmente necessidade de mudar o valor dos contadores? Para mim funciona, n�o sei no seu
============================
-> Fase_Primeira
	- Mapa ~ atributo string faseMapa[]
	- m�todo inicializarMapa()
-> Sugest�o
	//padr�o de escrita: virtuais normais ou puras por ultimo na lista de m�todos
-> D�vida
	//como o jogador recebe sua pontuacao?
	//o projetil lan�ado por ele consegue acesso a isso ou quando a fase faz a checagem de vivos ela distribui?
	//jogador eh deletado pela fase ou jogo?
	//se pelo jogo-> como fica a lista de entidade?
	//se pela fase-> o jogo deve checar ap�s o executar da fase, se o jogador existe e atualizar seu bool
-> Gerenciador_Colisoes
	//gerenciador_colisoes -> um m�todo que destroi tudo dele para ser chamado na destrutora de fase_primeira
-> Pontuacao (& Jogador)
	//OBS: atributo static n�o � aceito.... como fazer a pontuacao ent�o?
	//um atributo de jogo que eh passado como static para o Jogador (ou para os dois separadamente)
	//uma classe agregada?
	//tipo, pontuacao eh caracter�stica de quem? Do jogo ou do jogador?
=== C�digo (& UML)
-> Cavaleiro
- criar uma fun��o que recebe os comandos (ao inves de move) de movimento e ataque
-> Gerenciador_Colisoes
- arrumar o determinaColisao() que est� identico ao c�digo do qual foi referanciado
- APAGAR o lixo de deixei ap�s a substitui��o
-> Fase_Primeira && Fase_Segunda
- ap�s chamar gerenciar_colisoes checar quem est� vivo e destruir quem morreu
*/
/*
		int remove = 0;
		cont = LEntidades.LEs.getTotal();
		for (int j = (cont - 1); j >= 0; j--) {
			aux = LEntidades.LEs.getInfo(j);
			if (aux != NULL) {
				if ((dynamic_cast<Inimigo*>(aux)) && (remove == 0)) {
					gerenciadorColisao.removerInimigo(dynamic_cast<Inimigo*>(aux));
					LEntidades.LEs.excluir(aux);
					remove++;
				}
			}
			aux = NULL;
		}
*/