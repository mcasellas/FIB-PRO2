#include <iostream>
#include "LlistaIOParInt.hh"
using namespace std;

void buscar_elements (list<ParInt> llista, int num) {
    int nelements = 0, suma = 0;

    for (list<ParInt>::iterator it = llista.begin(); it != llista.end(); it++) {
        if ((*it).primer() == num) {
            ++nelements;
            suma += (*it).segon();
        }
    }

    cout << num << " " << nelements << " " << suma << endl;
}

int main () {
    list<ParInt> llista;

    int num;

    LlegirLlistaParInt(llista);

    cin >> num;

    buscar_elements(llista,num);

}
