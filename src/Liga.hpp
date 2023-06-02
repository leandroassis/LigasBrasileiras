#ifndef LIGA_H
#define LIGA_H

#include "Time.hpp"
#include "main.hpp"

class Liga{
    private:
        std::string nomeLiga;
        unsigned int maxTimes;

        std::vector<Time> times;
        std::vector<float> mediaMovelGolsSofridosTimes;
        std::vector<float> mediaMovelGolsEfetuadosTimes;

        Time timeComMaiorSaldoDeGols;

        void insereTime(Time);

    public:
        Liga(std::string, unsigned int = MAX_TIMES, unsigned int = INTERVALO_TEMPO);
        

        void setTimeComMaiorSaldoDeGols();
        Time getTimeComMaiorSaldoDeGols();
        
        void exibePerformanceTimes();

        void calculaMediaMovelTimes(unsigned int = 3);
        float getMediaMovelGolsSofridosTimes(unsigned int);
        float getMediaMovelGolsEfetuadosTimes(unsigned int);

        std::string getNome(void);
        std::vector<Time> getTimes();
        unsigned int getNumeroTimesNaLiga();
};

#endif