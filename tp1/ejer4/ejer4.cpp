#include "/home/paradigmas/tp1/ejer3/factory.cpp"
using namespace std;
#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <memory> 


int pedirEntero(const string& mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(99999, '\n'); // Ignora la entrada inválida
            cout << "Entrada inválida. Por favor ingrese un número entero válido." << endl;
        } else {
            cin.ignore(99999, '\n'); // Limpia cualquier carácter adicional
            return numero;
        }
    }
}


enum Accion {
    GOLPE_FUERTE = 1,
    GOLPE_RAPIDO,
    DEFENSA_Y_GOLPE
};

string nombreAccion(int accion) {
    switch (accion) {
        case GOLPE_FUERTE: return "Golpe Fuerte";
        case GOLPE_RAPIDO: return "Golpe Rapido";
        case DEFENSA_Y_GOLPE: return "Defensa y Golpe";
        default: return "Desconocido";
    }
}

int gano(int accion1, int accion2) {
    if (accion1 == accion2) return 0;

    if ((accion1 == GOLPE_FUERTE && accion2 == GOLPE_RAPIDO) ||
        (accion1 == GOLPE_RAPIDO && accion2 == DEFENSA_Y_GOLPE) ||
        (accion1 == DEFENSA_Y_GOLPE && accion2 == GOLPE_FUERTE)) {
        return 1;  // gana jugador 1
    } else {
        return -1; // gana jugador 2
    }
}

int main() {
    srand(time(nullptr));
    int cual;
    int tipo = pedirEntero("tipo:\n0.mago\n1.guerrero\ningrese tipo: ");
    while(tipo!=1 && tipo!=0){
        cout << "eleccion invalida" << endl;
        tipo = pedirEntero("tipo:\n0.mago\n1.guerrero\n\ningrese tipo: ");
    }
    if (tipo){
        cout << "seleccione que guerrero:" << endl;
        cual= pedirEntero("0.barbaro\n1.paladin\n2.caballero\n3.mercenario\n4.gladiador\nelija: ");
        while(cual>4 || cual<0){
            cout << "opcion invalida" << endl;
            cual= pedirEntero("0.barbaro\n1.paladin\n2.caballero\n3.mercenario\n4.gladiador\nelija: ");
        }
    }
    else{
        cout << "seleccione que mago:" << endl;
        cual= pedirEntero("0.hechicero\n1.conjurador\n2.brujo\n3.nigromante\nelija: ");
        while(cual>3 || cual<0){
            cout << "opcion invalida" << endl;
            cual= pedirEntero("0.hechicero\n1.conjurador\n2.brujo\n3.nigromante\nelija: ");
        }
    }

    shared_ptr<Personaje> player = factory::crear_personaje(tipo,cual);
    shared_ptr<Personaje> ia = factory::crear_personaje(rand(),rand());
    

    int tipoa = pedirEntero("tipo de arma:\n0. mágica\n1. combate\ningrese tipo: ");
    while (tipoa != 0 && tipoa != 1) {
        cout << "elección inválida" << endl;
        tipoa = pedirEntero("tipo de arma:\n0. mágica\n1. combate\ningrese tipo: ");
    }

    int cuala;
    if (tipoa) {
        cout << "seleccione qué arma de combate:\n";
        cuala = pedirEntero("0. Hacha simple\n1. Hacha doble\n2. Espada\n3. Lanza\n4. Garrote\nelija: ");
        while (cuala < 0 || cuala > 4) {
            cout << "opción inválida" << endl;
            cuala = pedirEntero("0. Hacha simple\n1. Hacha doble\n2. Espada\n3. Lanza\n4. Garrote\nelija: ");
        }
    } else {
        cout << "seleccione qué arma mágica:\n";
        cuala = pedirEntero("0. Bastón\n1. Libro de hechizos\n2. Poción\n3. Amuleto\nelija: ");
        while (cuala < 0 || cuala > 3) {
            cout << "opción inválida" << endl;
            cuala = pedirEntero("0. Bastón\n1. Libro de hechizos\n2. Poción\n3. Amuleto\nelija: ");
        }
    }
    cout << cuala;
    shared_ptr<armas> armap = factory::crear_arma(tipoa, cuala);//sumo uno por la implementecion en factory es al reves
    shared_ptr<armas> armaia = factory::crear_arma(rand(), rand());

    player->addArma(armap);
    ia->addArma(armaia);

    while (player->getVida() > 0 && ia->getVida() > 0) {
        int accion1;
        cout << "\n--- Nueva ronda ---\n";
        cout << "1. Golpe Fuerte\n2. Golpe Rapido\n3. Defensa y Golpe\n ";
        accion1 = pedirEntero("elija: ");

        while (accion1 < 1 || accion1 > 3) {
            cout << "Opcion invalida. Elegi 1, 2 o 3: ";
            accion1 = pedirEntero("elija: ");
        }

        int accion2 = rand() % 3 + 1;
        cout << "Jugador 2 eligio: " << nombreAccion(accion2) << "\n";

        int resultado = gano(accion1, accion2);
        if (resultado == 1) {
            ia->hurt(10);
            cout << "Jugador 1: ataca su " <<player->quees()<<" usando su "<< player->getArmas().first->quees()<<" y hace 10 de daño.\n";
        } else if (resultado == -1) {
            player->hurt(10);
            cout << "Jugador 2: ataca su " <<ia->quees()<<" usando su "<< ia->getArmas().first->quees()<<" y hace 10 de daño.\n";
        } else {
            cout << "Empate. Nadie recibe daño.\n";
        }

        cout << "Vida Jugador 1: " << player->getVida() << " | Vida Jugador 2: " << ia->getVida() << "\n";
    }

    cout << "\n--- Fin del combate ---\n";
    if (player->getVida() <= 0)
        cout << "¡Jugador 2 gana!\n";
    else
        cout << "¡Jugador 1 gana!\n";

    return 0;
}
