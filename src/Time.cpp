#include <cmath>
#include <climits>
#include <iostream>
#include "Time.hpp"

void Time::setNome(std::string nome){
    nomeTime = verificaNome(nome);
}

std::string Time::getNome(){
    return nomeTime;
}

void Time::setAnos(unsigned int totalAnos){
    maxAnos = totalAnos;
    
    Ano golsNosAnos[totalAnos]; // cria os anos e o construtor padrão já gera números aleatórios

    for(unsigned int i = 0; i < totalAnos; i++){
        incluiNovoAno(golsNosAnos[i]);
    }
}

void Time::getAnos(){
    std::cout << "Time: " + nomeTime << std::endl;

    for(unsigned int i = 0; i < anos.size(); i++){
        std::cout << "Ano: " + std::to_string(i+1) << std::endl;
        std::cout << "GE: " << getGolsEfetuadosNoAno(i);
        std::cout << " GS: " << getGolsSofridosNoAno(i) << std::endl;
    }
    std::cout << std::endl;
}

std::string Time::verificaNome(std::string nome){
    // se o nome do time tiver mais que 10 caracteres, corta até o 10º
    if(nome.length() > 10) return nome.substr(0, 10);

    return nome;
}

void Time::incluiNovoAno(Ano novoAno){
    // se o vetor de anos ainda não tiver chego ao máx especificado na criação do objeto
    if(anos.size() < maxAnos) anos.push_back(novoAno);
    else std::cout << "O vetor de anos do time " + nomeTime + "ja esta no limite maximo.\n" << std::endl;
}

unsigned int Time::getGolsSofridosNoAno(unsigned int indiceAno){
    if(indiceAno < maxAnos) return anos[indiceAno].getGolsSofridos();

    std::cout << "Tentando acessar ano nao disponivel" << std::endl;
    return 0;
}

unsigned int Time::getGolsEfetuadosNoAno(unsigned int indiceAno){
    if(indiceAno < maxAnos) return anos[indiceAno].getGolsEfetuados();

    std::cout << "Tentando acessar ano nao disponivel" << std::endl;
    return 0;
}

float Time::getMediaMovelGolsSofridos(){
    return mediaMovelGolsSofridos;
}

float Time::getMediaMovelGolsEfetuados(){
    return mediaMovelGolsEfetuados;
}

void Time::setMediaMovelGolsSofridos(unsigned int numeroAnosAnteriores){
    unsigned int temp;

    if(numeroAnosAnteriores > anos.size()){
        std::cout << "Tentanto calcular a media movel dos " + std::to_string(numeroAnosAnteriores) + \
        " ultimos anos, mas só se têm salvo " + std::to_string(anos.size()) + " anos.\n" << std::endl;
        mediaMovelGolsSofridos = 0;
        return;
    }

    for(unsigned int i = 0; i < numeroAnosAnteriores; i++) temp += getGolsSofridosNoAno(anos.size()-1-i);

    std::cout << temp << std::endl;
    mediaMovelGolsSofridos = temp/numeroAnosAnteriores;
}

void Time::setMediaMovelGolsEfetuados(unsigned int numeroAnosAnteriores){
    unsigned int temp;

    if(numeroAnosAnteriores > anos.size()){
        std::cout << "Tentanto calcular a media movel dos " + std::to_string(numeroAnosAnteriores) + \
        " ultimos anos, mas só se têm salvo " + std::to_string(anos.size()) + " anos.\n" << std::endl;
        mediaMovelGolsEfetuados = 0;
        return;
    }

    for(unsigned int i = 0; i < numeroAnosAnteriores; i++) temp += getGolsEfetuadosNoAno(anos.size()-1-i);
    
    std::cout << temp << std::endl;
    mediaMovelGolsEfetuados = temp/numeroAnosAnteriores;
}