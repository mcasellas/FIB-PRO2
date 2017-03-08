#include <iostream>
#include <vector>
using namespace std;

#include "Cjt_estudiants.hh"


int main() {
    
    // DECLARACIONS
    Cjt_estudiants cest;
    int op;
    
    //Introdueix el conjunt
    cout << "Introdueix el conjunt:" << endl;
    cest.llegir();
    
    cout << "Introdueix l'ordre (-1 fins a -5)" << endl;
    cin >> op;
    /*
     anadir un nuevo estudiante (opcion -1)
     consultar la nota de un estudiante a partir de su DNI (opcion -2)
     modificar la nota de un estudiante (opcion -3)
     redondear la nota a todos los estudiantes del conjunto (opcion -4)
     escribir el conjunto de estudiantes (opcion -5)
     */
    
    
    
    if (op == -1) {
        Estudiant est;
        
        est.llegir();
        cest.afegir_estudiant(est);
    }
    
    else if (op == -2) {
        cout << "Introdueix el DNI:" << endl;
        int dni;
        cin >> dni;
        cout << cest.consultar_estudiant(dni).consultar_nota() << endl;
    }
    
    else if (op == -3) {
        
    }
    
    else if (op == -4) {
        
    }
    
    else {
        cest.escriure();
    }
    
    
}
