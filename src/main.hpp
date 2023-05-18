#ifndef MAIN_H
#define MAIN_H

const unsigned int INTERVALO_TEMPO  = 8;
const unsigned int MAX_TIMES = 2;
const unsigned int MAX_GOLS = 50;
const unsigned int MIN_GOLS = 15;

void menu();
void menu1(int);
void menu2(int);
void menu3(int);
void menu4(int);
void menu5(int);


void verificaArgumentos(const int, const char *argv[], const unsigned int *, const unsigned int *);

#endif