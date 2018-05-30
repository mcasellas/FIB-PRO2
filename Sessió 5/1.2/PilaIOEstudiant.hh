#ifndef PILA_IO_PARINT
#define PILA_IO_PARINT

#include "Estudiant.hh"
#include <iostream>
#include <stack>
using namespace std;

void llegirPilaEstudiant(stack<Estudiant>& est);
// Pre: p és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han apilat a p els elements llegits fins al 0 0 (no inclòs)

void escriurePilaEstudiant(stack<Estudiant> est);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de p

#endif
