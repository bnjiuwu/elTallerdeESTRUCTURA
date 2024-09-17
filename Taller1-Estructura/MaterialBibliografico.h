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
    void setEstado(string Estado);
    string getEstado();
    virtual int Mostrarinfo();
};
