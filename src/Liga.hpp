#ifndef LIGA_H
#define LIGA_H

#include "Time.hpp"
#include "main.hpp"

class Liga{
    private:
        std::string nomeLiga;
        unsigned int maxTimes;

        void insereTime(Time);

    public:
        std::vector<Time> times;

        Liga(std::string, unsigned int = MAX_TIMES, unsigned int = INTERVALO_TEMPO);
        
        std::string getNome(void);
        void getTimes();

};

#endif