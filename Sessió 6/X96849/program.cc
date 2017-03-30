#include <iostream>
#include "ArbIOParInt.hh"
using namespace std;

pair<int, int> cerca_arbre(Arbre<ParInt> arb, int num, int profunditat) {
    pair<int, int> p;
    
    p.first = -1; // Per si no el trobem
    
    if (!arb.es_buit()){ // Si l'arbre no és buit
        if (arb.arrel().primer() == num){ // Si trobem l'element a l'arrel
            p.first = profunditat;
            p.second = arb.arrel().segon();
        }
        else {
            Arbre<ParInt> a1;
            Arbre<ParInt> a2;
            
            arb.fills(a1, a2); //Obtenim els fills de l'arrel
            
            p = cerca_arbre(a1, num, profunditat+1); // Busquem pel node esquerra
            if (p.first == -1) p = cerca_arbre(a2, num, profunditat+1); // En cas de no trobar-lo, fem el mateix pel dret
        }
    }
    
    return p;
}

int main () {
    Arbre<ParInt> arb;
    
    llegir_arbre_parint(arb);
    
    int num;
    
    while (cin >> num) {
        pair<int, int> resultat = cerca_arbre(arb, num, 0);
        
        if (resultat.first == -1) cout << "-1" << endl;
        
        else cout << num << " " << resultat.second << " " << resultat.first << endl;
    }
}
