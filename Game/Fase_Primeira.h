#pragma once
#include "Fase.h"

class Fase_Primeira :
    public Fase
{
private:

    G_Vetor2f checkpoint;

    string faseMapa[23] =
    {
        "##############################",
        "#                            #",
        "#                            #",
        "#                            #",
        "# c d    %    ?    %         #",
        "#######################      #",
        "#                            #",
        "#                            #",
        "# ?  ?   ?            %     %#",
        "#############        #########",
        "#                            #",
        "#                            #",
        "#               %    ?    ?  #",
        "#  ?   #      ################",
        "########                     #",
        "#                            #",
        "#                           &#",
        "#                           ##",
        "#                          ###",
        "#  ?            %         ####",
        "######## %   ######      #####",
        "##########^^^^^^^^^^^^^^######",
        "##############################"
    };

public:
    Fase_Primeira(const int i, Cavaleiro* pJ1, Escudeiro* pJ2, G_Vetor2f tamanhoBack);
    Fase_Primeira();
    ~Fase_Primeira();

    void inicializarMapa();
    void executar();
};
