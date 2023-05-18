#include <iostream>
#include <vector>
#include <cstdlib>
#include "Liga.hpp"
#include "Time.hpp"
#include "Ano.hpp"

    
int main(int argc, char *argv[]){

    srand((unsigned) time(NULL));

    Liga ligas[3] = {{"Campeonato Brasileiro"}, {"Copa do Brasil"}, {"Libertadores"}};
    
    for(int i = 0; i < 3; i++) ligas[i].getTimes(); // mostra nome de cada liga e seus respectivos times


    for(unsigned int i = 0; i < 3; i++){
            std::cout << ligas[i].getNome() << std::endl;
        for(unsigned int j = 0; j < ligas[i].times.size(); j++){

            ligas[i].times[j].getAnos();

            std::cout << "Média movel dos ultimos 3 anos:" << std::endl;

            ligas[i].times[j].setMediaMovelGolsEfetuados();
            ligas[i].times[i].setMediaMovelGolsSofridos();
            std::cout << "GE: " << ligas[i].times[j].getMediaMovelGolsEfetuados() << std::endl;
            std::cout << "GS: " << ligas[i].times[j].getMediaMovelGolsSofridos() << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}