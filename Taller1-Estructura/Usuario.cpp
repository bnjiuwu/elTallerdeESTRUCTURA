#include "Usuario.h"


Usuario::Usuario(string Nombre, string id)
{
    this->Nombre = Nombre;
    this->id = id;
    for (int i = 0; i < 5; i++) {
        this->MaterialesPrestados[i] = nullptr;
    }
}

void Usuario::setLista(MaterialBibliografico* Material)
{
    int aux = 0;
    while(aux<5)
    {
        if(this->MaterialesPrestados[aux] == nullptr)
        {
            this->MaterialesPrestados[aux] = Material;
            break;
        }
        aux++;
    }
}

string Usuario::getNombre()
{
    return this->Nombre;
}

string Usuario::getId()
{
    return this->id;
}

string Usuario::toString()
{
    int aux = 0;
    string mensaje = this->Nombre+","+this->id;
    if(this->MaterialesPrestados[aux] != nullptr)
    {
        mensaje += ","+this->MaterialesPrestados[aux]->getNombre();
    }
    aux++;
    
    return mensaje;
}

void Usuario::prestarMaterial(MaterialBibliografico* material)
{
    cout<<" "<<std::endl;
    int aux = 0;
    while(aux<5)
    {
        if(this->MaterialesPrestados[aux] == nullptr && material->getEstado() == "No Prestado")
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
        if(this->MaterialesPrestados[aux] == nullptr && material->getEstado() == "No Prestado")
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

int Usuario::mostrarMaterialesPrestados()
{
    cout<<" "<<std::endl;
    int aux = 0;
    int contador = 0;
    while(aux<5)
    {
        if(this->MaterialesPrestados[aux] != 0)
        {
            MaterialBibliografico* objeto = this->MaterialesPrestados[aux];
            if (objeto != nullptr)
            {
                objeto->MostrarInfo();
                contador += 1;
            }
            else
            {
                cout << "Error: Material no inicializado correctamente en la posición " << aux << endl;
            }
        }
        aux += 1;
    }  
    if(contador == 0)
    {
        cout<<"No hay libros en la lista"<<std::endl;  
    }
    return contador;
    cout<<" "<<std::endl;
}

Usuario::~Usuario()
{
    cout<<"Se ha eliminado el usuario: "<< this-> Nombre<<std::endl;
}
