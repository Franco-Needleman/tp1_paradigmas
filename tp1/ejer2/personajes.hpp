#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP

#include <memory>
#include <string>
#include "armas.hpp"
using namespace std;

// Interfaz base
class Personaje {
public:
    virtual int getVida() const = 0;
    virtual int getArmadura() const = 0;
    virtual int getFuerza() const = 0;
    virtual pair<shared_ptr<armas>, shared_ptr<armas>> getArmas() const = 0;
    virtual void addArma(const shared_ptr<armas> w) = 0;
    virtual void hurt(int d) = 0;
    virtual string quees() const = 0;
    virtual ~Personaje() = default;
};
#endif