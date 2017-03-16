#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest; // vector amb els estudiants del conjunt 
  int nest; // nombre d'estudiants del conjunt
  static const int MAX_NEST = 60; // nombre maxim d'estudiants del conjunt
  int imax; // posici� de l'estudiant amb nota m�xima

  /*
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel dni dels estudiants i no cont� estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - imax �s la posici� de l'estudiant amb nota m�xima a vest[0..nest-1];
       cas que hi hagi m�s d'un estudiant amb nota m�xima, imax assenyala el de dni menor 
       si no hi ha cap estudiant amb nota imax val -1
  */

  void ordenar();
  /* Pre: cert */
  /* Post: el elements del par�metre impl�cit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0<=left, right<vest.size(), right>=left+1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */
 
  void recalcular_posicio_imax();
  /* Pre: el campo imax del par�metro impl�cito no necesariamente tiene
     el valor que le corresponde */
  /* Post: el camp imax cont� la posici� de l'element del par�metre impl�cit
     amb la nota m�s gran; si no hi ha cap estudiant amb nota, val -1 */
  
public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */

  void modificar_estudiant(const Estudiant &est, bool& b);
  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni d'est; si b, aquest ha quedat sustituit per est */

  void eliminar_estudiants_sense_nota();
  /* Pre: cert */
  /* Post: el par�metre implicit no cont� cap estudiant sense nota */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'estudiants del par�metre impl�cit */

  Estudiant estudiant_nota_max() const;
  /* Pre: el par�metre impl�cit cont� almenys un estudiant amb nota */
  /* Post: el resultat �s l'estudiant del par�metre impl�cit amb nota
     m�xima; si en t� m�s d'un, �s el de DNI m�s petit */ 
 
  // Lectura i escriptura
	
  void llegir();
  /* Pre: cert */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida 
     els estudiants del conjunt que cont� el par�metre 
     impl�cit en ordre ascendent per DNI */

};

#endif

