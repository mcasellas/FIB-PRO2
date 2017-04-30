#include "Poblacio.hh"

using namespace std;

Poblacio::Poblacio(){
    
}

Individu Poblacio::buscar_individu(string nom){
    return poble[nom];
}

bool Poblacio::comprovar_individu(string nom){
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        if ((*it).first == nom) return true;
    }
    
    return false;
}


void Poblacio::afegir_individu(string nom, const Individu& p){

    poble[nom] = p;
}



void Poblacio::escriure_arbre() const{

}


void Poblacio::completar_arbre() const{

}


void Poblacio::escriure_poblacio() const{
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        cout << (*it).first << " X" << (*it).second.consultar_sexe() << " (" << (*it).second.consultar_pare() << ',' << (*it).second.consultar_mare() << ')' << endl;
    }
}


void Poblacio::llegir_individu(Especie esp){
    
    Individu ind;
    string nom;
    
    
    cerr << "Introdueix el nom" << endl;
    cin >> nom;
    
    if (not comprovar_individu(nom)) {
        ind.llegir_individu(esp);

        afegir_individu(nom,ind);
    }
    
    else cout << "error" << endl;

}
