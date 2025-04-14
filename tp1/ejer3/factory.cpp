#include "/home/paradigmas/tp1/ejer2/mago.cpp"
#include "/home/paradigmas/tp1/ejer2/guerrero.cpp"
#include "/home/paradigmas/tp1/ejer2/magic.cpp"
#include "/home/paradigmas/tp1/ejer2/combat.cpp"


class factory{
    public:
    static shared_ptr<Personaje> crear_personaje(int tipo, int cual) {
        //int tipo = rand() % 2; // 0 = mago, 1 = guerrero
    
        int v = 100;   // 
        int a = 10 + rand() % 21;   // armadura: 10–30
        int f = 5 + rand() % 16;    // fuerza: 5–20
    
        // Crear armas
        
        shared_ptr<armas> arma1 = nullptr;
        shared_ptr<armas> arma2 = nullptr;
        
        
        
        tipo = tipo %2;
        if (tipo == 0) { // MAGO
            int m = 20 + rand() % 31; // maná: 20–50
            cual = cual % 4;
    
            switch (cual) {
                case 0:
                    return make_shared<Hechicero>(v, a, f, m, arma1, arma2, "Howarts", rand() % 10);
                case 1:
                    return make_shared<Conjurador>(v, a, f, m, arma1, arma2, rand() % 6, rand() % 2);
                case 2:
                    return make_shared<Brujo>(v, a, f, m, arma1, arma2, rand() % 100, rand() % 2);
                case 3:
                    return make_shared<Nigromante>(v, a, f, m, arma1, arma2, rand() % 200, rand() % 2);
            }
        } else { // GUERRERO
            int r = 10 + rand() % 21; // resistencia: 10–30
            cual = cual % 5;
    
            switch (cual) {
                case 0:
                    return make_shared<Barbaro>(v, a, f, r, arma1, arma2, rand() % 2, 10 + rand() % 11);
                case 1:
                    return make_shared<Paladin>(v, a, f, r, arma1, arma2, rand() % 2, rand() % 5);
                case 2:
                    return make_shared<Caballero>(v, a, f, r, arma1, arma2, "Teniente", rand() % 2);
                case 3:
                    return make_shared<Mercenario>(v, a, f, r, arma1, arma2, rand() % 500, rand() % 2);
                case 4:
                    return make_shared<Gladiador>(v, a, f, r, arma1, arma2, rand() % 20, "Espada");
            }
        }
    
        return nullptr; // fallback
    }

    static shared_ptr<armas> crear_arma(int tipo, int cual){
        //int tipo = rand()%2;
        tipo = tipo%2;
        if (tipo) {
            // Arma de combate
            cual = cual % 5;
            int d = 10 + rand() % 11;   // daño: 10–20
            int f = 1 + rand() % 5;     // filo: 1–5
            int t = 10 + rand() % 31;   // durabilidad: 10–40
    
            switch (cual) {
                case 0:
                    return make_shared<HachaSimple>(d, f, t, 15, "Hierro");
                case 1:
                    return make_shared<HachaDoble>(d, f, t, f * 2, "Hierro");
                case 2:
                    return make_shared<Espada>(d, f, t, 70, "Acero");
                case 3:
                    return make_shared<Lanza>(d, f, t, 60, true);
                case 4:
                    return make_shared<Garrote>(d, f, t, true, 40);
            }
        } 
        else {
            // Arma mágica
            cual = cual % 4;
            int d = 5 + rand() % 11;     // daño: 5–15
            int m = 10 + rand() % 21;    // maná: 10–30
            int t = 5 + rand() % 11;     // tiempo de recarga: 5–15
    
            switch (cual) {
                case 0:
                    return make_shared<Baston>(d, m, t, 120, true);
                case 1:
                    return make_shared<LibroDeHechizos>(d, m, t, 6, "Mago de Oz");
                case 2:
                    return make_shared<Pocion>(d, m, t, "curacion", 50);
                case 3:
                    return make_shared<Amuleto>(d, m, t, "fuego", "maldición de atadura");
            }
        }
        return nullptr;
    }
    
};