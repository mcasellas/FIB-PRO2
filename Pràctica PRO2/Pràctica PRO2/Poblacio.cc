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
    
    buscar_descendents_cua(cua, buscar_individu(nom));
    
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

void Poblacio::buscar_descendents_cua(queue<string>& cua, Individu ind){
    
    
    if (ind.consultar_pare() == "$") {
        cua.push("$");
        cua.push("$");
    }
    else {
        cua.push(ind.consultar_pare());
        cua.push(ind.consultar_mare());
        buscar_descendents_cua(cua, buscar_individu(ind.consultar_pare()));
        
        
        buscar_descendents_cua(cua, buscar_individu(ind.consultar_mare()));
    }
    
}


void Poblacio::completar_arbre(string nom){
    
    Arbre<string> aparcial;
    
    //llegir_arbre_string(aparcial);
    

    
    
    // Eliminar desprès
    buscar_arbre_complet(aparcial, nom);
    
    escriure_arbre_string(aparcial);
}

void Poblacio::buscar_arbre_complet(Arbre<string>& arbre, string nom){
    
    Individu ind = buscar_individu(nom);
    
    Arbre<string> a1, a2;
    a1.a_buit();
    a2.a_buit();
    
    if (nom != "$") {
        buscar_arbre_complet(a1,ind.consultar_pare());
        buscar_arbre_complet(a2,ind.consultar_mare());
        arbre.plantar(nom,a1,a2);
    }
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
