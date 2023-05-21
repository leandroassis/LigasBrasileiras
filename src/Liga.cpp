#include <iostream>
#include "Liga.hpp"


Liga::Liga(std::string nome, unsigned int totalTimes, unsigned int totalAnos){
    nomeLiga = nome;
    maxTimes = totalTimes;

    Time timesNaLiga[totalTimes]; // cria os times com o construtor padrão

    for(unsigned int i = 0; i < totalTimes; i++){
        timesNaLiga[i].setNome("Time "+ std::to_string(i+1));
        timesNaLiga[i].setAnos(totalAnos);
        insereTime(timesNaLiga[i]);
    }
}

unsigned Liga::getNumTimes(void){
    return times.size();
}

void Liga::insereTime(Time novoTime){
    if(times.size() < maxTimes) times.push_back(novoTime);
    else std::cout << "O vetor de times da Liga " + nomeLiga + "ja esta no limite maximo.\n" << std::endl;
}

std::string Liga::getNome(){
    return nomeLiga;
}

std::vector<Time> Liga::getTimes(){
    //std::cout << "Liga: " + nomeLiga << std::endl;
    //for(unsigned int i = 0; i < times.size(); i++) std::cout << times[i].getNome() << std::endl;
    //std::cout << std::endl;

    return times;
}