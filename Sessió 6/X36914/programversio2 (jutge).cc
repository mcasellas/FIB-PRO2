#include <iostream>
#include "LlistaIOEstudiant.hh"
using namespace std;

int buscar_estudiant (list<Estudiant> llista, int dni) {

    int nvegades = 0;

    for (list<Estudiant>::iterator it = llista.begin(); it != llista.end(); ++it) {
        if ((*it).consultar_DNI() == dni) {
            ++nvegades;
        }
    }

    return nvegades;
}

int main () {
    list<Estudiant> llista;
    int dni;

    LlegirLlistaEstudiant(llista);
    cin >> dni;

    int vegades = buscar_estudiant(llista,dni);

    cout << dni << " " << vegades << endl;
}
