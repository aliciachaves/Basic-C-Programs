#ifndef ROBO_H
#define ROBO_H
#include "Ponto2D.hpp"
#include <iostream>

struct Robo{
    
    int id;
    Ponto2D p;
    double energia;
    bool com_bola;
    
    Robo (int id, Ponto2D p, bool tbola);

    void mover(double v, double th, double t);
    
    double calcular_distancia(Robo* robo);
    
    Robo* determinar_robo_mais_proximo(Robo** naves, int n);

    void passar_bola(Robo** time, int n);
    
    void imprimir_status();

};

#endif
