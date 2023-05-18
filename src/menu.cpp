#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "main.hpp"

void menu(){
    void (*opcoes[5])(int) = {menu1, menu2, menu3, menu4, menu5};
    int opcao = 0;

    do{
        std::cout << "1 - Evolucao da media de gols realizados e sofridos em cada campeonato e no total." << std::endl;
        std::cout << "2 - Exibir times com melhorias em um campeonato X." << std::endl;
        std::cout << "3 - Exibir times com melhorias em todos os campeonatos." << std::endl;
        std::cout << "4 - Exibir time com maior saldo de gols no campeonato X." << std::endl;
        std::cout << "5 - Exibit time com maior evolucao no último ano." << std::endl;
        std::cout << "6 - Sair." << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if(opcao == 6) break;
        else if(opcao >= 1 && opcao <= 5) opcoes[opcao-1](opcao);
        else std::cout << "Opcao invalida." << std::endl;
    }
    while(opcao >= 1 && opcao <= 5);
}
#endif