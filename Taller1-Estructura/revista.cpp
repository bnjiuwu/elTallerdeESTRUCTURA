#pragma once
#include "MaterialBibliografico.cpp"
#include <iostream>

revista:: revista(string Nombre,string Autor, string ISBN, bool Presstado,int numeroEdicion, string mesPublicacion):MaterialBibliografico(Nombre, Autor, ISBN, Prestado)
{
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
};

revista::~revista(){
    cout<<"Se ha eliminado la revista: "<< this-> Nombre<<std::endl;
};