#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(string Nombre, string Autor, string ISBN, string Prestado)
{
    this ->Nombre = Nombre;
    this ->Autor = Autor;
    this ->ISBN = ISBN;
    this ->Prestado = Prestado;
}

MaterialBibliografico::~MaterialBibliografico()
{
    std::cout<<"Se ha eliminado la clase padre"<<std::endl;
}

void MaterialBibliografico::setEstado(string Estado)
{
    this->Prestado = Estado;
}

string MaterialBibliografico::getEstado()
{
    return this->Prestado;
}

void MaterialBibliografico::Mostrarinfo()
{
    cout<<"Nombre del Libro: "<<this->Nombre<<std::endl;
    cout<<"Autor del Libro: "<<this-> Autor<<std::endl;
    cout<<"ISBN del Libro: "<<this->ISBN<<std::endl;
    cout<<"Estado del Libro: "<<this->Prestado<<std::endl;
    return;
}

