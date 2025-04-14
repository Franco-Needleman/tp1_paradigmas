#include "mago.hpp"
// ---------- Mago ----------
Mago::Mago(int v, int a, int f, int i, shared_ptr<armas> arma1, shared_ptr<armas> arma2)
: vida(v), armadura(a), fuerza(f), mana(i), armas_equipo({arma1, arma2}) {}
int Mago::getVida() const { return vida; }
int Mago::getArmadura() const { return armadura; }
int Mago::getFuerza() const { return fuerza; }
int Mago::getmana() const { return mana; }
void Mago::hurt(int d) { vida -= d; }
pair<shared_ptr<armas>, shared_ptr<armas>> Mago::getArmas() const { return armas_equipo; }

void Mago::addArma(const shared_ptr<armas> w) {
    if (!armas_equipo.first) {
        armas_equipo.first = w;
    } else if (!armas_equipo.second) {
        armas_equipo.second = w;
    } else {
        armas_equipo.first = w;
    }
}



// ---------- Hechicero ----------
Hechicero::Hechicero(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
                     string esc, int exp)
    : Mago(v, a, f, m, arma1, arma2), escuela(esc), experiencia(exp), es("hechicero") {}

string Hechicero::quees() const { return es; }
string Hechicero::getEscuela() const { return escuela; }
int Hechicero::getexp() const { return experiencia; }
string Hechicero::lanzarHechizo() const { return "¡Ráfaga de maná!"; }

// ---------- Conjurador ----------
Conjurador::Conjurador(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
                       int inv, bool elem)
    : Mago(v, a, f, m, arma1, arma2), invocaciones(inv), controlaElementos(elem), es("conjurador") {}

string Conjurador::quees() const { return es; }
int Conjurador::getInvocaciones() const { return invocaciones; }
bool Conjurador::controlaLosElementos() const { return controlaElementos; }
string Conjurador::lanzarHechizo() const { return "¡Invocación ancestral!"; }

// ---------- Brujo ----------
Brujo::Brujo(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
             int corr, bool pacto)
    : Mago(v, a, f, m, arma1, arma2), corrupcion(corr), pactoOscuro(pacto), es("brujo") {}

string Brujo::quees() const { return es; }
int Brujo::getCorrupcion() const { return corrupcion; }
bool Brujo::tienePactoOscuro() const { return pactoOscuro; }
string Brujo::lanzarHechizo() const { return "¡Pacto prohibido!"; }

// ---------- Nigromante ----------
Nigromante::Nigromante(int v, int a, int f, int m, shared_ptr<armas> arma1, shared_ptr<armas> arma2,
                       int ej, bool r)
    : Mago(v, a, f, m, arma1, arma2), ejercitoMuerto(ej), reencarna(r), es("nigromante") {}

string Nigromante::quees() const { return es; }
int Nigromante::getEjercitoMuerto() const { return ejercitoMuerto; }
bool Nigromante::reencarnaHabilitado() const { return reencarna; }
string Nigromante::lanzarHechizo() const { return "¡Ejército de los caídos!"; }
