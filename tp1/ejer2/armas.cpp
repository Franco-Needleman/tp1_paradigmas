#include "armas.hpp"

// ---------- MÉTODOS DE magic ----------
string magic::gettipo() const {
    return tipo;
}

int magic::getdamage() const {
    return damage;
}

int magic::getdelay() const {
    return tiemporecarga;
}

int magic::consumomana() const {
    return mana;
}

// ---------- MÉTODOS DE combat ----------
string combat::gettipo() const {
    return tipo;
}

int combat::getdamage() const {
    return damage;
}

int combat::getdurabilidad() const {
    return durabilidad;
}

int combat::getpenetracion() const {
    return filo * durabilidad;
}

// ---------- SUBCLASES MÁGICAS ----------

float Baston::getLongitud() const {
    return longitud;
}

bool Baston::tieneCristalMagico() const {
    return tieneCristal;
}

float Baston::getAlcance() const {
    return longitud;
}

string Baston::quees() const {
    return "Bastón";
}

int LibroDeHechizos::getCantidadHechizos() const {
    return cantidadHechizos;
}

string LibroDeHechizos::escritopor() const {
    return escritor;
}

float LibroDeHechizos::getAlcance() const {
    return 0;
}

string LibroDeHechizos::quees() const {
    return "Libro de Hechizos";
}

string Pocion::getEfecto() const {
    return efecto;
}

float Pocion::getVolumen() const {
    return volumen;
}

float Pocion::getAlcance() const {
    return 1.0;
}

string Pocion::quees() const {
    return "Poción";
}

string Amuleto::getElemento() const {
    return elemento;
}

string Amuleto::getmaldicion() const {
    return maldicion;
}

float Amuleto::getAlcance() const {
    return 0;
}

string Amuleto::quees() const {
    return "Amuleto";
}

// ---------- SUBCLASES DE COMBATE ----------

float HachaSimple::getPeso() const {
    return peso;
}

string HachaSimple::getmat() const {
    return material;
}

float HachaSimple::getVelocidadAtaque() const {
    return 1.5;
}

string HachaSimple::quees() const {
    return "Hacha Simple";
}

int HachaDoble::getpenetracion() const {
    return 2 * filo * durabilidad;
}

string HachaDoble::getmat() const {
    return material;
}

float HachaDoble::getVelocidadAtaque() const {
    return 1.2;
}

string HachaDoble::quees() const {
    return "Hacha Doble";
}

float Espada::getLongitud() const {
    return longitud;
}

string Espada::getmat() const {
    return material;
}

float Espada::getVelocidadAtaque() const {
    return 2.0;
}

string Espada::quees() const {
    return "Espada";
}

float Lanza::getAlcance() const {
    return alcance;
}

bool Lanza::puedeArrojarse() const {
    return esArrojadiza;
}

float Lanza::getVelocidadAtaque() const {
    return esArrojadiza ? 1.8f : 1.4f;
}

string Lanza::quees() const {
    return "Lanza";
}

bool Garrote::hasclavos() const {
    return tieneClavos;
}

int Garrote::getlargo() const {
    return largo;
}

float Garrote::getVelocidadAtaque() const {
    return 1.1;
}

string Garrote::quees() const {
    return "Garrote";
}
