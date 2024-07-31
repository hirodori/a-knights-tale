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
 //Variável noAr e métodos setNoAr e getNoAr
-> Modificações em Gerenciador_Colisoes
-> Personagem
 //Função virtual void pular e int delayPulo
 //setDelayPulo
* 
----------------------------
-> Fase_Primeira
	//limpei os comentarios na construtora
	//prototipo de conferir quem está vivo ou não
	//prototipo de aleatoriedade
	//mapa de teste de aleatoriedade
-> Fase
	//inclui PinoEletrico
-> Obstaculo
	//executar agr é virtual void
-> PinoEletrico
	//int brilho
	//métodos (q não serão usados) do int brilho
	//TextureRect do Pino
	//Possivelmente necessidade de mudar o valor dos contadores? Para mim funciona, não sei no seu
============================
-> Fase_Primeira
	- Mapa ~ atributo string faseMapa[]
	- método inicializarMapa()
-> Sugestão
	//padrão de escrita: virtuais normais ou puras por ultimo na lista de métodos
-> Dúvida
	//como o jogador recebe sua pontuacao?
	//o projetil lançado por ele consegue acesso a isso ou quando a fase faz a checagem de vivos ela distribui?
	//jogador eh deletado pela fase ou jogo?
	//se pelo jogo-> como fica a lista de entidade?
	//se pela fase-> o jogo deve checar após o executar da fase, se o jogador existe e atualizar seu bool
-> Gerenciador_Colisoes
	//gerenciador_colisoes -> um método que destroi tudo dele para ser chamado na destrutora de fase_primeira
-> Pontuacao (& Jogador)
	//OBS: atributo static não é aceito.... como fazer a pontuacao então?
	//um atributo de jogo que eh passado como static para o Jogador (ou para os dois separadamente)
	//uma classe agregada?
	//tipo, pontuacao eh característica de quem? Do jogo ou do jogador?
=== Código (& UML)
-> Cavaleiro
- criar uma função que recebe os comandos (ao inves de move) de movimento e ataque
-> Gerenciador_Colisoes
- arrumar o determinaColisao() que está identico ao código do qual foi referanciado
- APAGAR o lixo de deixei após a substituição
-> Fase_Primeira && Fase_Segunda
- após chamar gerenciar_colisoes checar quem está vivo e destruir quem morreu
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