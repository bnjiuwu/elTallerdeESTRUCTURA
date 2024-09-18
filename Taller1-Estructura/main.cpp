#include "MaterialBibliografico.cpp"
#include "Usuario.cpp"
#include <iostream>
#include <string>
#include <fstream>


int printmenu(){
    int repetirChar = 20;
    char g = '=';
    int num_esp = 7;

    std::cout<< std::string(repetirChar,g)<<std::endl;

    string textoMenu = "MENU";
    cout<<std::string(num_esp, ' ') << textoMenu <<std::endl;
    cout<< std::string(repetirChar,g)<<std::endl;
    cout<<"1) Agregar Material a la Biblioteca"<< std::endl;
    cout<<"2) Mostrar Informacion de los Materiales"<< std::endl;
    cout<<"3) Lista de invetario"<< std::endl;
    cout<<"4) Prestar libros"<< std::endl;
    cout<<"5) Gestion de Usuarios"<< std::endl;
    cout<<"Salir"<<std::endl;
    int opcionMenu;

    cout<<"Ingrese opcion: ";
    cin>> opcionMenu;

    return opcionMenu;
};

void funcion_opcion_1(){
    int opcionfuncion;
    int aux = 0;
    string Nombre;
    string Autor;
    string ISBN;
    

    cout<<" "<<std::endl;
    cout<<"==========="<<std::endl;
    cout<<"Deseas Agregar Libro o Revista"<<std::endl;
    cout<<"1) Libro"<<std::endl;
    cout<<"2) Revista"<<std::endl;
    cout<<" "<<std::endl;
    cout<<"Ingresa Opcion: "<<std::endl;
    cin>>opcionfuncion;
};

void funcion_opcion_2(Usuario* usuario, MaterialBibliografico* material){
   usuario->mostrarMaterialesPrestados();
};

void funcion_opcion_3(){
    int aux = 0;
    int opcionfuncion;
    cout<<" "<<std::endl;
    cout<<"==========="<<std::endl;
    cout<<"Deseas por Nombre o Autor"<<std::endl;
    cout<<"1) Nombre"<<std::endl;
    cout<<"2) Autor"<<std::endl;
    cout<<" "<<std::endl;
    cout<<"Ingresa Opcion: "<<std::endl;
    cin>>opcionfuncion;
};
void funcion_opcion_4(MaterialBibliografico** ListaMateriales){
    int aux = 0;
    int opcionfuncion;
    cout<<" "<<std::endl;
    cout<<"==================="<<std::endl;
    cout<<"Que desea hacer?"<<std::endl;
    cout<<"1) Pedir Prestado Material"<<std::endl;
    cout<<"2) Devolver Material"<<std::endl;
    cout<<"3) Salir"<<std::endl;
    cout<<" "<<std::endl;
    cout<<"Ingrese opcion: ";
    cin>> opcionfuncion;
    string nombreMaterial;

    switch(opcionfuncion)
    {
        case 1:
            cout<<"---------------"<<std::endl;
            cout<<"Introduce el Nombre: "<<std::endl;
            cin>>nombreMaterial;
            while(aux<100)
            {
                if(ListaMateriales[aux] != nullptr)
                {
                    if(nombreMaterial == ListaMateriales[aux]->getNombre())
                    {
                        if(ListaMateriales[aux]->getEstado() == "No Prestado")
                        {
                            cout<<" "<<std::endl;
                            cout<<"================="<<std::endl;
                            cout<<" "<<std::endl;
                            cout<<"Se ha realizado el prestamo del material"<<std::endl;
                            ListaMateriales[aux]->setEstado("Prestado");
                            funcion_opcion_4(ListaMateriales);
                            break;
                        }
                        else
                        {
                            cout<<" "<<std::endl;
                            cout<<"================="<<std::endl;
                            cout<<" "<<std::endl;
                            cout<<"El material ya se encuentra prestado"<<std::endl;
                            funcion_opcion_4(ListaMateriales);
                            break;
                        }
                    }
                }
                if(ListaMateriales[aux] == nullptr)
                {
                    cout<<" "<<std::endl;
                    cout<<"================="<<std::endl;
                    cout<<"El material no se encuentra en la Biblioteca"<<std::endl;
                    funcion_opcion_4(ListaMateriales);
                    break;
                }
                aux++;
            }
            cout<<" "<<std::endl;
            cout<<"================="<<std::endl;
            cout<<"El material no se encuentra en la Biblioteca"<<std::endl;
            funcion_opcion_4(ListaMateriales);
            break;
    }
};
void funcion_opcion_5(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 4
    */
};

void Menu(MaterialBibliografico** Lista)
{
    bool niger = true;
    while(niger)
    {
        int opcionMenu = printmenu();
        switch(opcionMenu)
        {
            case 1:
                funcion_opcion_1();
                std::cout<<"MIRA MI NEGRO USTE E TONTO  1"<< std::endl; 
                break;
            case 2:
                out<<"====================" <<std::endl;
                cout<<"Lista de Materiales Bibliograficos:"<<std::endl;
                funcion_opcion_2(usuario);
                break;
            case 3:
                funcion_opcion_3();
                std::cout<<"OPCION 3 MI LOCO"<< std::endl;
                break;
            case 4:
                funcion_opcion_4(Lista);
                std::cout<<"OPCION 4 MI LOCO"<< std::endl;
                break;
            case 5:
                funcion_opcion_5();
                std::cout<<"OPCION 5 MI LOCO"<< std::endl;
                break;

            case 6:
                niger = false;
                break;

            default:
                cout<<"Ingrese opcion valida: "; 
                cin>> opcionMenu; 
                break;    
        }
    }
};


int main(){
    MaterialBibliografico* principito2 = new MaterialBibliografico("Lolero","pepe","popo","No Prestado");
    MaterialBibliografico* principito = new MaterialBibliografico("Principito","pepe","popo","No Prestado");
    MaterialBibliografico* ListaMateriales[100] = {principito,principito2};
    Menu(ListaMateriales);
    return 0;
}
