#include <iostream>
#include "LlistaIOEstudiant.hh"
using namespace std;

double buscar_estudiant(list<Estudiant> llista, int dni, bool& trobat) {

    for (list<Estudiant>::iterator it = llista.begin(); it != llista.end(); ++it) {
        if ((*it).consultar_DNI() == dni) {
            trobat = true;
            if ((*it).te_nota()) return (*it).consultar_nota();
            else return -1;
        }
    }


    return -1;
}

int main () {
    list<Estudiant> llista;
    int dni;

    LlegirLlistaEstudiant(llista);
    cin >> dni;

    bool trobat = false;

    int nota = buscar_estudiant(llista,dni,trobat);

    if (not trobat) cout << "El estudiante no está en la lista" << endl;

    else if (nota == -1) cout << "El estudiante está en la lista, pero no tiene nota" << endl;

    else cout << "El estudiante está en la lista y su nota es " << nota << endl;

}
