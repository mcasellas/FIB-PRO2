#include "Poblacio.hh"

using namespace std;

Poblacio::Poblacio(){
    
}

Individu Poblacio::buscar_individu(string nom){
    
    map<string,Individu>::const_iterator it;
    
    it = poble.find(nom);
    
    return (*it).second;
    

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



void Poblacio::escriure_arbre(string nom){ // Mirar estrucutra per amplada !!!!!!!
    
    queue<string> cua;
    
    buscar_descendents(cua, buscar_individu(nom));
    
    cout << "  Nivell 0: " << nom << endl;;
    
    
    int nivell = 1;
    int parelles = 2;
    
    
    while (not cua.empty()){
        
        
        
        cout << "  Nivell " << nivell << ": ";
        
        int i = 0;
        
        while (i < parelles and not cua.empty()) {
            if (cua.front() != "$") cout << cua.front();
            if (i < parelles-1) cout << " ";
            cua.pop();
            ++i;
        }
        
        cout << endl;
        ++nivell;
        parelles *= 2;
        
        while (cua.front() == "$") cua.pop();
    }
    
    
}

void Poblacio::buscar_descendents(queue<string>& cua, Individu ind){
    
    
    if (ind.consultar_pare() == "$") {
        cua.push("$");
        cua.push("$");
    }
    else {
        cua.push(ind.consultar_pare());
        cua.push(ind.consultar_mare());
        buscar_descendents(cua, buscar_individu(ind.consultar_pare()));
        
        
        buscar_descendents(cua, buscar_individu(ind.consultar_mare()));
    }
    
}


void Poblacio::completar_arbre(string nom){
    
    queue<string> cua_arbre, cua_parcial;
    
    
    
    buscar_descendents(cua_arbre, buscar_individu(nom));
    
}


void Poblacio::escriure_poblacio() const{
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        cout << "  " << (*it).first << " X" << (*it).second.consultar_sexe() << " (" << (*it).second.consultar_pare() << ',' << (*it).second.consultar_mare() << ')' << endl;
    }
    cout << endl;
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
