#include "libro.cpp"
#include <iostream>
#include <string>


void printmenu(){
    int repetirChar = 20;
    char g = '=';
    int num_esp = 7;

    std::cout<< std::string(repetirChar,g)<<std::endl;

    string textoMenu = "MENU";
    cout<<std::string(num_esp, ' ') << textoMenu <<std::endl;
    cout<< std::string(repetirChar,g)<<std::endl;
    cout<<"1) Agregar libros"<< std::endl;
    cout<<"2) Prestar libros"<< std::endl;
    cout<<"3) Lista de invetario"<< std::endl;
};

void funcion_opcion_1(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 1
    */
};

void funcion_opcion_2(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 2
    */
};

void funcion_opcion_3(){
    /*
        ESCRIBIR LO QUE HACE LA FUNCION 3
    */
};

void Menu()
{
    printmenu();
    int opcionMenu;

    cout<<"Ingrese opcion: ";
    cin>> opcionMenu;

    switch(opcionMenu)
    {
        case 1:
<<<<<<< Updated upstream
            cout<<"MIRA MI NEGRO USTE E TONTO  1"<< std::endl; 
            break;
        case 2:
            cout<<"NIGGA U STUPID 2"<< std::endl;
            break;
        case 3:
            cout<<"OPCION 3 MI LOCO"<< std::endl;
=======
            funcion_opcion_1();
            std::cout<<"MIRA MI NEGRO USTE E TONTO  1"<< std::endl; 
            break;
        case 2:
            funcion_opcion_2();
            std::cout<<"NIGGA U STUPID 2"<< std::endl;
            break;
        case 3:
            funcion_opcion_3();
            std::cout<<"OPCION 3 MI LOCO"<< std::endl;
>>>>>>> Stashed changes
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
