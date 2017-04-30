#include "Parellcromosomes.hh"

using namespace std;

Parell_cromosomes::Parell_cromosomes(){
    
}

/** Parell_cromosomes creuament(Parell_cromosomes pare, Parell_cromosomes mare, int npare, int nmare, int k){
    
} **/

int Parell_cromosomes::consultar_gen(int numero, int gen) const{
    if (numero == 1) {
        return c1[gen];
    }
    else {
        return c2[gen];
    }
}

void Parell_cromosomes::llegir_cromosomes_no_sexuals(int llargada_parell){
    int alel;
    for (int i = 0; i < llargada_parell; i++){
        cin >> alel;
        c1.push_back(alel);
    }

    for (int i = 0; i < llargada_parell; i++){
        cin >> alel;
        c2.push_back(alel);
    }
}

void Parell_cromosomes::llegir_cromosomes_sexuals(int primer, int segon, char sexe){
    int alel;
    for (int i = 0; i < primer; i++){
        cin >> alel;
        c1.push_back(alel);
    }
    
    if (sexe == 'X') segon = primer;
    
    for (int i = 0; i < segon; i++){
        cin >> alel;
        c2.push_back(alel);
    }
}
