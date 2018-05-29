/** @file Especie.cc
 @brief Codi de la classe Especie
 */

#include "Especie.hh"

using namespace std;

Especie::Especie() {}

void Especie::establir_genetica(){
    
    cin >> n;

    for (int i = 0; i <= n; i++){
        int longit;
        cin >> longit;
        l.push_back(longit);
    }
    
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
