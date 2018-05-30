#include <iostream>
#include <list>
using namespace std;


void eliminar_de_la_llista(list<int>& llista) {

    int num;
    cin >> num;

    bool trobat = false;
    list<int>::iterator it = llista.begin();

    while (it != llista.end() and not trobat) {
        if ((*it) == num){
            trobat = true;
            it = llista.erase(it);
        }

        else it++;
    }
}

void calcular(list<int>& llista) {

    int minim = 0,
        maxim = 0,
        suma = 0;

    for (list<int>::iterator it = llista.begin(); it != llista.end(); it++) {

        suma += (*it);

        if (it == llista.begin()) {
            minim = (*it);
            maxim = (*it);
        }
        else {
            if ((*it) < minim) minim = (*it);
            if ((*it) > maxim) maxim = (*it);
        }
    }

    double mitjana = double(suma)/llista.size();

    if (minim != 0 and maxim != 0) cout << minim << " " << maxim << " " << mitjana << endl;
    else cout << minim << endl;
}

int main() {
    list<int> llista;
    list<int>::iterator it = llista.begin();

    int accio;

    while (cin >> accio and accio != 0) {

        if (accio == -1) {
            int num;
            cin >> num;

            llista.insert(it, num);
        }
        else if (accio == -2) eliminar_de_la_llista(llista);

        calcular(llista);
    }

}
