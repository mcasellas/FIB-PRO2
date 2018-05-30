#include "Estudiant.hh"
#include <vector>

void leer_vector_estudiants(vector<Estudiant>& v) {// version accion

  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);


  for (int i=0; i<numEst;++i)
    v[i].llegir();
}


void nota_maxima(vector<Estudiant> v, vector<Estudiant>& resu) {
    int pos = 0;

    resu[pos] = v[0];
    // Entrem el primer element

    for (int i = 1; i < v.size(); i++) {
        if (v[i-1].consultar_DNI() != v[i].consultar_DNI()) { //Mirem si canvia el DNI
            ++pos; //avancem una posició al vector de resultats i afegim DNI i nota inicial
            resu[pos] = v[i];
        }

        else { // Si el DNI és el mateix
            if (v[i].te_nota()) { // Només modificarem si té nota v[i]
                if (not resu[pos].te_nota()) { // Si resu no te nota
                    resu[pos] = v[i];
                }

                else if (resu[pos].consultar_nota() < v[i].consultar_nota()){
                    resu[pos] = v[i];
                }
            }


        }
    }
}

void escriure_vector(const vector<Estudiant>& v){
    int i = 0;
    int nEst = v.size();
    bool finish = false;
    //Escrivim els elements que no tenen DNI = 0
    while(i < nEst and !finish){
        if(v[i].Estudiant::consultar_DNI() != 0) v[i].Estudiant::escriure();
        else finish = true;
        ++i;
    }
}


int main() {
  vector<Estudiant> v;
  leer_vector_estudiants(v); //Tots els elements inicials.

  vector<Estudiant> resu (v.size()); //Vector on guardarem tots els resultats amb DNI únic.

  nota_maxima(v,resu); //Obtenim el vector de resultats.

  escriure_vector(resu); //Traiem els elements del vector Resultats (menys els elements on el DNI es 0).
}
