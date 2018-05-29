#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;


class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per nota.  
  
  vector<Estudiant> vest; // estudiants del conjunt

  int nest; // nombre d'estudiants del conjunt 

  int primer_est_amb_nota;// la posicio on estaria el primer estudiant amb nota

  static const int MAX_NEST = 25; // nombre maxim d'elements del conjunt

  /* 
     Invariant de la representació: 

     vest[0..nest-1] no conté estudiants repetits, a més està ordenat
     creixentment per nota i en cas d'empat creixentment per DNI. En 
     particular, els estudiants sense nota precedeixen als estudiants 
     amb nota.
    
     0 <= primer_est_amb_nota <= nest

     primer_est_amb_nota indica: 1) la posicio del primer estudiant amb 
     nota, si hi ha estudiants amb nota; 2) la posicio on s'hauria d'inserir 
     el primer estudiant amb nota, si no hi ha estudiants amb nota.
     
     0 <= nest <= vest.size() = MAX_NEST
  */

  void ordenar();
  /* Pre: cert */
  /* Post: el elements del paràmetre implícit passen a estar ordenats
     creixentment per nota i en cas d'empat per DNI. */


  static int cerca_lineal_per_dni(const vector<Estudiant> &v, int ini, 
                                  int fi, int dni_b); 
  /* Pre: 0 <= ini <= fi < nest */
  /* Post: si v[ini...fi] conté un estudiant amb DNI igual a dni_b, el
     resultat és la seva posició; si no, el resultat és fi+1 */     


  static int cerca_dicot_per_dni(const vector<Estudiant> &v, 
			 int left, int right, int x);
  /* Pre: v.size() > 0, els elements de v[left...right] estan ordenats 
     creixentment per DNI,
     0 <= left <= v.size(), -1 <= right < v.size(), left <= right + 1 */
  /* Post: si hi ha un estudiant amb el DNI x a v[left..right], el resultat 
     és la posició que hi ocupa; si no, és la posició que hauria d'ocupar */
 

  static int cerca_dicot_per_nota_dni(const vector<Estudiant> &v, int left, 
                                      int right, const Estudiant& e);
  /* Pre: v.size() > 0, els elements de v[left...right] estan ordenats 
     creixentment per nota i en cas d'empat per DNI,
     0 <= left <= v.size(), -1 <= right < v.size(), left <= right + 1 */
  /* Post: si hi ha un estudiant amb el DNI i la nota del estudiant e a 
     v[left..right], el resultat és la posició que hi ocupa; si no, és 
     la posició que hauria d'ocupar */
 

  int posicio_nota(double nota_b) const;
  /* Pre: 0 <= nota_b <= nota_maxima() */
  /* Post: el resultat és la posició del primer estudiant amb nota major 
     o igual que nota_b a vest[0...nest-1]. Si no hi ha estudiants amb 
     nota major o igual que nota_b, el resultat és nest. */



public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */


  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& trobat);
  /* Pre: el paràmetre implícit no està ple */
  /* Post: trobat indica si el p.i. original conté un estudiant amb 
     el dni d'est. Si trobat és cert el p.i. no es modifica; i si 
     trobat és fals, s'ha afegit l'estudiant est al paràmetre implícit */


  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'estudiants del paràmetre implícit */


  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre maxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */


  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal estàndar d'entrada un enter (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndar d'entrada */


  void escriure() const ;
  /* Pre: cert */
  /* Post: escriu pel canal estàndar el numero d'estudiants sense nota, 
     el numero d'estudiants amb nota i la llista d'estudiants del paràmetre 
     implícit en ordre ascendent per nota i en cas d'empat per DNI */


void escriure_i(double nota_i, double nota_s) const;
  /* Pre: 0 <= nota_i <= nota_s <= nota_maxima() */
  /* Post: s'han escrit pel canal estàndar de sortida els estudiants
     del paràmetre implícit amb nota dins del interval tancat
     [nota_i, nota_s]. Els estudiants s'escriuen en ordre ascendent
     per nota i en cas d'empat en ordre ascendent per DNI */

};

#endif









