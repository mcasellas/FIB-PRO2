#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    b = false;
    int dni = est.consultar_DNI();

    int pos = cerca_dicot(vest, 0, nest-1, dni); //miro la posició on es o on hauria d'anar

    if (vest[pos].consultar_DNI() == dni) b = true; //l'estudiant ja existex

    else { //l'estudiant no existeix
        ++nest;
        for (int i = nest-1; i > pos; i--) {
            vest[i] = vest[i-1]; //movem tots els elements cap a la dreta
        }

        vest[pos] = est; //Sempre substituim, si existeix el crearem, sinò el modificarem.

        if (est.te_nota()) {
            ++nest_amb_nota;
            suma_notes += est.consultar_nota();

        }
    }


}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {

    int pos = 0;
    bool trobat = false;

    //anem a buscar la posició on hi ha el DNI.
    while (not trobat and pos < nest) {
        if (vest[pos].consultar_DNI() == dni) trobat = true;
        ++pos;
    }

    if (not trobat) b = false; //no el podem esborrar

    else { //el podem esborrar
        b = true;

        if (vest[pos-1].te_nota()) {
            suma_notes -= vest[pos-1].consultar_nota();
            --nest_amb_nota;
        }
        for (int z = pos; z < nest; ++z) {
            vest[z-1] = vest[z];
        }
        --nest;
    }



}
