#include "PilaIOEstudiant.hh"


void llegirPilaEstudiant(stack<Estudiant>& est){
  Estudiant est;
  while (est.llegir() and est.consultar_DNI() != 0){
    p.push(est);
  }
}

void escriurePilaEstudiant(stack<Estudiant> est){ //NO FA RES EN EL PROGRAMA PERO L'ARXIU ÉS IN-OUT
    while (not est.empty()) {
        est.top().escriure();
        est.pop();
    }
}
