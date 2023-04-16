#include <iostream>
#include <list>
#include <string>
#include "veiculo.hpp"
#include "caminhao_autonomo.hpp"
using namespace std;

void print_list(list<Veiculo*> l){
list<Veiculo*>::iterator it;
  for (it = l.begin(); it != l.end(); ++it) {
      (*it)->print_info();
    }
  } 

void rm_id(list<Veiculo*> &l, int id){
list<Veiculo*>::iterator it;
  for (it = l.begin(); it != l.end(); ++it) {
    if((*it)->get_id() == id) {
      l.erase(it);
      return;
    }
  } 
}

int main(){

list<Veiculo*> l;
string command;
string fab;
int x, y, z;

  while (getline(cin, command) && !command.empty()) {
    if (command == "add_c") {

      cin >> x >> y >> z;
      Caminhao * c = new Caminhao("Caminhao", x, y, z);
      l.push_back(c);

    } else if (command == "add_ca") {

      cin >> x >> y >> z >> fab;
      CaminhaoAutonomo * ca = new CaminhaoAutonomo(x, y, z, fab);
      l.push_back(ca);
      

    } else if (command == "rm id") {

      cin >> x;
      rm_id(l, x);

    } else if (command == "print") {
        
      print_list(l);
    }
    
    command = "";
  }
    return 0;
}
