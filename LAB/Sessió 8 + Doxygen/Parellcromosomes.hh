/** @file Parellcromosomes.hh
 @brief Especificació de la clase Parellcromosomes.
 */

#ifndef _PARELLCROMOSOMES_HH_
#define _PARELLCROMOSOMES_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>

using namespace std;
#endif


/** @class Parell_cromosomes
 @brief Representa un parell de cromosomes.
 
 Permet llegir i consultar un parell concret de cromosomes.
 */
class Parell_cromosomes {
    
public:
    
    // Creadora per defecte
    /** @brief Creadora por defecte.
     
     S'executa automàticament al declarar un parell de cromosomes.
     \pre <em>Cert</em>
     \post El resultat és un parell de cromosomes sense gens.
     */
    Parell_cromosomes();
    
    
    /** @brief Creuadora de dos cromosomes.
     
     \pre El paràmetre explicit conté el parell de cromosomes del pare, de la mare, el seleccionat pel pare, el per la mare i el punt de tall.
     \post Es retorna el parell de cromosomes corresponent al fill, després del creuament utilitzant el punt de tall.
     */
    void creuament(Parell_cromosomes pare, Parell_cromosomes mare, int npare, int nmare, int k, int lo);
    
    
    /** @brief Lectora del material genètic dels cromosomes no sexuals.
     
     \pre El paràmetre implicit està inicialitzat amb el parell de cromosomes corresponent. El paràmetre explícit conté la llargada del parell concret que es vol afegir. El canal d'entrada conté la informació genètica del parell de cromosomes no sexuals que es volen llegir.
     \post Es guarda la informació dins de cada cromosoma del parell.
     */
    void llegir_cromosomes_no_sexuals(int llargada_parell);
    

    /** @brief Lectora del material genètic dels cromosomes sexuals.

     \pre El paràmetre implicit està inicialitzat amb el parell de cromosomes corresponent. El paràmetre explícit conté la llargada del cromosoma X, del Y i el sexe del individu.
     \post Es guarda la informació dins de cada cromosoma del parell d'acord amb el sexe (si és femení, els dos tindràn la mateixa llargada, ja que seràn tots dos X).
     */
    void llegir_cromosomes_sexuals(int llargada_lx, int llargada_ly, char sexe);
    
    /** @brief Escriptora d'un cromosoma.

     \pre El paràmetre implicit està inicialitzat amb el parell de cromosomes corresponent. El paràmetre explícit conté quin dels dos cromosomes s'ha d'imprimir pel canal de sortida (1 o 2).
     \post S'escriuen pel canal de sortida els al·lels del cromosoma corresponent.
     */
    void escriure_cromosoma(int num) const;
    
    
    
    
private:
    /** @brief Cromosoma 1 */
    vector<int> c1;
    /** @brief Cromosoma 2 */
    vector<int> c2;
    
    /** @brief Consultora d'un cromosoma.
     
     \pre El paràmetre explicit està inicialitzat amb el número del cromosoma que es vol consultar (0 pel primer, 1 pel segon).
     \post Es retorna el vector corresponent al cromosoma del paràmetre explícit.
     */
    vector<int> consultar_cromosoma(int num) const;
    
};

#endif

