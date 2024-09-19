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
    string getNombre();
    string getId();
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados();
    ~Usuario();


};
