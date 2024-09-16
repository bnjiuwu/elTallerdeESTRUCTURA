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
    bool Prestado;

    public:
    MaterialBibliografico(string Nombre,string Autor, string ISBN, bool Presstado);
    ~MaterialBibliografico();
    string getNombre();
    virtual int Mostrarinfo();
};
