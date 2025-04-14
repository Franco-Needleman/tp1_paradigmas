#ifndef MAGO_HPP
#define MAGO_HPP
#include"armas.hpp"

#include "personajes.hpp"

class Mago : public Personaje {
protected:
    int vida, armadura, fuerza, mana;
    pair<shared_ptr<armas>, shared_ptr<armas>> armas_equipo;
public:
    Mago(int v, int a, int f, int i, shared_ptr<armas> arma1, shared_ptr<armas> arma2);
    int getVida() const override;
    int getArmadura() const override;
    int getFuerza() const override;
    void hurt(int d) override;
    int getmana() const;
    pair<shared_ptr<armas>, shared_ptr<armas>> getArmas() const override;
    void addArma(const shared_ptr<armas> w) override;
    virtual string lanzarHechizo() const = 0;
};

class Hechicero : public Mago {
    string escuela;
    int experiencia;
    string es;
public:
    Hechicero(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
              string esc, int exp);
    string quees() const override;
    string getEscuela() const;
    int getexp() const;
    string lanzarHechizo() const override;
};

class Conjurador : public Mago {
    int invocaciones;
    bool controlaElementos;
    string es;
public:
    Conjurador(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
               int inv, bool elem);
    string quees() const override;
    int getInvocaciones() const;
    bool controlaLosElementos() const;
    string lanzarHechizo() const override;
};

class Brujo : public Mago {
    int corrupcion;
    bool pactoOscuro;
    string es;
public:
    Brujo(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
          int corr, bool pacto);
    string quees() const override;
    int getCorrupcion() const;
    bool tienePactoOscuro() const;
    string lanzarHechizo() const override;
};

class Nigromante : public Mago {
    int ejercitoMuerto;
    bool reencarna;
    string es;
public:
    Nigromante(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
               int ej, bool r);
    string quees() const override;
    int getEjercitoMuerto() const;
    bool reencarnaHabilitado() const;
    string lanzarHechizo() const override;
};

#endif
