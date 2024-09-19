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
    std::cout<<"Se ha eliminado el Material "<<this->Nombre<<std::endl;
}

void MaterialBibliografico::setEstado(string Estado)
{
    this->Prestado = Estado;
}

string MaterialBibliografico::getAutor()
{
    return this->Autor;
}

string MaterialBibliografico::getNombre()
{
    return this->Nombre;
}

string MaterialBibliografico::getEstado()
{
    return this->Prestado;
}



