#include "Estudiant.hh"
#include "vectorIOestudiants.hh"
#include <vector>

// Redondear, version funcion

Estudiant redondear_e_f(const Estudiant& est)
/* Pre: est tiene nota */
/* Post: el resultado es un estudiante como est pero con la nota redondeada */
{
  Estudiant est2(est.consultar_DNI());
  double notaR = ((int) (10.0 * (est.consultar_nota() + 0.05))) / 10.0;
  est2.afegir_nota(notaR);
  return est2;
}

// Redondear, version accion

void redondear_e_a(Estudiant& est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

void comprov_nota(vector<Estudiant> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].te_nota()) {
          redondear_e_a(v[i]);

        }
    }
}

int main() {
  vector<Estudiant> v;
  leer_vector_estudiants(v);

  comprov_nota(v);

  escribir_vector_estudiants(v);
}
