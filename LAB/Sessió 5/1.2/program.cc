#include "PilaIOEstudiants.hh"
#include "Estudiant.hh"

void entrar_estudiant() {

}


int main() {
    stack<Estudiant> pila;

    llegirPilaEstudiant (pila);
    int dni;
    cin >> dni;

    int valor = trobar_element(pila, dni);

    escriurePilaEst(pila);

    if (element != -1) cout << element << endl;

    else cout << "No trobat" << endl;
}
