#include "PilaIOParInt.hh"


void llegirPilaParInt(stack<ParInt>& p){
  ParInt ent;
  while (ent.llegir()){
    p.push(ent);
  }
}

void escriurePilaParInt(stack<ParInt> p){
    while (not p.empty()) {
        p.top().escriure();
        p.pop();
    }
}
