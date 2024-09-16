#include "MaterialBibliografico.cpp"
#include "libro.cpp"

int main(){
    libro* material = new libro("Principito","pepe","Vision",true, "10 de Octubre");
    material->~libro();
};
