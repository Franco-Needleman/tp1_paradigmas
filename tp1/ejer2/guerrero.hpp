#ifndef GUERRERO_HPP
#define GUERRERO_HPP
#include"armas.hpp"
#include "personajes.hpp"

class Guerrero : public Personaje {
    protected:
        int vida, armadura, fuerza, resistencia;
        pair<shared_ptr<armas>, shared_ptr<armas>> armas_equipo;
    public:
        Guerrero(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2);
        virtual string quees() const override = 0;
        int getVida() const override;
        int getArmadura() const override;
        int getFuerza() const override;
        void hurt(int d) override;
        int getResistencia() const;
        pair<shared_ptr<armas>, shared_ptr<armas>> getArmas() const override;
        void addArma(const shared_ptr<armas> w) override;
        virtual string tecnicaEspecial() const = 0;
    };

class Barbaro : public Guerrero {
    bool furiaActiva;
    int speed;
    string es;
public:
    Barbaro(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
            bool fA, int sp);
    string quees() const override;
    bool estaEnFuria() const;
    int getspeed() const;
    string tecnicaEspecial() const override;
};

class Paladin : public Guerrero {
    bool familiareal;
    int sanaciones;
    string es;
public:
    Paladin(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
            bool real, int san);
    string quees() const override;
    bool esdelarealeza() const;
    int getSanaciones() const;
    string tecnicaEspecial() const override;
};

class Caballero : public Guerrero {
    string rango;
    bool caballo;
    string es;
public:
    Caballero(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
              string o, bool c);
    string quees() const override;
    string getrango() const;
    bool acaballo() const;
    string tecnicaEspecial() const override;
};

class Mercenario : public Guerrero {
    int oroGanado;
    bool aceptaSobornos;
    string es;
public:
    Mercenario(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
               int oro, bool sob);
    string quees() const override;
    int getOroGanado() const;
    bool esCorrupto() const;
    string tecnicaEspecial() const override;
};

class Gladiador : public Guerrero {
    int victoriasarena;
    string armafav;
    string es;
public:
    Gladiador(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
              int vict, string arma);
    string quees() const override;
    int getVictorias() const;
    string getarmafav() const;
    string tecnicaEspecial() const override;
};

#endif
