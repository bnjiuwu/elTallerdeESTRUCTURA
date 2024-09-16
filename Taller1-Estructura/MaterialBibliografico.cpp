#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(string Nombre, string Autor, string ISBN, bool Presstado)
{
    this ->Nombre = Nombre;
    this ->Autor = Autor;
    this ->ISBN = ISBN;
    this ->Prestado = Prestado;
}

MaterialBibliografico::~MaterialBibliografico()
{
    std::cout<<"Se ha eliminado "<<std::endl;
}

string MaterialBibliografico::getNombre()
{
    return this->Nombre;
}

int MaterialBibliografico::Mostrarinfo()
{
    cout<<"Nombre del Libro: "<<this->Nombre<<std::endl;
    cout<<"Autor del Libro: "<<this-> Autor<<std::endl;
    cout<<"ISBN del Libro: "<<this->ISBN<<std::endl;
    string estado = "";
    if(this->Prestado == true)
    {
        estado = "Prestado";
    }
    else
    {
        estado = "No Prestado";
    }
    cout<<"Estado del Libro: "<<estado<<std::endl;
    return 0;
}

