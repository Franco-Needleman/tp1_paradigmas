#include "mago.cpp"
#include "guerrero.cpp"
#include "magic.cpp"
#include "combat.cpp"
#include <iostream>
using namespace std;

void mostrar_personaje(const shared_ptr<Personaje>& p) {

    cout << p->quees()<<endl;
    cout << "Vida: " << p->getVida() << endl;
    cout << "Armadura: " << p->getArmadura() << endl;
    cout << "Fuerza: " << p->getFuerza() << endl;

    // Armas equipadas
    auto armas_pair = p->getArmas();
   
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

int main(){
        // Crear armas
    shared_ptr<armas> armaHechicero = make_shared<LibroDeHechizos>(20, 10, 3, 5, "Merlín");
    shared_ptr<armas> armaCaballero = make_shared<Espada>(25, 5, 10, 100.0, "acero templado");

    // Crear personajes
    shared_ptr<Personaje> mago = make_shared<Hechicero>(100, 15, 10, 50, armaHechicero, nullptr, "Arcana", 150);
    shared_ptr<Personaje> gurrrero = make_shared<Caballero>(180, 30, 25, 20, armaCaballero, nullptr, "Alférez", true);

    mostrar_personaje(mago);
    mostrar_personaje(gurrrero);

}