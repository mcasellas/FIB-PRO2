#include "PilaIOParInt.hh"
#include "ParInt.hh"

int trobar_element(stack<ParInt> pila, int n, bool trobat) {
    while (not pila.empty()) {
        if (pila.top().primer() == n) {
            trobat = true;
            return pila.top().segon();
        }
        pila.pop();
    }
    trobat = false;
}

int main() {
    stack<ParInt> pila;

    llegirPilaParInt(pila);
    int n;
    bool trobat;
    cin >> n;

    int element = trobar_element(pila, n, trobat);

    escriurePilaParInt(pila);

    if (trobat) cout << element << endl;

    else cout << "No trobat" << endl;
}
