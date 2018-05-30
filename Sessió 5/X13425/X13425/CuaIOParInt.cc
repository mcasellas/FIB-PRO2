#include "CuaIOParInt.hh"


void llegirCuaParInt(queue<ParInt>& c) {
    ParInt ent;

    while (ent.llegir()) {
        c.push(ent);
    }
    
    
}

void escriureCuaParInt(queue<ParInt> c) {
    while (not c.empty()) {
        c.front().escriure();
        c.pop();
    }
}
