#include <iostream>
#include <vector>
#include <cstdlib>
#include "Liga.hpp"
#include "Time.hpp"
#include "Ano.hpp"
#include "menu.hpp"

int main(int argc, char *argv[]){

    unsigned int totalAnos = 0, totalTimes = 0;

    srand((unsigned) time(NULL)); // inicializa o gerador de números aleatórios
    
    if(argc != 3 && argc != 1){
        std::cout << "Numero de argumentos invalido" << std::endl;
        std::cout << "Uso: ./main <numero de times = opcional> <numero de anos = opcional>" << std::endl;
        return 1;
    }

    if(argc == 3){
        totalTimes = strtol(argv[1], NULL, 10);
        totalAnos = strtol(argv[2], NULL, 10);

        if(totalTimes <= 0 || totalAnos <= 0){
            std::cout << "Argumentos invalidos" << std::endl;
            std::cout << "Numero de anos e times nao pode ser zero ou negativos." << std::endl;
            return 1;
        }
    }
    else{
        totalTimes = MAX_TIMES;
        totalAnos = INTERVALO_TEMPO;
    }


    Liga ligas[NUM_LIGAS] = {{"Campeonato Brasileiro", totalTimes, totalAnos}, {"Copa do Brasil", totalTimes, totalAnos}, \
    {"Libertadores", totalTimes, totalAnos}}; // cria as ligas

    menu_principal(ligas); // chama o menu principal

    return 0;
}