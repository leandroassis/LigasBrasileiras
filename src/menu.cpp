#include <iostream>
#include "main.hpp"
#include "menu.hpp"

void menu_principal(Liga *ligas){
    void (*opcoes[5])(Liga*) = {menu1, menu2, menu3, menu4, menu5};
    int opcao = 0;

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
        else if(opcao >= 1 && opcao <= 5) opcoes[opcao-1](ligas);
        else std::cout << "Opcao invalida." << std::endl;
    }
    while(opcao >= 1 && opcao <= 5);
}

void menu1(Liga *ligas){
    unsigned int N;
    unsigned numeroTimes = ligas[0].getNumTimes();
    float bufferMediaMovel[numeroTimes] = {0};

    std::cout << "Insira o número de anos anteriores a serem considerados (padrão = 3)" << std::endl;
    std::cin >> N;

    std::cout << "\nMédia móvel de gols sofridos: " << std::endl;

    std::cout << "\n- Individualmente -" << std::endl;
    for(unsigned i = 0; i < NUM_LIGAS; i++){
        std::cout << "\nLiga: " + ligas[i].getNome() << std::endl;
        std::vector<Time> timesNaLiga = ligas[i].getTimes();
        for(unsigned j = 0; j < numeroTimes; j++){
            timesNaLiga[j].setMediaMovelGolsSofridos(N); // calcula a media movel dos N anos pro time j da liga i
            float mediaMovel = timesNaLiga[j].getMediaMovelGolsSofridos();
            std::cout << timesNaLiga[j].getNome() << ": " << mediaMovel << std::endl;
            bufferMediaMovel[j] += mediaMovel; // salva a media movel do time j da liga i (para calcular a media movel total de todos os campeonatos)
        }
    }

    std::cout << "\n- No total -" << std::endl;
    for(unsigned i = 0; i < numeroTimes; i++){
        std::cout << "Time " << i+1 << ": " << bufferMediaMovel[i] << std::endl;
    }

    std::cout << "\nMédia móvel de gols efetuados: " << std::endl;

    std::cout << "\n- Individualmente -" << std::endl;
    for(unsigned i = 0; i < NUM_LIGAS; i++){
        std::cout << "\nLiga: " + ligas[i].getNome() << std::endl;
        std::vector<Time> timesNaLiga = ligas[i].getTimes();
        for(unsigned j = 0; j < numeroTimes; j++){
            timesNaLiga[j].setMediaMovelGolsEfetuados(N); // calcula a media movel dos N anos pro time j da liga i
            float mediaMovel = timesNaLiga[j].getMediaMovelGolsEfetuados();
            std::cout << timesNaLiga[j].getNome() << ": " << mediaMovel << std::endl;
            bufferMediaMovel[j] += mediaMovel; // salva a media movel do time j da liga i (para calcular a media movel total de todos os campeonatos)
        }
    }

    std::cout << "\n- No total -" << std::endl;
    for(unsigned i = 0; i < numeroTimes; i++){
        std::cout << "Time " << i+1 << ": " << bufferMediaMovel[i] << std::endl;
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
    
    float mediaMovelGols[2][2]; /* [0][0] = media movel gols sofridos, [0][1] = media movel gols sofridos do ano anterior
                                [1][0] = media movel gols efetuados, [1][1] = media movel gols efetuados do ano anterior*/
    for(unsigned i = 0; i < ligas[codCampeonato-1].getNumTimes(); i++){
        // para cada um dos times na liga escolhida
        std::vector<Time> timesNaLiga = ligas[codCampeonato-1].getTimes();
        
        // calcula a media de gols sofridos e efetuados do ano atual
        timesNaLiga[i].setMediaMovelGolsSofridos();
        mediaMovelGols[0][0] = timesNaLiga[i].getMediaMovelGolsSofridos();

        timesNaLiga[i].setMediaMovelGolsEfetuados();
        mediaMovelGols[1][0] = timesNaLiga[i].getMediaMovelGolsEfetuados();

        // calcula a media de gols sofridos e efetuados do ano anterior
        timesNaLiga[i].setMediaMovelGolsSofridos(1);
        mediaMovelGols[0][1] = timesNaLiga[i].getMediaMovelGolsSofridos();

        timesNaLiga[i].setMediaMovelGolsEfetuados(1);
        mediaMovelGols[1][1] = timesNaLiga[i].getMediaMovelGolsEfetuados();

        // verifica se houve melhora
        if((mediaMovelGols[0][0]/mediaMovelGols[0][1]) <= 0.95 || (mediaMovelGols[1][0]/mediaMovelGols[1][1]) >= 1.05){
            std::cout << "O time " << i+1 << " melhorou no campeonato " << codCampeonato << "."  << std::endl;
        }
        // verifica se houve piora
        else if((mediaMovelGols[0][0]/mediaMovelGols[0][1]) >= 1.05 || (mediaMovelGols[1][0]/mediaMovelGols[1][1]) <= 0.95){
            std::cout << "O time " << i+1 << " piorou no campeonato " << codCampeonato << "."  << std::endl;
        }
        // se não houve melhora nem piora
        else std::cout << "O time " << i+1 << " manteve o desempenho no campeonato " << codCampeonato << "." << std::endl;
    }

    std::cout << "\nRetornando ao Menu Principal..." << std::endl;
}

void menu3(Liga *ligas){
    std::cout << "Funcao" << std::endl;
}

void menu4(Liga *ligas){
    std::cout << "Funcao" << std::endl;
}

void menu5(Liga *ligas){
    std::cout << "Funcao" << std::endl;
}

