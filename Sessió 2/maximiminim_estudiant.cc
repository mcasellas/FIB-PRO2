#include <iostream>
#include <vector>
#include "vectorIOestudiants.hh"
using namespace std;


pair<int,int> max_min(const vector<Estudiant>& v){
    int mida = v.size();
    int posmin = 0,
        posmax = 0,
        dni_max,
        dni_min;

    double min, max;

    min = max = v[0].consultar_nota(); //CUIDAO
    dni_max = dni_min = v[0].consultar_DNI();

    for (int i = 0; i < mida; ++i) {
        if (v[i].te_nota()) {

            if (max == v[i].consultar_nota()) {
                if (v[i].consultar_DNI() < dni_max) {
                    max = v[i].consultar_nota();
                    posmax = i;
                    dni_max = v[i].consultar_DNI();
                }
            }

            else if (max < v[i].consultar_nota()) {
                max = v[i].consultar_nota();
                posmax = i;
                dni_max = v[i].consultar_DNI();
            }

            if (min > v[i].consultar_nota()) {
                min = v[i].consultar_nota();
                posmin = i;
                dni_min = v[i].consultar_DNI();
            }

            else if (min == v[i].consultar_nota()) {
                if (v[i].consultar_DNI() < dni_min) {
                    min = v[i].consultar_nota();
                    posmin = i;
                    dni_min = v[i].consultar_DNI();
                }
            }
        }
    }
    return make_pair(posmax,posmin);
}

int main() {
    vector<Estudiant> v;
    leer_vector_estudiants(v);


    pair<int, int> par = max_min(v);




    cout << "Estudiant amb la nota màxima: ";
    v[par.first].escriure();
    cout << endl;

    cout << "Estudiant amb la nota mínima: ";
    v[par.second].escriure();
    cout << endl;



}
