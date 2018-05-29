#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
    
    for (int i = primer_est_amb_nota; i < nest; i++ ){
        if (vest[i].consultar_nota() >= nota_b) return i;
    }
    return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat) {
    
    trobat = false;
    
    int cerca = cerca_lineal_per_dni(vest, 0, nest-1, est.consultar_DNI());
    
    
    if (cerca < nest) trobat = true; // S'ha trobat el DNI
    
    if (not trobat) {
        
        
        if (est.te_nota()) { // L'inserim entre els que tenen nota
            int pos = cerca_dicot_per_nota_dni(vest, primer_est_amb_nota, nest-1, est);
            
            ++nest;
            
            for (int i = nest-1; i > pos; i--) {
                vest[i] = vest[i-1];
            }
            
            vest[pos] = est;
            
            
        }
        
        else { // L'inserim entre els que NO tenen nota
            int pos = cerca_dicot_per_dni(vest, 0, primer_est_amb_nota-1, est.consultar_DNI());
            
            ++nest;
            
            for (int i = nest-1; i > pos; i--) {
                vest[i] = vest[i-1];
            }
            
            vest[pos] = est;
            
            ++primer_est_amb_nota;
        }
    }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
    
    
    int inf = posicio_nota(nota_i);
    int sup = posicio_nota(nota_s);
    
    if (inf != sup and sup != nest) {
        for (int i = inf; i < sup; ++i) {
            vest[i].escriure();
        }
        if (vest[sup].consultar_nota() == nota_s) vest[sup].escriure();
        for (int j = sup+1; j < nest and vest[j].consultar_nota() == nota_s; ++j) {
            vest[j].escriure();
        }
    }
    else if (sup == nest) for (int i = inf; i < nest; i++) vest[i].escriure();
    else for (int i = inf; i < nest and vest[i].consultar_nota() == nota_s; ++i) vest[i].escriure(); 
     
     
    
}




