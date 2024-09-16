#include "libro.h"
#include <string>

libro::libro(string Nombre, string Autor, string ISBN, bool Prestado, string FechaDePublicacion): MaterialBibliografico(string Nombre, string Autor, string ISBN, bool Prestado)
{

  this-> FechaDePublicacion = FechaDePublicacion;
  
}

libro::~libro()
{
  cout<<"Se ha eliminado el libro: "<< this-> Nombre<<std::endl;
}
