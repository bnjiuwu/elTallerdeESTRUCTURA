#pragma once
#include <iostream>
#include <string>

using namespace std;

class MaterialBibliografico
{
    protected:
    string Nombre;
    string Autor;
    string ISBN;
    string Prestado;

    public:
    MaterialBibliografico(string Nombre,string Autor, string ISBN, string Presstado);
    ~MaterialBibliografico();
    string getNombre();
    virtual int Mostrarinfo();
};
