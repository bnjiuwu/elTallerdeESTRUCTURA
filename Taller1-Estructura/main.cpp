#include "libro.cpp"
#include <iostream>
#include <string>


void printmenu(){
    int repetirChar = 20;
    char g = '=';
    int num_esp = 7;

    std::cout<< std::string(repetirChar,g)<<std::endl;

    std::string textoMenu = "MENU";
    std::cout<<std::string(num_esp, ' ') << textoMenu <<std::endl;
    std::cout<< std::string(repetirChar,g)<<std::endl;
    std::cout<<"1) Agregar libros"<< std::endl;
    std::cout<<"2) Prestar libros"<< std::endl;
    std::cout<<"3) Lista de invetario"<< std::endl;
};

void Menu()
{
    printmenu();
    int opcionMenu;

    std::cout<<"Ingrese opcion: ";
    std::cin>> opcionMenu;

    switch(opcionMenu)
    {
        case 1:
            std::cout<<"MIRA MI NEGRO USTE E TONTO  1"<< std::endl; 
            break;
        case 2:
            std::cout<<"NIGGA U STUPID 2"<< std::endl;
            break;
        case 3:
            std::cout<<"OPCION 3 MI LOCO"<< std::endl;
            break;

        default:
        std::cout<<"Ingrese opcion valida: "; 
        
        std::cin>> opcionMenu; 
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
