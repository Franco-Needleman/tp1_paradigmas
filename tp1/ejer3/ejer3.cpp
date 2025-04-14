#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <memory> 
#include "factory.cpp" 


using namespace std;




void mostrar_personaje(const shared_ptr<Personaje>& p) {
    if(p){ 
        cout << p->quees()<<endl;
        cout << "Vida: " << p->getVida() << endl;
        cout << "Armadura: " << p->getArmadura() << endl;
        cout << "Fuerza: " << p->getFuerza() << endl;

        // Armas equipadas
        pair<std::shared_ptr<armas>, std::shared_ptr<armas>> armas_pair = p->getArmas();
    
        cout << "Arma 1: ";

        if (armas_pair.first) {
            cout << armas_pair.first->gettipo() << " | " << armas_pair.first->quees()
                    << " | Daño: " << armas_pair.first->getdamage()<<endl;
        } else {
            cout << "Ninguna" << endl;
        }

        cout << "Arma 2: " ;

        if (armas_pair.second) {
            cout << armas_pair.second->gettipo() << " | " << armas_pair.second->quees()
                    << " | Daño: " << armas_pair.second->getdamage()<<endl;
        } else {
            cout << "Ninguna" << endl;
        }
    
    }

}



int main() {
    // Inicializar el generador de números aleatorios con la hora actual
    srand(time(nullptr));

    // Generar número entre 3 y 7
    int cant_personajes = 3 + (rand() % 5); // 5 = (7 - 3 + 1)
    shared_ptr<armas> arma1 = nullptr;
    shared_ptr<armas> arma2 = nullptr;
    for (int i=0; i<cant_personajes; i++){
        int cant_armas = rand() % 3;
        if (cant_armas){
            arma1 = factory::crear_arma(rand() ,rand() );
            if (cant_armas>1){
                arma2 = factory::crear_arma(rand() ,rand() );
            }
        }
        cout << "-------------------------------\nPersonaje: "<<i << endl;
        shared_ptr<Personaje> p =factory::crear_personaje(rand(),rand());
        p->addArma(arma1);
        p->addArma(arma2);
        mostrar_personaje(p);


    }
    

    return 0;
}
