#include "ArbIOest.hh"

void llegir_arbre_est(Arbre<Estudiant>& a) {
    Arbre<Estudiant> a1;
    Arbre<Estudiant> a2;
    
    Estudiant est; //Llegim un parell de nombres
    est.llegir();

    if (est.consultar_DNI() != 0 and nota )
    llegir_arbre_est(a1);
    llegir_arbre_est(a2);
    a.plantar(est, a1, a2);
    
}
