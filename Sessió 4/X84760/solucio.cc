#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    b = true; // Ja s'ha trobat l'estudiant
    
    int pos = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
    
    if (vest[pos].consultar_DNI() != est.consultar_DNI()) {
        
        ++nest; //incrementem el nombre d'estudiants
        
        for (int i = nest-1; i > pos; i--) {
            vest[i] = vest[i-1]; //Movem tots els elements una posició amunt
        }
        vest[pos] = est;
        b = false;
        
        recalcular_posicio_imax();
        
        
    }
}

void Cjt_estudiants::eliminar_estudiants_sense_nota() {
    
    vector<Estudiant> ambnota (nest);
    
    int j = 0;
    
    for (int i = 0; i < nest; i++) {

        if (vest[i].te_nota()) {
            ambnota[j] = vest[i];
            ++j;
        }
    }
    
    nest = j;
    
    for (int k = 0; k < nest; ++k) {
        vest[k] = ambnota[k];
    }
    
    recalcular_posicio_imax();
}
