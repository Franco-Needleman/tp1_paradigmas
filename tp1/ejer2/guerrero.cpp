#include "guerrero.hpp"

// ---------- Guerrero ----------
Guerrero::Guerrero(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2)
: vida(v), armadura(a), fuerza(f), resistencia(r), armas_equipo({arma1, arma2}) {}
int Guerrero::getVida() const { return vida; }
int Guerrero::getArmadura() const { return armadura; }
int Guerrero::getFuerza() const { return fuerza; }
int Guerrero::getResistencia() const { return resistencia; }
void Guerrero::hurt(int d) { vida -= d; }
pair<shared_ptr<armas>, shared_ptr<armas>> Guerrero::getArmas() const { return armas_equipo; }

void Guerrero::addArma(const shared_ptr<armas> w) {
    if (!armas_equipo.first) {
        armas_equipo.first = w;
    } else if (!armas_equipo.second) {
        armas_equipo.second = w;
    } else {
        armas_equipo.first = w;
    }
}


// ---------- Barbaro ----------
Barbaro::Barbaro(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
    bool fA, int sp)
: Guerrero(v, a, f, r, arma1, arma2), furiaActiva(fA), speed(sp), es("barbaro") {}

string Barbaro::quees() const { return es; }
bool Barbaro::estaEnFuria() const { return furiaActiva; }
int Barbaro::getspeed() const { return speed; }
string Barbaro::tecnicaEspecial() const { return "Golpe colosal"; }

// ---------- Paladin ----------
Paladin::Paladin(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
    bool real, int san)
: Guerrero(v, a, f, r, arma1, arma2), familiareal(real), sanaciones(san), es("paladin") {}

string Paladin::quees() const { return es; }
bool Paladin::esdelarealeza() const { return familiareal; }
int Paladin::getSanaciones() const { return sanaciones; }
string Paladin::tecnicaEspecial() const { return "Luz del guardián"; }

// ---------- Caballero ----------
Caballero::Caballero(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
        string o, bool c)
: Guerrero(v, a, f, r, arma1, arma2), rango(o), caballo(c), es("caballero") {}

string Caballero::quees() const { return es; }
string Caballero::getrango() const { return rango; }
bool Caballero::acaballo() const { return caballo; }
string Caballero::tecnicaEspecial() const { return "Carga heroica"; }

// ---------- Mercenario ----------
Mercenario::Mercenario(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
          int oro, bool sob)
: Guerrero(v, a, f, r, arma1, arma2), oroGanado(oro), aceptaSobornos(sob), es("mercenario") {}

string Mercenario::quees() const { return es; }
int Mercenario::getOroGanado() const { return oroGanado; }
bool Mercenario::esCorrupto() const { return aceptaSobornos; }
string Mercenario::tecnicaEspecial() const { return "Golpe letal"; }

// ---------- Gladiador ----------
Gladiador::Gladiador(int v, int a, int f, int r, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
        int vict, string arma)
: Guerrero(v, a, f, r, arma1, arma2), victoriasarena(vict), armafav(arma), es("gladiador") {}

string Gladiador::quees() const { return es; }
int Gladiador::getVictorias() const { return victoriasarena; }
string Gladiador::getarmafav() const { return armafav; }
string Gladiador::tecnicaEspecial() const { return "Fin del contendiente"; }
