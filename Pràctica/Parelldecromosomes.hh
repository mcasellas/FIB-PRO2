#ifndef _PARELL_CROMOSOMES_HH_
#define _PARELL_CROMOSOMES_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <vector>
using namespace std;

#endif


class Parell_cromosomes {

public:

    // Creadora per defecte
    Parell_cromosomes();
    
    void consultar_c1() const;
    
    void consultar_c2() const;
    
    int consultar_gen(int numero, int gen) const;
    


private:
    vector<int> c1;
    vector<int> c2;

};
