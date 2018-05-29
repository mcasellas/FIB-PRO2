#include <iostream>
#include <vector>
using namespace std;

#include "vectorIOestudiants.hh"
#include "Estudiant.hh"

int busqueda_lin_vest(const vector<Estudiant> v, int dni) {
    int mida = v.size();

    for (int i = 0; i < mida; i++) {
        if (dni == v[i].consultar_DNI()) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<Estudiant> v;
    leer_vector_estudiants(v); // Entrem els elements

    Estudiant est;

    cout << "Entra el DNI a buscar" << endl;
    int dni;
    cin >> dni;

    int i = busqueda_lin_vest(v,dni);

    if (i == -1) cout << "L'estudiant no està en el vector" << endl;

    else if (!v[i].te_nota()) cout << "L'estudiant està al vector però no te nota" << endl;

    else cout << "L'estudiant està en el vector i té de nota: " << v[i].consultar_nota() << endl;
}
