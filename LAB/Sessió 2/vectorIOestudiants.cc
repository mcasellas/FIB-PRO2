#include "vectorIOestudiants.hh"
#include "Estudiant.hh"

/* Leer vector */
void leer_vector_estudiants(vector<Estudiant>& v) {// version accion
  cout<<"Escriu la mida del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  
  cout<<"Escriu DNI i nota:"<<endl;

  for (int i=0; i<numEst;++i)
    v[i].llegir();
}

/* Escribir vector */
void escribir_vector_estudiants(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
      if (v[i].consultar_nota() != -2) v[i].escriure();
}
