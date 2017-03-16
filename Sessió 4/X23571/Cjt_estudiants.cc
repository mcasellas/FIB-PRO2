#include <algorithm>
#include "Cjt_estudiants.hh"


Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  primer_est_amb_nota=0;
  vest = vector<Estudiant>(MAX_NEST);
}


int Cjt_estudiants::mida() const {
  return nest;
}

int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}
 

void Cjt_estudiants::ordenar() {
  sort(vest.begin(), vest.begin() + nest, Estudiant::comp_nota_dni);
}


void Cjt_estudiants::llegir() {
  cin >> nest; 
  for (int i = 0; i < nest; ++i) {
    vest[i].llegir();
    if (not vest[i].te_nota())  primer_est_amb_nota++;
  }
  ordenar();
}


void Cjt_estudiants::escriure() const {
  cout << "Estudiants sense nota " << primer_est_amb_nota << endl;
  cout << "Estudiants amb nota " << nest-primer_est_amb_nota << endl;
  for (int i = 0; i < nest; ++i) vest[i].escriure();
}


int Cjt_estudiants::cerca_lineal_per_dni(const vector<Estudiant> &v, int ini, int fi, int dni_b) {
  int i = ini; 
  while (i<=fi and v[i].consultar_DNI() != dni_b) i++;
  return i;
}



int Cjt_estudiants::cerca_dicot_per_dni(const vector<Estudiant> &vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  while (left <= right) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i-1;
    else if (x > vest[i].consultar_DNI()) left = i+1;
    else return i;
  }
  // i es la posicio, si l'element existeix
  return left;  
}  


int Cjt_estudiants::cerca_dicot_per_nota_dni(const vector<Estudiant> &v, int left, int right, const Estudiant& e) {
  while (left <= right) { 
    int i = (left + right)/2;
    if (Estudiant::comp_nota_dni(e,v[i])) right = i - 1; 
    else if (Estudiant::comp_nota_dni(v[i],e)) left = i + 1; 
    else return i;
  } 
    return left;
}  

