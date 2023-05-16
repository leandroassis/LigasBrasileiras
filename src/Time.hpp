#ifndef TIME_H
#define TIME_H

#include <string>
#include <vector>

class Time{
    private:
        std::string nomeTime;
    public:
        Time(std::string);
        void setNome(std::string);
        std::string getNome();
};

#endif