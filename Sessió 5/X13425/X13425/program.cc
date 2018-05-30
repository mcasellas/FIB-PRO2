#include <iostream>
#include "CuaIOParInt.hh"
using namespace std;

void repartir_cues(queue<ParInt> cua, queue<ParInt>& cua1, queue<ParInt>& cua2) {
    int temps1 = 0, temps2 = 0;
    
    while (not cua.empty()){
        if (temps1 == temps2) {
            cua1.push(cua.front());
            temps1 += cua.front().segon();
        }
        
        else if (temps1 < temps2) {
            cua1.push(cua.front());
            temps1 += cua.front().segon();
        }
        else {
            cua2.push(cua.front());
            temps2 += cua.front().segon();
        }
        
        cua.pop();
    }
}

int main () {
    queue<ParInt> cua;
    
    llegirCuaParInt(cua);
    
    queue<ParInt> cua1;
    queue<ParInt> cua2;
    
    repartir_cues(cua, cua1, cua2);
    
    escriureCuaParInt(cua1);
    cout << endl;
    escriureCuaParInt(cua2);
}
