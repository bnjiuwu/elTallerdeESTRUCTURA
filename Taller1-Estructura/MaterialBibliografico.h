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
    string getAutor();
    string getEstado();
    string getNombre();
    virtual string toString() const = 0;
    virtual void MostrarInfo() const = 0;
};
