#include <iostream>
#include "CuaIOEstudiant.hh"
using namespace std;

int trobar_dni (queue<Estudiant> cua, int dni, bool& trobat) {
    
    trobat = false;
    
    while (not cua.empty()) {
        if (cua.front().consultar_DNI() == dni) {
            trobat = true;
        
            if (cua.front().te_nota()) return cua.front().consultar_nota();
            else return -1;
        }
        
        cua.pop();
    }
    
    return -1;
}

int main () {
    
    queue<Estudiant> cua;
    
    LlegirCuaEstudiant(cua);
    
    int dni;
    cin >> dni;
    bool trobat;
    
    EscriureCuaEstudiant(cua);
    
    int nota = trobar_dni(cua, dni, trobat);
    
    if (not trobat) cout << "No trobat" << endl;
    else if (nota == -1) cout << "No te nota" << endl;
    else cout << "La nota es " << nota << endl;
    
}
