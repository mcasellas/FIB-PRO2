#include "CuaIOEstudiant.hh"


void LlegirCuaEstudiant(queue<Estudiant> &q) {
    int n;
    Estudiant est;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        est.llegir();
        q.push(est);
    }
    
}

void EscriureCuaEstudiant(queue<Estudiant> q) {
    while (not q.empty()) {
        q.front().escriure();
        
        q.pop();
    }
}
