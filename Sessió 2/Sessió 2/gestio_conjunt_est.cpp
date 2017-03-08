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
        /*
     anadir un nuevo estudiante (opcion -1)
     consultar la nota de un estudiante a partir de su DNI (opcion -2)
     modificar la nota de un estudiante (opcion -3)
     redondear la nota a todos los estudiantes del conjunto (opcion -4)
     escribir el conjunto de estudiantes (opcion -5)
     */
    
    cout << "Introdueix l'ordre (-1 fins a -5)" << endl;
    
    while (cin >> op) {
   
        

        
        if (op == -1) { //entra un nou estudiant
            Estudiant est;
            cout << "Entra el DNI i la nota:" << endl;
            est.llegir();
            cest.afegir_estudiant(est);
        }
        
        else if (op == -2) { //consulta la nota d'un estudiant a través del DNI
            cout << "Introdueix el DNI de l'estudiant:" << endl;
            int dni;
            cin >> dni;
            
            cout << cest.consultar_estudiant(dni).consultar_nota() << endl;
        }
        
        else if (op == -3) { // modifica la nota d'un estudiant
            
        }
        
        else if (op == -4) { // Arrodonir la nota
            
        }
        
        else { // Escriure tots els elements
            cest.escriure();
        }
        
        cout << "Introdueix l'ordre (-1 fins a -5)" << endl;
        
    }
    
    
}
