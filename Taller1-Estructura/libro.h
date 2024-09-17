#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class libro: public MaterialBibliografico
{
    protected:
    string FechaDePublicacion;
    string resumen;

    public:
    libro(string Nombre, string Autor, string ISBN, bool Prestado, string FechaDePublicacion,string resumen);
    ~libro();

};
