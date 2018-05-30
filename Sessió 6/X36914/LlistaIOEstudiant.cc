#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
    list<Estudiant>::iterator it = l.begin();

    Estudiant est;
    bool acabat = false;


    while (not acabat) {
        est.llegir();
        if (est.consultar_DNI() == 0) acabat = true;
        else {
            l.insert(it,est);
        }

    }
}


/*void EscriureLlistaEstudiant(list<Estudiant>& l) {

}*/
