#include "Usuario.h"

Usuario::Usuario(string Nombre, string id)
{
    this ->Nombre = Nombre;
    this ->id = id;
}

string Usuario::getNombre()
{
    return this->Nombre;
}

string Usuario::getId()
{
    return this->id;
}

void Usuario::prestarMaterial(MaterialBibliografico* material)
{
    cout<<" "<<std::endl;
    int aux = 0;
    while(aux<5)
    {
        if(this->MaterialesPrestados[aux] == 0 && material->getEstado() == "No Prestado")
        {
            cout<<"============="<<std::endl;
            cout<<"Se ha guardado el Material"<<std::endl;
            this->MaterialesPrestados[aux] = material;
            material->setEstado("Prestado");
            cout<<" "<<std::endl;
            return;
        }
        else if(material->getEstado() == "Prestado")
        {
            cout<<"============="<<std::endl;
            cout<<"El material ya fue prestado"<<std::endl;
            return;
        }
        aux++;
    }
    cout<<"============="<<std::endl;
    cout<<"La lista esta completa, no se puede prestar mas Materiales"<<std::endl;
    cout<<" "<<std::endl;
}

void Usuario::devolverMaterial(MaterialBibliografico* material)
{
    cout<<" "<<std::endl;
    int aux = 0;
    while(aux<5)
    {
        if(this->MaterialesPrestados[aux] == 0 && material->getEstado() == "No Prestado")
        {
            cout<<"============="<<std::endl;
            cout<<"El material no ha sido Prestado"<<std::endl;
            cout<<" "<<std::endl;
            return;
        }
        else if(material->getEstado() == "Prestado")
        {
            cout<<"============="<<std::endl;
            cout<<"Se ha devuelto el Material"<<std::endl;
            this->MaterialesPrestados[aux] = 0;
            material->setEstado("No Prestado");
            cout<<" "<<std::endl;
            return;
        }
        aux++;
    }
    cout<<"============="<<std::endl;
    cout<<"La lista esta completa, no se puede prestar mas Materiales"<<std::endl;
    cout<<" "<<std::endl;
   
}

void Usuario::mostrarMaterialesPrestados()
{
    cout<<" "<<std::endl;
    int aux = 0;
    int contador = 0;
    while(aux<5)
    {
        if(this->MaterialesPrestados[aux] != nullptr)
        {
            MaterialBibliografico* objeto = this->MaterialesPrestados[aux];
            objeto->MostrarInfo();
            contador += 1;
        }
        aux += 1;
    }  
    if(contador == 0)
    {
        cout<<"No hay libros en la lista"<<std::endl;  
    }
    cout<<" "<<std::endl;
}

Usuario::~Usuario()
{
    cout<<"Se ha eliminado el usuario: "<< this-> Nombre<<std::endl;
}
