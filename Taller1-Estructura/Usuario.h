#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class Usuario
{
    private:
    string Nombre;
    string id;
    MaterialBibliografico* MaterialesPrestados[5];

    public:
    Usuario(string Nombre, string id);
    void setLista(MaterialBibliografico* Lista);
    string getNombre();
    string getId();
    string toString();
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
    int mostrarMaterialesPrestados();
    ~Usuario();
};
