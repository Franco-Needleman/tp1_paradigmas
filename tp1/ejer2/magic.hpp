#ifndef MAGIC_HPP
#define MAGIC_HPP

#include "armas.hpp"

class magic : public armas {
    protected:
        int damage;
        string tipo;
        int mana;
        int tiemporecarga;
    public:
        magic(int d, int m, int t);
        string gettipo() const override;
        int getdamage() const override;
        int getdelay() const;
        int consumomana() const;
        virtual float getAlcance() const = 0;
    };
    

class Baston : public magic {
    float longitud;
    bool tieneCristal;
public:
    Baston(int d, int m, int t, float l, bool c);
    float getLongitud() const;
    bool tieneCristalMagico() const;
    float getAlcance() const override;
    string quees() const override;
};

class LibroDeHechizos : public magic {
    int cantidadHechizos;
    string escritor;
public:
    LibroDeHechizos(int d, int m, int t, int cant, string escr);
    int getCantidadHechizos() const;
    string escritopor() const;
    float getAlcance() const override;
    string quees() const override;
};

class Pocion : public magic {
    string efecto;
    float volumen;
public:
    Pocion(int d, int m, int t, string e, float v);
    string getEfecto() const;
    float getVolumen() const;
    float getAlcance() const override;
    string quees() const override;
};

class Amuleto : public magic {
    string elemento;
    string maldicion;
public:
    Amuleto(int d, int m, int t, string elem, string mald);
    string getElemento() const;
    string getmaldicion() const;
    float getAlcance() const override;
    string quees() const override;
};

#endif
