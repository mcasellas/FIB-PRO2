#include <iostream>
using namespace std;

#include "vectorIOint.hh"


void canvi_valors(vector<int>& v, int x, int y) {
    int aux;
    aux = v[x];
    v[y] = v[x];
    v[x] = v[aux];
}

int main() {
    vector<int> v;
    leer_vector_int(v);
    cout << "Escriu les dues posicions a intercanviar: " << endl;
    int x, y;
    cin >> x >> y;

    canvi_valors(v,x,y);

    escribir_vector_int(v);
}
