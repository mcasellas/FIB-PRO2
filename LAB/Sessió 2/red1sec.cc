#include "Estudiant.hh"


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

int main() {
    Estudiant est;

    cout << "Escribe un estudiante <DNI nota>" << endl;
    est.llegir();
    int dni = est.consultar_DNI();

    while (dni != 0) {
        if (est.te_nota()) {
            redondear_e_a(est);
        }
        est.escriure();
        cout << "Escribe un estudiante <DNI nota>" << endl;
        est.llegir();
        dni = est.consultar_DNI();


  }

}

