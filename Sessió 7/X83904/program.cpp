#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void llegir_set(map<string,int>& d) {
    string cogn;

    while (cin >> cogn and cogn != ".") {
        d[cogn];
    }
}

void llegir_participants(set<string> part) {
    string cogn;

    while (cin >> cogn and cogn != ".") {
        part.insert(cogn);
    }
}

void actualitzar_frequencia(map<string,int>& d, set<string> part) {

}

void imprimir_map(map<string,int> d, int n) {

}

int main () {
    map<string,int> d;

    int n; //Activitats programades
    cin >> n;

    for (int i = 0; i < n; i++){
        set<string> part;
        llegir_participants(part);
        actualitzar_frequencia(d,part);
        imprimir_map(d,n);
    }




}
