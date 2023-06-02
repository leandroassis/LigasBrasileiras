#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "main.hpp"

#include "menu.hpp"

void menu_principal(Liga *ligas){
    void (*opcoes[5])(Liga*) = {menu1, menu2, menu3, menu4, menu5};
    int opcao = 0;

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    do{
        std::cout << "1 - Evolucao da media de gols realizados e sofridos em cada campeonato e no total." << std::endl;
        std::cout << "2 - Exibir times com melhorias em um campeonato X." << std::endl;
        std::cout << "3 - Exibir times com melhorias em todos os campeonatos." << std::endl;
        std::cout << "4 - Exibir time com maior saldo de gols no campeonato X." << std::endl;
        std::cout << "5 - Exibir time com maior evolucao no último ano." << std::endl;
        std::cout << "6 - Sair." << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if(opcao == 6) break;
        else if(opcao >= 1 && opcao <= 5){
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            opcoes[opcao-1](ligas);
        }
        else std::cout << "Opcao invalida." << std::endl;
    }
    while(opcao >= 1 && opcao <= 5);
}

void menu1(Liga *ligas){
    unsigned int N;
    unsigned numeroTimes = ligas[0].getNumeroTimesNaLiga();
    float tempMediaGolsEfetuados = 0, tempMediaGolsSofridos = 0;

    std::cout << "Insira o número de anos anteriores a serem considerados (padrão = 3)" << std::endl;
    std::cin >> N;

    for(unsigned int i = 0; i < NUM_LIGAS; i++){
        ligas[i].calculaMediaMovelTimes(N);
    }

    std::cout << "\n- Individualmente -" << std::endl;
    for(unsigned i = 0; i < NUM_LIGAS; i++){
        std::cout << "\nLiga: " + ligas[i].getNome() << std::endl;
        for(unsigned int j = 0; j < numeroTimes; j++){
            std::cout << "Time " << j << ": " << std::endl;
            std::cout << "Gols efetuados: " << ligas[i].getMediaMovelGolsEfetuadosTimes(j) << std::endl;
            std::cout << "Gols sofridos: " << ligas[i].getMediaMovelGolsSofridosTimes(j) << std::endl;
            std::cout << std::endl;
        }
    }

    std::cout << "\n- No total -" << std::endl;
    for(unsigned i = 0; i < numeroTimes; i++){
        tempMediaGolsEfetuados = tempMediaGolsSofridos = 0;
        for(unsigned j = 0; j < NUM_LIGAS; j++){
            tempMediaGolsEfetuados += ligas[j].getMediaMovelGolsEfetuadosTimes(i);
            tempMediaGolsSofridos += ligas[j].getMediaMovelGolsSofridosTimes(i);
        }
        std::cout << "Time " << i << ": " << std::endl;
        std::cout << "Gols efetuados: " << tempMediaGolsEfetuados << std::endl;
        std::cout << "Gols sofridos: " << tempMediaGolsSofridos << std::endl;
        std::cout << std::endl;
    }

    std::cout << "\nRetornando ao Menu Principal..." << std::endl;
}

void menu2(Liga *ligas){
    unsigned int codCampeonato;

    std::cout << "1 - Campeonato Brasileiro" << std::endl;
    std::cout << "2 - Copa do Brasil" << std::endl;
    std::cout << "3 - Libertadores" << std::endl;
    std::cout << "Escolha o campeonato: " << std::endl;
    std::cin >> codCampeonato;

    if(codCampeonato < 1 || codCampeonato > 3){
        std::cout << "Opcao invalida." << std::endl;
        return;
    }
    
    ligas[codCampeonato-1].exibePerformanceTimes();

    std::cout << "\nRetornando ao Menu Principal..." << std::endl;
}

