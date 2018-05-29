#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
  Cjt_estudiants c;
  c.llegir();
  int op; 
  cin >> op;
  while (-3 <= op and op <= -1) {
    if (op == -1) {   // afegir estudiant
      Estudiant est; 
      est.llegir();
      bool trobat; 
      c.afegir_estudiant(est,trobat);
      if (trobat)  cout << endl << "L'estudiant " << est.consultar_DNI() << " ja hi era" << endl << endl;
    }
    else if (op == -2) {   // escriure conjunt
      cout << endl << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
    }
    else {   // escriure interval
      double inf, sup; 
      cin >> inf >> sup; 
      cout << endl << "Interval [" << inf << ", " << sup << "]" << endl; 
      c.escriure_i(inf,sup);
    }
    cin >> op;
  }
}

