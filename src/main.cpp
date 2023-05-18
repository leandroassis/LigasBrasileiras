#include <iostream>
#include <vector>
#include <cstdlib>
#include "Liga.hpp"
#include "Time.hpp"
#include "Ano.hpp"
#include "main.hpp"
    
int main(int argc, char *argv[]){

    unsigned int totalAnos = 0, totalTimes = 0;
    int status;

    srand((unsigned) time(NULL)); // inicializa o gerador de números aleatórios
    
    verificaArgumentos(argc, argv, &totalAnos, &totalTimes); // verifica os argumentos passados na linha de comando

    Liga ligas[3] = {{"Campeonato Brasileiro", totalTimes, totalAnos}, {"Copa do Brasil", totalTimes, totalAnos}, \
    {"Libertadores", totalTimes, totalAnos}}; // cria as ligas

    menu(); // chama o menu principal

    return 0;
}