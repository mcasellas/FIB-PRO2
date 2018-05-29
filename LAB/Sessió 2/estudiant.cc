#include "estudiant.hh"
using namespace std;

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  amb_nota = false;
}

Estudiant::Estudiant(int dni)
{

  this->dni = dni;
  amb_nota = false;
}

Estudiant::~Estudiant(){}

void Estudiant::afegir_nota(double nota)
{




  this->nota = nota;
  amb_nota = true;
}

void Estudiant::modificar_nota(double nota)
{

  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  return amb_nota;
}

double Estudiant::consultar_nota() const
{

  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

void Estudiant::llegir()
{
  cin >> dni;

  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x;
    amb_nota = true;
  }
  else amb_nota = false;
}

void Estudiant::escriure() const
{
  if (amb_nota)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
