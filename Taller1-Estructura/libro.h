#pragma once
#include <iostream>
#include <string>

using namespace std;

class libro: public MaterialBibliografico
{
    protected:
    string FechaDePublicacion;

    public:
    libro(string Nombre, string Autor, string ISBN, bool Prestado, string FechaDePublicacion);
    ~libro();

};
