#include <iostream>
#include "Ponto2D.hpp"



    Ponto2D::Ponto2D(double x, double y){
        this->x = x;
        this->y = y;
    }
    
    
    double Ponto2D::calcular_distancia(Ponto2D* ponto){
        double x2 = (ponto->x - this->x)*(ponto->x - this->x);
        double y2 = (ponto->y - this->y)*(ponto->y - this->y);
        
        return sqrt((x2+y2));
    }