void menu3(Liga *ligas){
    float mediaMovelGols[2][2] = {{0, 0}, {0, 0}}; /* [0][0] = media movel gols sofridos, [0][1] = media movel gols sofridos do ano anterior
                                [1][0] = media movel gols efetuados, [1][1] = media movel gols efetuados do ano anterior*/

    for(unsigned i = 0; i < ligas[0].getNumeroTimesNaLiga(); i++){
        // para cada um dos times
        for(unsigned j = 0; j < NUM_LIGAS; j++){
            // em cada uma das ligas

            std::vector<Time> timesNaLiga = ligas[j].getTimes();
        
            // calcula a media de gols sofridos e efetuados do ano atual
            mediaMovelGols[0][0] += timesNaLiga[i].getMediaMovelGolsSofridos();

            mediaMovelGols[1][0] += timesNaLiga[i].getMediaMovelGolsEfetuados();

            // calcula a media de gols sofridos e efetuados do ano anterior
            mediaMovelGols[0][1] += timesNaLiga[i].getMediaMovelGolsSofridos(3, 1);

            mediaMovelGols[1][1] += timesNaLiga[i].getMediaMovelGolsEfetuados(3, 1);
        }

         // verifica se houve melhora
        if((mediaMovelGols[0][0]/mediaMovelGols[0][1]) <= 0.95 || (mediaMovelGols[1][0]/mediaMovelGols[1][1]) >= 1.05){
            std::cout << "O time " << i+1 << " melhorou."  << std::endl;
        }
        // verifica se houve piora
        else if((mediaMovelGols[0][0]/mediaMovelGols[0][1]) >= 1.05 || (mediaMovelGols[1][0]/mediaMovelGols[1][1]) <= 0.95){
            std::cout << "O time " << i+1 << " piorou."  << std::endl;
        }
        // se não houve melhora nem piora
        else std::cout << "O time " << i+1 << " manteve o desempenho." << std::endl;
    }

    std::cout << "\nRetornando ao Menu Principal..." << std::endl;
}

void menu4(Liga *ligas){
    unsigned int codCampeonato;

    std::cout << "1 - Campeonato Brasileiro" << std::endl;
    std::cout << "2 - Copa do Brasil" << std::endl;
    std::cout << "3 - Libertadores" << std::endl;
    std::cout << "Escolha o campeonato: " << std::endl;
    std::cin >> codCampeonato;

    if(codCampeonato < 1 || codCampeonato > 3){
        std::cout << "Opcao invalida." << std::endl;
        return;
    }

    std::cout << "O time com o maior saldo de gols no campeonato " << ligas[codCampeonato-1].getNome() << " em todos os anos foi o " << ligas[codCampeonato-1].getTimeComMaiorSaldoDeGols().getNome() << "." << std::endl;

    std::cout << "\nRetornando ao Menu Principal..." << std::endl;
}

void menu5(Liga *ligas){
    Time timeComMelhorGS, timeComMelhorGE;
    float evolucaoGE = 0, evolucaoGS = 0;

    // arbitra-se a maior evolução como a do primeiro time na primeira liga
    evolucaoGE = ligas[0].getTimes()[0].getMediaMovelGolsEfetuados()/ligas[0].getTimes()[0].getMediaMovelGolsEfetuados(3, 1);
    evolucaoGS = ligas[0].getTimes()[0].getMediaMovelGolsSofridos()/ligas[0].getTimes()[0].getMediaMovelGolsSofridos(3, 1);
    timeComMelhorGE = ligas[0].getTimes()[0];
    timeComMelhorGS = ligas[0].getTimes()[0];

    for(unsigned i = 1; i < ligas[0].getNumeroTimesNaLiga(); i++){
        // para cada um dos times
        for(unsigned j = 0; j < NUM_LIGAS; j++){
            // em cada uma das ligas
            std::vector<Time> timesNaLiga = ligas[j].getTimes();

            if(timesNaLiga[i].getMediaMovelGolsEfetuados(3, 0)/timesNaLiga[i].getMediaMovelGolsEfetuados(3, 1) > evolucaoGE){
                evolucaoGE = timesNaLiga[i].getMediaMovelGolsEfetuados()/timesNaLiga[i].getMediaMovelGolsEfetuados(3, 1);
                timeComMelhorGE = timesNaLiga[i];
            }

            if(timesNaLiga[i].getMediaMovelGolsSofridos(3, 0)/timesNaLiga[i].getMediaMovelGolsSofridos(3, 1) < evolucaoGS){
                evolucaoGS = timesNaLiga[i].getMediaMovelGolsSofridos()/timesNaLiga[i].getMediaMovelGolsSofridos(3, 1);
                timeComMelhorGS = timesNaLiga[i];
            }
        }
    }

    std::cout << "O time com a maior evolucao de Gols Efetuados no ultimo ano foi o " + timeComMelhorGE.getNome() + " com uma evolucao de " << std::setprecision(5) << evolucaoGE << " no gols efetuados." << std::endl;
    std::cout << "O time com a maior evolucao de Gols Sofridos no ultimo ano foi o " + timeComMelhorGS.getNome() + " com uma evolucao de " << std::setprecision(5) << evolucaoGS << " no gols sofridos." << std::endl;

    std::cout << "\nRetornando ao Menu Principal..." << std::endl;
}

