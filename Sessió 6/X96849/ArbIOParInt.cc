#include "ArbIOParInt.hh"

void llegir_arbre_parint(Arbre<ParInt>& a) {
    Arbre<ParInt> a1;
    Arbre<ParInt> a2;
    
    ParInt ent; //Llegim un parell de nombres
    ent.llegir();
    
    if (ent.primer() != 0 and ent.segon() != 0) {
        llegir_arbre_parint(a1);
        llegir_arbre_parint(a2);
        a.plantar(ent, a1, a2);
    }
}
