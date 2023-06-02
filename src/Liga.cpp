#include <iostream>
#include "Liga.hpp"


Liga::Liga(std::string nome, unsigned int totalTimes, unsigned int totalAnos): mediaMovelGolsSofridosTimes(totalTimes), mediaMovelGolsEfetuadosTimes(totalTimes){
    nomeLiga = nome;
    maxTimes = totalTimes;

    Time timesNaLiga[totalTimes]; // cria os times com o construtor padrão

    for(unsigned int i = 0; i < totalTimes; i++){
        timesNaLiga[i].setNome("Time "+ std::to_string(i+1));
        timesNaLiga[i].setAnos(totalAnos);
        insereTime(timesNaLiga[i]);
    }
}

void Liga::insereTime(Time novoTime){
    if(times.size() < maxTimes) times.push_back(novoTime);
    else std::cout << "O vetor de times da Liga " + nomeLiga + "ja esta no limite maximo.\n" << std::endl;
}

std::string Liga::getNome(){
    return nomeLiga;
}

std::vector<Time> Liga::getTimes(){
    return times;
}   

unsigned int Liga::getNumeroTimesNaLiga(){
    return times.size();
}

void Liga::setTimeComMaiorSaldoDeGols(){
    unsigned int indiceMaiorSaldoGols = 0; // considera o primeiro como maior saldo de gols

    for(unsigned i = 1; i < times.size(); i++){
        // se algum time tiver saldo de gols maior, troca o maior saldo de gols
        if(times[i].getSaldoGolsTotal() > times[indiceMaiorSaldoGols].getSaldoGolsTotal()) indiceMaiorSaldoGols = i;
    }

    timeComMaiorSaldoDeGols = times[indiceMaiorSaldoGols];
}

Time Liga::getTimeComMaiorSaldoDeGols(){
    setTimeComMaiorSaldoDeGols();
    return timeComMaiorSaldoDeGols;
}

void Liga::exibePerformanceTimes(){
    float mediaMovelGols[2][2]; /* [0][0] = media movel gols sofridos, [0][1] = media movel gols sofridos do ano anterior
                                   [1][0] = media movel gols efetuados, [1][1] = media movel gols efetuados do ano anterior*/
    for(unsigned i = 0; i < times.size(); i++){
    // para cada um dos times na liga escolhida
        
        // calcula a media de gols sofridos e efetuados do ano atual
        mediaMovelGols[0][0] = times[i].getMediaMovelGolsSofridos();

        mediaMovelGols[1][0] = times[i].getMediaMovelGolsEfetuados();

        // calcula a media de gols sofridos e efetuados do ano anterior
        mediaMovelGols[0][1] = times[i].getMediaMovelGolsSofridos(3, 1);

        mediaMovelGols[1][1] = times[i].getMediaMovelGolsEfetuados(3, 1);

        // verifica se houve melhora
        if((mediaMovelGols[0][0]/mediaMovelGols[0][1]) <= 0.95 || (mediaMovelGols[1][0]/mediaMovelGols[1][1]) >= 1.05){
            std::cout << "O " << times[i].getNome() << " melhorou no campeonato " << nomeLiga << "."  << std::endl;
        }
        // verifica se houve piora
        else if((mediaMovelGols[0][0]/mediaMovelGols[0][1]) >= 1.05 || (mediaMovelGols[1][0]/mediaMovelGols[1][1]) <= 0.95){
            std::cout << "O " << times[i].getNome() << " piorou no campeonato " << nomeLiga << "."  << std::endl;
        }
        // se não houve melhora nem piora
        else std::cout << "O " << times[i].getNome() << " manteve o desempenho no campeonato " << nomeLiga << "." << std::endl;
    }
}

void Liga::calculaMediaMovelTimes(unsigned int numeroAnosAnteriores){
    for(unsigned j = 0; j < times.size(); j++){
        mediaMovelGolsSofridosTimes[j] = times[j].getMediaMovelGolsSofridos(numeroAnosAnteriores); // calcula a media movel dos N anos pro time j
        mediaMovelGolsEfetuadosTimes[j] = times[j].getMediaMovelGolsEfetuados(numeroAnosAnteriores); // calcula a media movel dos N anos pro time j
    }
}

float Liga::getMediaMovelGolsEfetuadosTimes(unsigned int pos){
    if(pos < 0 || pos >= times.size()){
        std::cout << "Posição inválida." << std::endl;
        return -1;
    }

    return mediaMovelGolsEfetuadosTimes[pos];
}


float Liga::getMediaMovelGolsSofridosTimes(unsigned int pos){
    if(pos < 0 || pos >= times.size()){
        std::cout << "Posição inválida." << std::endl;
        return -1;
    }

    return mediaMovelGolsSofridosTimes[pos];
}