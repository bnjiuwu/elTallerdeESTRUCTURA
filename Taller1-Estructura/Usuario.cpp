#include "Usuario.h"

Usuario::Usuario(string Nombre, string id)
{
    this ->Nombre = Nombre;
    this ->id = id;
}

void Usuario::prestarMaterial(MaterialBibliografico* material)
{
    
    MaterialBibliografico* aux = this->MaterialesPrestados[0] ;
    while(aux == nullptr)
    {
        if(aux == nullptr)
        {
            aux = material;
            
        }
        aux += 1;
    }

    cout<<"La lista de Material Bibliografico esta ocupado"<<std::endl;
}

void Usuario::devolverMaterial(MaterialBibliografico* material)
{
   
}

void Usuario::mostrarMaterialesPrestados()
{
}

Usuario::~Usuario()
{
}
