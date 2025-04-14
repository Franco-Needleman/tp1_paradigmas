#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "armas.hpp"

class combat : public armas {
    protected:
        int damage;
        string tipo;
        int filo;
        int durabilidad;
    public:
        combat(int d, int f, int t);
        string gettipo() const override;
        int getdamage() const override;
        int getdurabilidad() const;
        virtual int getpenetracion() const;
        virtual float getVelocidadAtaque() const = 0;
    };

class HachaSimple : public combat {
    float peso;
    string material;
public:
    HachaSimple(int d, int f, int t, float p, string mat);
    float getPeso() const;
    string getmat() const;
    float getVelocidadAtaque() const override;
    string quees() const override;
};

class HachaDoble : public combat {
    int dobleFilo;
    string material;
public:
    HachaDoble(int d, int f, int t, int df, string m);
    int getpenetracion() const override;
    string getmat() const;
    float getVelocidadAtaque() const override;
    string quees() const override;
};

class Espada : public combat {
    float longitud;
    string material;
public:
    Espada(int d, int f, int t, float l, string mat);
    float getLongitud() const;
    string getmat() const;
    float getVelocidadAtaque() const override;
    string quees() const override;
};

class Lanza : public combat {
    float alcance;
    bool esArrojadiza;
public:
    Lanza(int d, int f, int t, float a, bool arroja);
    float getAlcance() const;
    bool puedeArrojarse() const;
    float getVelocidadAtaque() const override;
    string quees() const override;
};

class Garrote : public combat {
    bool tieneClavos;
    int largo;
public:
    Garrote(int d, int f, int t, bool clavos, int l);
    bool hasclavos() const;
    int getlargo() const;
    float getVelocidadAtaque() const override;
    string quees() const override;
};

#endif
