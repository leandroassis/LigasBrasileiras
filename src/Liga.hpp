#ifndef LIGA_H
#define LIGA_H

#include "Time.hpp"
#include "main.hpp"

class Liga{
    private:
        std::string nomeLiga;
        unsigned int maxTimes;

        std::vector<Time> times;

        void insereTime(Time);

    public:
        Liga(std::string, unsigned int = MAX_TIMES, unsigned int = INTERVALO_TEMPO);
        
        std::string getNome(void);
        std::vector<Time> getTimes();
        unsigned int getNumeroTimesNaLiga();
};

#endif