#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void llegir_map(map<string,int>& d) {
    string cogn;

    while (cin >> cogn and cogn != ".") {
        d[cogn];
    }
}

void llegir_participants(set<string>& part) {
    string cogn;

    while (cin >> cogn and cogn != ".") {
        part.insert(cogn);
    }
}

void actualitzar_frequencia(map<string,int>& d, set<string>& part) {
    for (set<string>::iterator it = part.begin(); it != part.end(); ++it) {
        map<string, int>::iterator itmap = d.find((*it));
        (*itmap).second++;
    }
}

void imprimir_map(map<string,int> d, int n) {
    cout << "Totes les activitats:";

    for (map<string,int>::iterator it = d.begin(); it != d.end(); ++it) {
        if ((*it).second == n) cout << " " << (*it).first;
    }
    cout << endl;
    
    cout << "Cap activitat:";
    for (map<string,int>::iterator it = d.begin(); it != d.end(); ++it) {
        if ((*it).second == 0) cout << " " << (*it).first;
    }
    cout << endl;
    
}

int main () {
    map<string,int> d; //Map de participants
    llegir_map(d);
    
    int n; //Número d'activitats programades
    cin >> n;

    for (int i = 0; i < n; i++){
        set<string> part;
        llegir_participants(part);
        actualitzar_frequencia(d,part);
    }
    
        imprimir_map(d,n);
   
    
    




}
