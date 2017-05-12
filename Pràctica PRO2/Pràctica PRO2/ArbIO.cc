
#include "ArbIO.hh"

void llegir_arbre_string(Arbre<string>& a){
/* Pre: a es buit; el canal estandar d'entrada conte el recorregut en preordre
   d'un arbre binari A d'enters marcat amb "marca" */  
/* Post: a = A */
  Arbre<string> a1;
  Arbre<string> a2;
  string x;
  cin >> x;
  if (x != "$") {
    llegir_arbre_string(a1);
    llegir_arbre_string(a2);
    a.plantar(x,a1,a2);
  }
}

void escriure_arbre_string(Arbre<string>& a) {
/* Pre: cert */ 
/* Post: El canal estandar de sortida conte el recorregut en inordre d'a */
  if (not a.es_buit()) {
    Arbre<string> a1;
    Arbre<string> a2;
    string x = a.arrel();
    a.fills(a1,a2);
    escriure_arbre_string(a1);
    cout << " " << x;
    escriure_arbre_string(a2);
    a.plantar(x,a1,a2);
  }
}
