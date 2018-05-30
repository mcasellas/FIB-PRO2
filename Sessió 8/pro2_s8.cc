/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

using namespace std;

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
    Lavadora lab;
    Cubeta cub;

    int opcio;
    while (cin >> opcio) {

        if (opcio == -1) { //Inicialitzar lavadora
            int pes_maxim;
            cin >> pes_maxim;
            bool color = readbool();

            lab.inicializar(pes_maxim, color);

         }

        else if (opcio == -2) {
            int pes_maxim;
            cin >> pes_maxim;
            bool color = readbool();
            Prenda p (pes_maxim, color);

            lab.anadir_prenda(p);
        }

        else if (opcio == -3) {
            int pes_maxim;
            cin >> pes_maxim;
            bool color = readbool();
            Prenda p (pes_maxim, color);

            cub.anadir_prenda(p);
        }

        else if (opcio == -4) {
             cub.completar_lavadora(lab);
        }

        else if (opcio == -5) {
             lab.lavado();
        }

        else if (opcio == -6) {
            cout << "   Cubeta: " << endl;
            cub.escribir();
        }

        else if (opcio == -7) {
            cout << "   Lavadora: " << endl;
            lab.escribir();
        }

        else return 0;


    }
}
