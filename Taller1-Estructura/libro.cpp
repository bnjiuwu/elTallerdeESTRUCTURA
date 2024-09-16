#include "libro.h"
#include "MaterialBibliografico.cpp"
#include <string>

libro::libro(string Nombre, string Autor, string ISBN, bool Prestado, string FechaDePublicacion): MaterialBibliografico(Nombre, Autor, ISBN, Prestado)
{

  this-> FechaDePublicacion = FechaDePublicacion;
  
}

libro::~libro()
{
  cout<<"Se ha eliminado el libro: "<< this-> Nombre<<std::endl;
}
