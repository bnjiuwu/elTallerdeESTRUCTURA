#include "revista.h"
#include <iostream>

revista:: revista(string Nombre,string Autor, string ISBN, string Prestado,int numeroEdicion, string mesPublicacion):MaterialBibliografico(Nombre, Autor, ISBN, Prestado)
{
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
};

revista::~revista(){
    cout<<"Se ha eliminado la revista: "<< this-> Nombre<<std::endl;
}

void revista::MostrarInfo() const
{
    cout<<"Nombre de la Revista: "<<this->Nombre<<", ";
    cout<<"Autor de la Revista: "<<this-> Autor<<", ";
    cout<<"ISBN de la Revista: "<<this->ISBN<<", ";
    cout<<"Estado de la Revista: "<<this->Prestado<<".";
    cout<<"Edicion de la Revista: "<<this->numeroEdicion<<", ";
    cout<<"Mes de Publicacion de la Revista: "<<this->mesPublicacion<<".";
    cout<<" "<<std::endl;
}
