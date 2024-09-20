#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"
using namespace std;

class revista: public MaterialBibliografico
{
    protected:
        int numeroEdicion;
        string mesPublicacion;

    public:
        revista(string Nombre,string Autor, string ISBN, string Prestado,int numeroEdicion,string mesPublicacion);
        ~revista();
        void MostrarInfo() const override;
        string toString() const override;

};
