#include "Individu.hh"

using namespace std;

Individu::Individu(){
    
}

/**void reproduir(Individu pare, Individu mare, string npare, string nmare, string nfill, Especie esp){
    
}**/

char Individu::consultar_sexe() const{
    return sexe;
}


Parell_cromosomes consultar_parell_cromosomes(int i);


string Individu::consultar_pare() const{
    return pare;
}


string Individu::consultar_mare() const{
    return mare;
}

void Individu::escriure_genotip(Especie esp) const{
    for (int i = 0; i < adn.size(); i++) {
        if (i == 0){
            cout << "X: ";
            for (int j = 0; i < adn[i].size(); i++) {
                cout << adn[i].consultar_gen(1, j);
            }
            
            cout << "X: ";
            for (int j = 0; i < adn[i].size(); i++) {
                cout << adn[i].consultar_gen(2, j);
            }
        }
    }
}


void Individu::llegir_individu(Especie esp){
    cerr << "Introdueix el sexe" << endl;
    cin >> sexe;
    
    cerr << "Introdueix les dades genètiques" << endl;
    

    // Cromosomes sexuals
        Parell_cromosomes parell;
        parell.llegir_cromosomes_sexuals(esp.consultar_lx(), esp.consultar_ly(), sexe);
        adn.push_back(parell);
    
    
    // Cromosomes no sexuals
    for (int i = 1; i <= esp.consultar_n(); i++){
        Parell_cromosomes parell;
        parell.llegir_cromosomes_no_sexuals(esp.consultar_ln(i));
        adn.push_back(parell);
    }
    
    mare = "$";
    pare = "$";
}
