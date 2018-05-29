/** @file Especie.hh
    @brief Especificació de la clase Especie.
*/
#ifndef _ESPECIE_HH_
#define _ESPECIE_HH_


#ifndef NO_DIAGRAM

#include <iostream>
#include <vector>

#endif

using namespace std;

/** @class Especie
    @brief Representa una espècie.

    Permet llegir i consultar les dades inicials del programa i consultar-ne els valors posteriorment.
*/
class Especie {

public:

    /** @brief Creadora por defecte.


        S'executa automàticament al declarar una especie.
        \pre <em>Cert</em>.
        \post El resultat és una espècie sense genetica inicial.
    */
    Especie();
    
    
    /** @brief Lectora de les dades que determinen la genètica d'una espècie.
     
     \pre Es preparen pel canal d'entrada els valors de <em>N</em>, (N+1) elements corresponents a la longitud de cada parell de cromosomes, la longitud del cromosoma x i la del y. <em>iparell</em> és el número del parell al que volem accedir (1 <= i <= N).
     \post El resultat és la llargada dels cromosomes x.
     */
    void establir_genetica();

    
    /** @brief Consultora del nombre de cromosomes normals.

        \pre El paràmetre implicit està inicialitzat.
        \post El resultat és el nombre de cromosomes normals.
    */
    int consultar_n() const;
    
    
    /** @brief Consultora de la llargada dels cromosomes X.
     
     \pre El paràmetre implicit està inicialitzat.
     \post El resultat és la llargada dels cromosomes X.
    */
    int consultar_lx() const;
    
    
    /** @brief Consultora de la llargada dels cromosomes Y.
     
     \pre El paràmetre implicit està inicialitzat.
     \post El resultat és la llargada dels cromosomes Y.
    */
    int consultar_ly() const;
    
    
    /** @brief Consultora de la longitud d'un determinat parell de cromosomes.
     
     \pre El paràmetre implicit està inicialitzat, iparell conté el subindex del parell que es vol consultar.
     \post El resultat és la llargada del parell de cromosomes corresponent a iparell.
    */
    int consultar_ln(int iparell) const;


private:
    /** @brief Número de cromosomes no sexuals (normals) */
    int n;
    
    /** @brief Llargada dels cromosomes sexuals X */
    int lx;
    
    /** @brief Llargada dels cromosomes sexuals Y */
    int ly;
    
    /** @brief Llargada de cada parell de cromosomes
     
        Cada posició del vector correspon a la llargada del número de parell de cromosomes corresponent a aquesta */
    vector<int> l;
};
 #endif
