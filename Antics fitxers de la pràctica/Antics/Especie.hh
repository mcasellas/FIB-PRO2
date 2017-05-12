/** @file Especie.hh
    @brief Especificació de la clase Espècie.
*/

#ifndef _ESPECIE_HH_
#define _ESPECIE_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <vector>
using namespace std;
#endif



/** @class Espècie
    @brief Representa una espècie

    Permet llegir les dades inicials del programa i consultar-ne els valors posteriorment.
*/
class Especie {

public:

    // Constructores

    /** @brief Creadora por defecte.

        S'executa automàticament al declarar una especie.
        \pre <em>cierto</em>
        \post El resultat és una espècie sense genetica inicial
    */
    Especie();


    //Consultores
    /** @brief Consultora del nombre de cromosomes normals.

        \pre El paràmetre implicit està inicialitzat.
        \post El resultat és el nombre de cromosomes normals.
    */
    void consultar_n() const;
    
    /** @brief Consultora de la llargada dels cromosomes X.
     
     \pre El paràmetre implicit està inicialitzat.
     \post El resultat és la llargada dels cromosomes X.
    */
    void consultar_lx() const;
    
    /** @brief Consultora de la llargada dels cromosomes Y.
     
     \pre El paràmetre implicit està inicialitzat.
     \post El resultat és la llargada dels cromosomes Y.
    */
    void consultar_ly() const;
    
    /** @brief Consultora de la longitud d'un determinat parell de cromosomes.
     
     \pre El paràmetre implicit està inicialitzat, nparell conté el subindex del parell que es vol consultar.
     \post El resultat és la llargada del parell de cromosomes corresponent a nparell.
    */
    void consultar_ln(int nparell) const; 

    // Lectura
    
    /** @brief Lectora de les dades que determinen la genètica d'una espècie.
     
     \pre Es preparen pel canal d'entrada els valors de N, la longitud de cada parell de cromosomes (N+1), la longitud dels cromosomes x i la dels y.
     \post El resultat és la llargada dels cromosomes x.
     */
    void establir_genetica();

private:
    int n, lx, ly;
    vector<int> l;
};

