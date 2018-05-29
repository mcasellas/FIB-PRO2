#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b){
    int dni = est.consultar_DNI();
    
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    
    if (vest[pos].consultar_DNI() != dni) {
        ++nest;
        
        if (est.te_nota()) {
            
            if (est.consultar_nota() != 10) incrementar_interval(int(est.consultar_nota()));
            else incrementar_interval(9);
        
        }
        
        for (int i = nest-1; i > pos; i--) vest[i] = vest [i-1];
        
        vest[pos] = est;
        
        b = false;
    }
    
    else b = true;
}


void Cjt_estudiants::esborrar_estudiant(int dni, bool& b){
    
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    
    if (vest[pos].consultar_DNI() == dni) {
        
        if (vest[pos].te_nota()) {
            
            if (vest[pos].consultar_nota() != 10) decrementar_interval(int(vest[pos].consultar_nota()));
            else decrementar_interval(9);
        }
        
        for (int i = pos; i < nest-1; i++) {
            vest[i] = vest[i+1];
        }
        
        --nest;
        
        
        b = true;
    }
    
    else b = false;
}
