using namespace std;
#include "Estudiant.hh"
#include <vector>

int main() {
    int numest,
        numassig,
        assigsel,
        assig;

    vector<bool> condicio (numassig,false);

    for (int i = 0; i < assigsel) { // Establim quins elements agafarem
        cin >> assig;
        condicio[assig-1] = true;
    }

    Estudiant est;

    for (int j; j < numest; j++) {
        double mitjana;
        double nota;
        cin >> est.dni;

        for (int k = 0; k < numassig; k++) {
            cin >> nota;
            if (condicio[k]) {
                mitjana += nota;
            }

            est.nota = mitjana/assigsel;
            escriure(est);
        }

    }

}
