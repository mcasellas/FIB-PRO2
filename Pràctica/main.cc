#include <iostream>
#include <string>
#include "Especie.hh"
#include "Poblacio.hh"


using namespace std;

int main(){

    Especie esp;

    esp.establir_genetica();

    Poblacio poble;
    
    int numindiv;
    cin >> numindiv;

    poble.llegir_primers(numindiv);
    
    string accio;

    while (cin >> accio and accio != "acabar"){
        if (accio == "anadir_individuo"){
            Individu ind;
            ind.llegir();
            poble.afegir_individu(ind);
        }

        else if (accio == "reproduccion_sexual"){
            string nmare, npare, nfill;
            cin >> nmare >> npare >> nfill;
            
            Individu pare, mare, fill;
            
            mare = poble.buscar_individu(nmare);
            pare = poble.buscar_individu(npare);
            
            fill.reproduir(pare, mare, npare, nmare, nfill);

            poble.afegir_individu(fill);
        }

        else if (accio == "escribir_arbol_genealogico"){
            Individu ind;
            poble.escriure_arbre(ind);
        }

        else if (accio == "completar_arbol_genealogico"){
            poble.completar_arbre();
        }

        else if (accio == "escribir_poblacion"){
            poble.escriure_poblacio();
        }

        else if (accio == "escribir_genotipo"){
            Individu ind;
            string nom;
            cin >> nom;
            
            ind = poble.buscar_individu(nom);
            
            ind.escriure_genotip();
        }
    }

}
