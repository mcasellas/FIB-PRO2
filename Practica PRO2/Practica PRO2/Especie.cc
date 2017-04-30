#include "Especie.hh"

using namespace std;

Especie::Especie() {
    n = 0;
    lx = 0;
    ly = 0;
}

void Especie::establir_genetica(){
    cerr << "Introdueix la n:" << endl;
    cin >> n;

    cerr<< "Introdueix les longituds dels cromosomes (" << n+1 << " valors)" <<  endl;

    for (int i = 0; i <= n; i++){
        int longit;
        cin >> longit;
        l.push_back(longit);
    }

    cerr << "Introdueix la lx i ly:" << endl;

    cin >> lx >> ly;
}

int Especie::consultar_n() const {
    return n;
}

int Especie::consultar_lx() const {
    return lx;
}

int Especie::consultar_ly() const {
    return ly;
}

int Especie::consultar_ln(int nparell) const {
    return l[nparell];
}
