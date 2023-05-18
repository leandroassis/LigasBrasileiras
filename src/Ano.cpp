#include <iostream>
#include <cstdlib>
#include "Ano.hpp"

#include "main.hpp"

Ano::Ano(){
    // gera valores aleatórios para os golsSofridos e golsEfetuados
    golsSofridos = MIN_GOLS + (rand() % (MAX_GOLS - MIN_GOLS + 1));
    golsEfetuados = MIN_GOLS + (rand() % (MAX_GOLS - MIN_GOLS + 1));
}

unsigned int Ano::getGolsEfetuados(){
    return golsEfetuados;
}

unsigned int Ano::getGolsSofridos(){
    return golsSofridos;
}