/** @file Poblacio.hh
 @brief Especificació de la clase Població.
 */

#include <iostream>
#include "Individu.hh"
#include <map>

using namespace std;

class Poblacio {

public:

    // Creadora per defecte
    Poblacio();

    // Consultora
    Individu buscar_individu(string nom);

    
    void afegir_individu(const Individu& p);
    
    void llegir_primers(int nindiv);
    
    // Escriptura
    void escriure_arbre(const Individu& indiv) const;
    
    void completar_arbre() const;
    
    void escriure_poblacio() const;

private:
    map<string,Individu> poble;
};


