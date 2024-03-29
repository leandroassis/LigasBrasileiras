#ifndef TIME_H
#define TIME_H

#include <string>
#include <vector>
#include "Ano.hpp"
#include "main.hpp"

class Time{
    private:
        std::string nomeTime;

        std::vector<Ano> anos;
        unsigned int maxAnos;

        float mediaMovelGolsSofridos;
        float mediaMovelGolsEfetuados;

        int saldoGolsTotal;

        void incluiNovoAno(Ano);
        std::string verificaNome(std::string);

    public:
        
        void setNome(std::string);
        std::string getNome();

        void setAnos(unsigned int);
        void getAnos();

        unsigned int getGolsSofridosNoAno(unsigned int); // retorna num gols sofridos no ano 0 <= n <= maxAnos
        unsigned int getGolsEfetuadosNoAno(unsigned int);

        float getMediaMovelGolsSofridos(unsigned = 3, unsigned = 0);
        float getMediaMovelGolsEfetuados(unsigned = 3, unsigned = 0);
        void setMediaMovelGolsSofridos(unsigned int = 3, unsigned int = 0);
        void setMediaMovelGolsEfetuados(unsigned int = 3, unsigned int = 0);

        void setSaldoGolsTotal();
        int getSaldoGolsTotal();
};

#endif