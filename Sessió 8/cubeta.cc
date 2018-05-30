#include "Cubeta.hh"
#include "Lavadora.hh"
#include "Prenda.hh"


void anadir_prenda(const Prenda& p) {
    if (p.consul_color()) ropacolor.push(p);

    else ropablanca.push(p);
}

void completar_lavadora(Lavadora& lav){
    int pmax = lav.consultar_peso_maximo();
    int pes = lav.consultar_peso();


    if (pes < pmax) {
        if (lav.consultar_color()) { // Roba color
            if (pes+ropacolor.top.consultar_peso() < pmax)
            lav.anadir_prenda(ropacolor.top);
        }

        else {
            if (pes+ropablanca.top.consultar_peso() < pmax)
            lav.anadir_prenda(ropablanca.top);
        }
    }
}

void escribir() const{
    if (lav.consultar_color()) {
        cout << "Ropa de color de la cubeta: " << endl;

    }
}
