#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int pos = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());


    /*if (vest[pos].consultar_DNI() == est.consultar_DNI()) { // Si ja hi era modifiquem l'estudiant
        if (vest[pos].te_nota()) decrementar_interval(int(vest[pos].consultar_nota()));
        vest[pos] = est;
        if (est.te_nota()) incrementar_interval(int(est.consultar_nota()));
        b = true;
    } */

    if (est.te_nota()){
        for (int i = nest; i > pos; i--) {
            vest[i+1] = vest[i]; //Movem tots els elements una posició amunt
        }
        vest[pos] = est;
        b = false;
        ++nest; //incrementem el nombre d'estudiants
        incrementar_interval(int(est.consultar_nota()));
    }
}


void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    b = false;

    if (vest[pos].consultar_DNI() == dni) {
        if (vest[pos].te_nota()) decrementar_interval(int(vest[pos].consultar_nota()));

        for (int i = pos; i < nest-1; i++) {
            vest[i] = vest[i+1];

        }
         --nest;
        b = true;
    }


}

