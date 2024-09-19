#include "libro.h"

#include <string>

libro::libro(string Nombre, string Autor, string ISBN, string Prestado, string FechaDePublicacion, string resumen) : MaterialBibliografico(Nombre, Autor, ISBN, Prestado)
{

  this -> FechaDePublicacion = FechaDePublicacion;
  this -> resumen = resumen;
  
}

libro::~libro()
{
  cout<<"Se ha eliminado el libro: "<< this-> Nombre<<std::endl;
}

void libro::MostrarInfo() const
{
  cout<<"Nombre del Libro: "<<this->Nombre<<", ";
  cout<<"Autor del Libro: "<<this-> Autor<<", ";
  cout<<"ISBN del Libro: "<<this->ISBN<<", ";
  cout<<"Estado del Libro: "<<this->Prestado<<", ";
  cout<<"Fecha de Publicacion del Libro: "<<this->FechaDePublicacion<<", ";
  cout<<"Resumen del Libro: "<<this->resumen<<", ";
  cout<<" "<<std::endl;
}
