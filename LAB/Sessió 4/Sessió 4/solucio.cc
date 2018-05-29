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
        
        if (est.te_nota()) {
            incrementar_interval(est.consultar_nota());
        }
    }
    
    

}


void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    b = false;

    int pos = cerca_dicot(vest, 0, nest-1, dni);


    if (vest[pos].consultar_DNI() == dni) {
        
        if (vest[pos].te_nota()){
            decrementar_interval(vest[pos].consultar_nota());
        }
        
        
        
        for (int i = pos; i < nest-1; i++) {
            vest[i] = vest[i+1];

        }
        
        --nest;

        b = true;
        
     
    }
    

}




