#include <iostream>
#include <vector>
using namespace std;

#include "Cjt_estudiants.hh"

void arrodonir(Cjt_estudiants& cest) {
    for (int i = 0; i < cest.mida()+1; i++) {
        
        double nota = ((int) (10.0 * (cest.consultar_iessim(i).consultar_nota() + 0.05))) / 10.0;
        
        Estudiant est (cest.consultar_iessim(i).consultar_DNI());
        
        est.afegir_nota(nota);
        
        cest.modificar_iessim(i,est);

    }
}

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
    
    while (cin >> op and op != -6) {
   
        

        
        if (op == -1) { //entra un nou estudiant
            Estudiant est;
            cout << "Entra el DNI i la nota:" << endl;
            est.llegir();
            
            if (cest.existeix_estudiant(est.consultar_DNI())) cout << "L'estudiant ja existeix" << endl;
            
            else cest.afegir_estudiant(est);
        }
        
        else if (op == -2) { //consulta la nota d'un estudiant a través del DNI
            cout << "Introdueix el DNI de l'estudiant:" << endl;
            int dni;
            cin >> dni;
            
            if (!cest.existeix_estudiant(dni)) cout << "L'estudiant " << dni << " no existeix" << endl;
            
            else if (cest.consultar_estudiant(dni).te_nota()) {
                cout << "L'estudiant " << dni << " té nota " << cest.consultar_estudiant(dni).consultar_nota() << endl;
            }
            
            
            else cout << "L'estudiant " << dni << " no té nota" << endl;
        }
        
        else if (op == -3) { // modifica la nota d'un estudiant
            Estudiant est;
            cout << "Entra el DNI del estudiant a modificar i la nova nota:" << endl;
            est.llegir();
            
            if (!cest.existeix_estudiant(est.consultar_DNI())) cout << "No existeix l'estudiant" << endl;
            
            else cest.modificar_estudiant(est);
            
            
        }
        
        else if (op == -4) { // Arrodonir la nota
            arrodonir(cest);
        }
        
        else if (op == -5){ // Escriure tots els elements
            cest.escriure();
        }
        
        cout << "Introdueix l'ordre (-1 fins a -5)" << endl;
        
    }
    
    
}
