#include "Robo.hpp"
#include "Ponto2D.hpp"
#include <iostream>
using namespace std;
 
    Robo::Robo (int id, Ponto2D p, bool tbola){
    
    this->energia = 100.00;
    this->id = id;
    this->p = p;
    this->com_bola = tbola;
    
    }
    
    void Robo::mover(double v, double th, double t){
        double des = v*t;
        this->p.x = this->p.x + des*cos(th);
        this->p.y = this->p.y + des*sin(th);
        this->energia -= des;
    }
    
    double Robo::calcular_distancia(Robo* robo){
        return robo->p.calcular_distancia(&this->p);
    }
    
    Robo *Robo::determinar_robo_mais_proximo(Robo** naves, int n){

        
        double min = naves[0]->p.calcular_distancia(&this->p);
        auto maisprox = naves[0];
        if(this == naves[0]) min = 999999.0;
        
        
        for(int i=1; i<n; i++){
            if(naves[i]!=this){
                if(naves[i]->p.calcular_distancia(&this->p) < min){
                    maisprox = naves[i];
                    min = naves[i]->p.calcular_distancia(&this->p);
                }
            }
        }
        return maisprox;
    }
    
    void Robo::passar_bola(Robo** time, int n){
        if (!this->com_bola) {
            std::cout << "Estou sem a bola!" << '\n';
            return;
    } else{
        auto prox = determinar_robo_mais_proximo(time, n);
        prox->com_bola = true;
        this->com_bola = false;
    }
    }
    
    void Robo::imprimir_status(){
        std::cout << this->id << '\t' << this->p.x << '\t' << this->p.y << '\t' << this->com_bola << '\t' << this->energia <<'\n';
    }
