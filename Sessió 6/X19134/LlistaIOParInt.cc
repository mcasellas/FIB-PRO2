#include "LlistaIOParInt.hh"


void LlegirLlistaParInt(list<ParInt>& l) {
    list<ParInt>::iterator it = l.begin();

    ParInt ent;

    while (ent.llegir()) {
        l.insert(it,ent);
    }

}

/*
void EscriureLlistaParInt(const list<ParInt>& l) {

    if (not l.empty()) {

        for (list<ParInt>::iterator it = l.begin(); it != l.end(); ++it) {
            cout << (*it).escriure() << endl;
        }


    }

}
*/
