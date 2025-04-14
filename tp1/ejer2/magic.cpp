#include "magic.hpp"
// ---------- MÉTODOS DE magic ----------
magic::magic(int d, int m, int t) : damage(d), tipo("magico"), mana(m), tiemporecarga(t) {}

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



// ---------- SUBCLASES MÁGICAS ----------
Baston::Baston(int d, int m, int t, float l, bool c)
: magic(d, m, t), longitud(l), tieneCristal(c) {}

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

LibroDeHechizos::LibroDeHechizos(int d, int m, int t, int cant, string escr)
: magic(d, m, t), cantidadHechizos(cant), escritor(escr) {}

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

Pocion::Pocion(int d, int m, int t, string e, float v)
: magic(d, m, t), efecto(e), volumen(v) {}

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

Amuleto::Amuleto(int d, int m, int t, string elem, string mald)
: magic(d, m, t), elemento(elem), maldicion(mald) {}

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

