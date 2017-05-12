/** @file Individu.hh
 @brief Especificació de la clase Individu.
*/

#include <iostream>
#include "Parelldecromosomes.hh"

using namespace std;


class Individu {

public:

    // Creadora per defecte
    Individu();

    // Creadores
    void reproduir(Individu pare, Individu mare, string npare, string nmare, string nfill);

    // Consultores:
    char consultar_sexe() const;

    string consultar_pare() const;

    string consultar_mare() const;

    void escriure_genotip() const;

    // Lectura:
    void llegir();

private:
    char sexe;
    vector<Parell_cromosomes> Celula;
    string pare;
    string mare;
};

