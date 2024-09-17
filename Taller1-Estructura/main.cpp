#include "MaterialBibliografico.cpp"
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
    int opcionMenu;

    cout<<"Ingrese opcion: ";
    cin>> opcionMenu;

    return opcionMenu;
};

void funcion_opcion_1(){
    /*

        ESCRIBIR LO QUE HACE LA FUNCION 1
    */
};

void funcion_opcion_2(Usuario* usuario, MaterialBibliografico* material){
   usuario->mostrarMaterialesPrestados();
};

void funcion_opcion_3(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 3
    */
};
void funcion_opcion_4(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 4
    */
};
void funcion_opcion_5(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 4
    */
};

void Menu()
{
    
    int opcionMenu = printmenu();

    switch(opcionMenu)
    {
        case 1:
            funcion_opcion_1();
            std::cout<<"MIRA MI NEGRO USTE E TONTO  1"<< std::endl; 
            break;
        case 2:
            cout<<"====================" <<std::endl;
            cout<<"Lista de Materiales Bibliograficos:"<<std::endl;
            funcion_opcion_2(usuario,material);
            break;
        case 3:
            funcion_opcion_3();
            std::cout<<"OPCION 3 MI LOCO"<< std::endl;
            break;
        case 4:
            funcion_opcion_4();
            std::cout<<"OPCION 4 MI LOCO"<< std::endl;
            break;
        case 5:
            funcion_opcion_5();
            std::cout<<"OPCION 5 MI LOCO"<< std::endl;
            break;

        default:
            cout<<"Ingrese opcion valida: "; 
            cin>> opcionMenu; 
            break;    
    }
};


int main(){
 
    Menu();
    //libro* material = new libro("Principito","pepe","Vision",true, "10 de Octubre");
    //material->Mostrarinfo();
    //material ->~libro();
    return 0;
}
