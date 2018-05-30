#include <iostream>
#include <vector>
#include "vectorIOestudiants.hh"
using namespace std;


pair<double, double> max_min(const vector<Estudiant>& v){
    int mida = v.size();
    double max,
        min;

    if (v[0].te_nota()) {
        max = v[0].consultar_nota();
        min = v[0].consultar_nota();
    }

    for (int i = 1; i < mida; ++i) {
        if (v[i].te_nota()) {
             if (min > v[i].consultar_nota()) {
                 min = v[i].consultar_nota();
             }

             if (max < v[i].consultar_nota()) {
                 max = v[i].consultar_nota();
             }
        }
    }
    return make_pair(max,min);
}

int main() {
    vector<Estudiant> v;
    leer_vector_estudiants(v);
      
    pair<double, double> par = max_min(v);

    cout << "Nota maxima: " << par.first << " i la nota mínima és: " << par.second << endl;



}
