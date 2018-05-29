#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Partit {
    int e1;
    int e2;
};

struct Resultat {
    int num;
    int punts;
    int marcats;
    int rebuts;
};

typedef vector<Partit> Fila;
typedef vector<Fila> Matriu;



bool ordenacio (Resultat a, Resultat b) {
    if (a.punts > b.punts) return true;
    if (b.punts > a.punts) return false;
    if (a.marcats-a.rebuts > b.marcats-b.rebuts) return true;
    if (a.marcats-a.rebuts < b.marcats-b.rebuts) return false;
    return a.num < b.num;

}


int main() {
    int n;
    cin >> n;

    Matriu hola(n,Fila(n));
    vector<Resultat> res (n);

    for (int i = 0; i < n; i++) {

        res[i].num = i+1;

        for (int j = 0; j < n; j++) {
            cin >> hola[i][j].e1;
            cin >> hola[i][j].e2;
        }
    }

    for (int k = 0; k < n; k++) { //fila
        for (int l = 0; l < n; l++) { //columna
            if (k != l) {
                res[k].marcats += hola[k][l].e1; //sumem als marcats corresponents a la fila, el primer component.
                res[k].rebuts += hola[k][l].e2;
                res[l].marcats += hola[k][l].e2;
                res[l].rebuts += hola[k][l].e1;

                if (hola[k][l].e1 > hola[k][l].e2) res[k].punts += 3;
                else if (hola[k][l].e1 < hola[k][l].e2) res[l].punts += 3;
                else {
                    ++res[k].punts;
                    ++res[l].punts;
                }
            }
        }
    }

    sort(res.begin(), res.end(), ordenacio);

    for (int z = 0; z < n; z++) {
        cout << res[z].num << ' ' << res[z].punts << ' ' << res[z].marcats << ' ' << res[z].rebuts << endl;
    }

}
