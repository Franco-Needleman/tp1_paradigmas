#include "combat.hpp"

// ---------- MÉTODOS DE combat ----------
combat::combat(int d, int f, int t) : damage(d), tipo("combate"), filo(f), durabilidad(t) {}

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


// ---------- SUBCLASES DE COMBATE ----------
HachaSimple::HachaSimple(int d, int f, int t, float p, string mat)
: combat(d, f, t), peso(p), material(mat) {}


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

HachaDoble::HachaDoble(int d, int f, int t, int df, string m)
: combat(d, f, t), dobleFilo(df), material(m) {}

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

Espada::Espada(int d, int f, int t, float l, string mat)
: combat(d, f, t), longitud(l), material(mat) {}

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

Lanza::Lanza(int d, int f, int t, float a, bool arroja)
: combat(d, f, t), alcance(a), esArrojadiza(arroja) {}

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

Garrote::Garrote(int d, int f, int t, bool clavos, int l)
            : combat(d, f, t), tieneClavos(clavos), largo(l) {}


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


