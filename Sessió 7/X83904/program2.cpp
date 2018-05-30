#include <iostream>
#include <string>
#include <set>
using namespace std;

void participants_activitat(set<string>& aux) {
    string cogn;
    while (cin >> cogn and cogn != ".") { //Entrem els cognoms dels participants sense repetició
        aux.insert(cogn);
    }
}

void augmentar_frequencia(set<pair<string,int> >& seter, set<string> aux) {

    set<pair<string,int> >::iterator it1 = seter.begin();

    for (set<string>::iterator it = aux.begin(); it < aux.end(); ++it) { //Ens anem moment pels elements d'aux
        string elem = *it;
        it1 = seter.find(elem);
    }

}

int main () {
    /*bool comp(pair<string,int> a, pair<string,int> b){
        return a.first < b.first;
    }*/

    set<pair<string,int> > seter;

    string cogn;
    cin >> cogn;

    while (cin >> cogn and cogn != ".") { //Entrem els cognoms en el set
        pair<string,int> a;
        a.first = cogn;
        a.second = 0;
        seter.insert(a);
    }

    int n; //Activitats programades
    cin >> n;

    for (int i = 0; i < n; i++){
        set<string> aux;

        participants_activitat(aux);

        augmentar_frequencia(seter, aux);

    }




}
