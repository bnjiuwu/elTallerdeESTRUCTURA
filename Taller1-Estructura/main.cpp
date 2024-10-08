#include "MaterialBibliografico.h"
#include "libro.h"
#include "Usuario.h"
#include "revista.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <unistd.h> 

std::string toLowerString(const std::string &str) {
    std::string resultado = str;
    for (char &c : resultado) {
        c = tolower(static_cast<unsigned char>(c));  // Convertir cada carácter a minúscula
    }
    return resultado;
}

MaterialBibliografico* EncontrarMaterial(string nombreMaterial, MaterialBibliografico** ListaMateriales, int aux)
{
    cout<<"---------------"<<std::endl;
    cout<<"Introduce el Nombre: "<<std::endl;

    getline(cin,nombreMaterial);
    while(aux<100)
    {
        if(ListaMateriales[aux] != nullptr)
        {
            if(toLowerString(nombreMaterial) == toLowerString(ListaMateriales[aux]->getNombre()))
            {
                return ListaMateriales[aux];
            }
        }
        if(ListaMateriales[aux] == nullptr)
        {
            break;
        }
        aux++;
    }
    return nullptr;
};

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
    cout<<"3) Buscar Material"<< std::endl;
    cout<<"4) Prestar/Devolver libros"<< std::endl;
    cout<<"5) Gestion de Usuarios"<< std::endl;
    cout<<"6) Salir"<<std::endl;
    int opcionMenu;

    cout<<"Ingrese opcion: ";
    cin>> opcionMenu;

    return opcionMenu;
};

int EncontrarUsuario(std::vector<Usuario*> ListaUsuario, string nombre, string id)
{
    int aux = 0;
    while(aux<ListaUsuario.size())
    {
        if(ListaUsuario[aux]->getNombre() == nombre && ListaUsuario[aux]->getId() == id)
        {
            return aux;
        }
        aux++;
    }
    return -1;
}

void eliminarTodoObjeto(MaterialBibliografico** ListaMateriales, vector<Usuario*> ListaUsuario)
{
    int aux = 0;
    while(aux<100)
    {
        if(ListaMateriales[aux] == nullptr)
        {
    
        }
        else
        {
            delete ListaMateriales[aux];
        }
        aux++;
    }

    aux = 0;
    while(aux<ListaUsuario.size())
    {
        delete ListaUsuario[aux];
        aux++;
    }
   
};


MaterialBibliografico** funcion_opcion_1(MaterialBibliografico** ListaMateriales){
    int opcionfuncion;
    int aux = 0;
    string Nombre;
    string Autor;
    string ISBN;
    string Prestado;
    string dato2;
    int dato1Revista;
    string dato1Libro;
    libro* LibroNuevo;
    revista* Revista;
    

    cout<<" "<<std::endl;
    cout<<"==========="<<std::endl;
    cout<<"Deseas Agregar Libro o Revista"<<std::endl;
    cout<<"1) Libro"<<std::endl;
    cout<<"2) Revista"<<std::endl;
    cout<<"3) Salir"<<std::endl;
    cout<<" "<<std::endl;
    cout<<"Ingresa Opcion: "<<std::endl;
    cin>>opcionfuncion;

    cin.ignore();

    switch(opcionfuncion)
    {
        case 1:
            cout<<"Introduce Nombre: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Introduce Autor: "<<std::endl;
            getline(cin,Autor);
            cout<<"Introduce ISBN: "<<std::endl;
            getline(cin,ISBN);
            cout<<"Introduce Fecha De Publicacion: "<<std::endl;
            getline(cin,dato1Libro);
            cout<<"Introduce Resumen: "<<std::endl;
            getline(cin,dato2);
            while(aux<100)
            {
                if(ListaMateriales[aux] == nullptr)
                {
                    LibroNuevo = new libro(Nombre,Autor,ISBN,"No Prestado",dato1Libro,dato2);
                    ListaMateriales[aux] = LibroNuevo;
                    cout<<""<<std::endl;
                    cout<<"==========="<<std::endl;
                    cout<<""<<std::endl;
                    cout<<"Se ha guardado el Libro"<<std::endl;
                    cout<<""<<std::endl;
                    sleep(3);
                    funcion_opcion_1(ListaMateriales);
                    break;
                }
                aux++;
            }
            cout<<"No quedan espacios en Lista de Materiales"<<std::endl;
            break;
        
        case 2:
            cout<<"Introduce Nombre: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Introduce Autor: "<<std::endl;
            getline(cin,Autor);
            cout<<"Introduce ISBN: "<<std::endl;
            getline(cin,ISBN);
            cout<<"Introduce Numero de Edicion: "<<std::endl;
            cin>>dato1Revista;
            cin.ignore();
            cout<<"Introduce Mes de Publicacion: "<<std::endl;
            getline(cin,dato2);
            while(aux<100)
            {
                if(ListaMateriales[aux] == nullptr)
                {
                    Revista = new revista(Nombre,Autor,ISBN,"No Prestado",dato1Revista,dato2);
                    ListaMateriales[aux] = Revista;
                    cout<<""<<std::endl;
                    cout<<"==========="<<std::endl;
                    cout<<""<<std::endl;
                    cout<<"Se ha guardado la Revista"<<std::endl;
                    cout<<""<<std::endl;
                    sleep(3);
                    funcion_opcion_1(ListaMateriales);
                    break;
                }
                aux++;
            }
            cout<<"No quedan espacios en Lista de Materiales"<<std::endl;
            break;

        case 3:
            return ListaMateriales;
            break;

        default:
            cout<<"Ingrese opcion valida: "; 
            cin>> opcionfuncion; 
            break;
    }
    return nullptr;
}


void funcion_opcion_2(MaterialBibliografico** ListaMateriales){
    int contador = 0;
    int aux = 0;
    while(aux<100)
    {
        if(ListaMateriales[aux] != nullptr)
        {
            ListaMateriales[aux]->MostrarInfo();
            cout<<""<<std::endl;
            contador += 1;
        }
        aux++;
    }
    sleep(3);
    if(contador == 0)
    {
        cout<<""<<std::endl;
        cout<<"La Biblioteca se encuentra vacia de Materiales"<<std::endl;
        cout<<""<<std::endl;
        sleep(3);
        return;
    }
    return;
    
};

void funcion_opcion_3(MaterialBibliografico** ListaMaterial){

    int contador = 0;
    MaterialBibliografico* Material;
    string MetodoDeBusqueda;
    int aux = 0;
    int opcionfuncion;
    string AutorMaterial;
    cout<<" "<<std::endl;
    cout<<"==========="<<std::endl;
    cout<<"Deseas por Nombre o Autor"<<std::endl;
    cout<<"1) Nombre"<<std::endl;
    cout<<"2) Autor"<<std::endl;
    cout<<"3) Salir"<<std::endl;
    cout<<" "<<std::endl;
    cout<<"Ingresa Opcion: "<<std::endl;
    cin>>opcionfuncion;
    cin.ignore();
    switch(opcionfuncion)
    {
        case 1:
            cout<<"---------------"<<std::endl;
            cout<<"Introduce el Nombre: "<<std::endl;
            getline(cin,AutorMaterial);
            while(aux<100)
            {
                if(ListaMaterial[aux] != nullptr)
                {
                    if(toLowerString(AutorMaterial) == toLowerString(ListaMaterial[aux]->getNombre()))
                    {
                        cout<<" "<<std::endl;
                        cout<<"==========="<<std::endl;
                        cout<<" "<<std::endl;
                        ListaMaterial[aux]->MostrarInfo();
                        contador += 1;
                        
                    }
                }
                if(ListaMaterial[aux] == nullptr && contador == 0)
                {
                    cout<<" "<<std::endl;
                    cout<<"================="<<std::endl;
                    cout<<" "<<std::endl;
                    cout<<"El material no se encuentra en la Biblioteca"<<std::endl;
                    sleep(3);
                    break;
                    funcion_opcion_3(ListaMaterial);
                    
                }
                aux++;
            }
            sleep(3);
            funcion_opcion_3(ListaMaterial);
            break;
        
        case 2:
            cout<<"---------------"<<std::endl;
            cout<<"Introduce el Autor: "<<std::endl;
            getline(cin,AutorMaterial);
            while(aux<100)
            {
                if(ListaMaterial[aux] != nullptr)
                {
                    if(toLowerString(AutorMaterial) == toLowerString(ListaMaterial[aux]->getAutor()))
                    {
                        cout<<" "<<std::endl;
                        cout<<"==========="<<std::endl;
                        cout<<" "<<std::endl;
                        ListaMaterial[aux]->MostrarInfo();
                        contador += 1;
                        
                    }
                }
                if(ListaMaterial[aux] == nullptr && contador == 0)
                {
                    cout<<" "<<std::endl;
                    cout<<"================="<<std::endl;
                    cout<<" "<<std::endl;
                    cout<<"El material no se encuentra en la Biblioteca"<<std::endl;
                    sleep(3);
                    break;
                    funcion_opcion_3(ListaMaterial);
                    
                }
                aux++;
            }
            sleep(3);
            funcion_opcion_3(ListaMaterial);
            break;

        case 3:
            return;
            break;

        default:
            cout<<"Ingrese opcion valida: "; 
            cin>> opcionfuncion; 
            break;
    }
};

void funcion_opcion_4(MaterialBibliografico** ListaMateriales, vector<Usuario*> ListaUsuario){
    int Usuario;
    string Nombre;
    string ID;
    MaterialBibliografico* Material;
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
    cin.ignore();
    string nombreMaterial;

    switch(opcionfuncion)
    {
        case 1:
            cout<<" "<<std::endl;
            cout<<"========="<<std::endl;
            cout<<"Ingrese Nombre de Usuario: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Ingrese ID del Usuario: "<<std::endl;
            getline(cin,ID);

            Usuario = EncontrarUsuario(ListaUsuario,Nombre,ID);
            if(Usuario != -1)
            {
                Material = EncontrarMaterial(nombreMaterial,ListaMateriales,aux);
                if(Material == nullptr)
                {
                    cout<<""<<std::endl;
                    cout<<"============="<<std::endl;
                    cout<<"El material no se encuentra en la Biblioteca"<<std::endl;
                    sleep(3);
                    funcion_opcion_4(ListaMateriales,ListaUsuario);
                }
                ListaUsuario[Usuario]->prestarMaterial(Material);
                sleep(3);
                funcion_opcion_4(ListaMateriales,ListaUsuario);
            }
            else
            {
                cout<<" "<<std::endl;
                cout<<"================"<<std::endl;
                cout<<""<<std::endl;
                cout<<"El Usuario no existe"<<std::endl;
                sleep(3);
                funcion_opcion_4(ListaMateriales,ListaUsuario);
            }
            break;
        

        case 2:
            cout<<" "<<std::endl;
            cout<<"========="<<std::endl;
            cout<<"Ingrese Nombre de Usuario: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Ingrese ID del Usuario: "<<std::endl;
            getline(cin,ID);

            Usuario = EncontrarUsuario(ListaUsuario,Nombre,ID);
            if(Usuario != -1)
            {
                Material = EncontrarMaterial(nombreMaterial,ListaMateriales,aux);
                if(Material == nullptr)
                {
                    cout<<""<<std::endl;
                    cout<<"============="<<std::endl;
                    cout<<"El material no se encuentra en la Biblioteca"<<std::endl;
                    sleep(3);
                    funcion_opcion_4(ListaMateriales,ListaUsuario);
                }
                ListaUsuario[Usuario]->devolverMaterial(Material);
                sleep(3);
                funcion_opcion_4(ListaMateriales,ListaUsuario);
            }
            else
            {
                cout<<" "<<std::endl;
                cout<<"================"<<std::endl;
                cout<<""<<std::endl;
                cout<<"El Usuario no existe"<<std::endl;
                sleep(3);
                funcion_opcion_4(ListaMateriales,ListaUsuario);
            }
            break;
        
        case 3:
            return;
            break;

        default:
            cout<<"Ingrese opcion valida: "; 
            cin>> opcionfuncion; 
            break;


    }
};


vector<Usuario*> funcion_opcion_5(vector<Usuario*> ListaUsuario){
    int indiceUsuario;
    string Nombre;
    string ID;
    int opcionfuncion;
    cout<<" "<<std::endl;
    cout<<"==================="<<std::endl;
    cout<<"Que desea hacer?"<<std::endl;
    cout<<"1) Crear Usuario"<<std::endl;
    cout<<"2) Eliminar Usuario"<<std::endl;
    cout<<"3) Buscar Usuario"<<std::endl;
    cout<<"4) Salir"<<std::endl;
    cout<<"Ingrese opcion: "<<std::endl;
    cin>> opcionfuncion;
    cin.ignore();

    switch(opcionfuncion)
    {
        case 1:
            cout<<" "<<std::endl;
            cout<<"============="<<std::endl;
            cout<<"Introduce Nombre: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Introduce ID: "<<std::endl;
            getline(cin,ID);

            indiceUsuario = EncontrarUsuario(ListaUsuario,Nombre,ID);
            if(indiceUsuario == -1)
            {
                Usuario* NuevoUsuario = new Usuario(Nombre,ID);
                ListaUsuario.push_back(NuevoUsuario);
                cout<<" "<<std::endl;
                cout<<"================"<<std::endl;
                cout<<""<<std::endl;
                cout<<"Usuario creado con exito"<<std::endl;
                sleep(3);
                funcion_opcion_5(ListaUsuario);
            }
            else
            {
                cout<<" "<<std::endl;
                cout<<"================"<<std::endl;
                cout<<""<<std::endl;
                cout<<"El Usuario ya existe"<<std::endl;
                sleep(3);
                funcion_opcion_5(ListaUsuario);
            }
            break;

        case 2:
            cout<<" "<<std::endl;
            cout<<"============="<<std::endl;
            cout<<"Introduce Nombre: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Introduce ID: "<<std::endl;
            getline(cin,ID);

            indiceUsuario = EncontrarUsuario(ListaUsuario,Nombre,ID);
            if(indiceUsuario == -1)
            {
                cout<<" "<<std::endl;
                cout<<"================"<<std::endl;
                cout<<""<<std::endl;
                cout<<"El Usuario no existe"<<std::endl;
                sleep(3);
                funcion_opcion_5(ListaUsuario);
            }
            else
            {
                Usuario* usuario = ListaUsuario[indiceUsuario];
                if(usuario->mostrarMaterialesPrestados() == 0)
                {
                    ListaUsuario.erase(ListaUsuario.begin() + indiceUsuario);
                    delete usuario;
                    cout<<" "<<std::endl;
                    cout<<"================"<<std::endl;
                    cout<<""<<std::endl;
                    cout<<"Usuario eliminado"<<std::endl;
                    sleep(3);
                    funcion_opcion_5(ListaUsuario);
                }
                else
                {
                    cout<<" "<<std::endl;
                    cout<<"================"<<std::endl;
                    cout<<""<<std::endl;
                    cout<<"El Usuario debe devolver Materiales antes de ser eliminado"<<std::endl;
                    sleep(3);
                    funcion_opcion_5(ListaUsuario);
                }


            }
            break;

        case 3:
            cout<<" "<<std::endl;
            cout<<"============="<<std::endl;
            cout<<"Introduce Nombre: "<<std::endl;
            getline(cin,Nombre);
            cout<<"Introduce ID: "<<std::endl;
            getline(cin,ID);

            indiceUsuario = EncontrarUsuario(ListaUsuario,Nombre,ID);
            if(indiceUsuario == -1)
            {
                cout<<" "<<std::endl;
                cout<<"================"<<std::endl;
                cout<<""<<std::endl;
                cout<<"El Usuario no existe"<<std::endl;
                sleep(3);
                funcion_opcion_5(ListaUsuario);
            }
            else
            {
                Usuario* usuario = ListaUsuario[indiceUsuario];
                cout<<""<<std::endl;
                cout<<"=============="<<std::endl;
                cout<<"Nombre: "<<usuario->getNombre()<<std::endl;
                cout<<"ID: "<<usuario->getId()<<std::endl;
                cout<<""<<std::endl;
                cout<<"Lista Materiales: "<<std::endl;
                usuario->mostrarMaterialesPrestados();
                sleep(3);
                funcion_opcion_5(ListaUsuario);
            
            }
            break;
        
        case 4:
            return ListaUsuario;
            break;

        default:
            cout<<"Ingrese opcion valida: "; 
            cin>> opcionfuncion; 
            break;
    }
    return ListaUsuario;
};


void GuardarMateriales(MaterialBibliografico** ListaMaterial) {
    ofstream archivo("biblioteca.txt");

    for (int i = 0; i < 100; ++i) {
        if (ListaMaterial[i] != nullptr) {
            archivo << ListaMaterial[i]->toString() << endl; // Escribe cada material en el archivo
        }
    }
    archivo.close();
}

void GuardarUsuarios(vector<Usuario*> ListaUsuario)
{
    ofstream archivo("usuarios.txt");

    for (int i = 0; i < ListaUsuario.size(); ++i) {
        if (ListaUsuario[i] != nullptr) {
            archivo << ListaUsuario[i]->toString() << endl; // Escribe cada material en el archivo
        }
    }
    archivo.close();
}


void Menu(MaterialBibliografico** Lista, vector<Usuario*> ListaUsuario)
{
    bool EstadoMenu = true;
    while(EstadoMenu)
    {
        int opcionMenu = printmenu();
        switch(opcionMenu)
        {
            case 1:
                funcion_opcion_1(Lista);
                break;
            case 2:
                cout<<"====================" <<std::endl;
                cout<<"Lista de Materiales Bibliograficos:"<<std::endl;
                cout<<""<<std::endl;
                funcion_opcion_2(Lista);
                break;
            case 3:
                funcion_opcion_3(Lista);
                break;
            case 4:
                funcion_opcion_4(Lista,ListaUsuario);
                break;
            case 5:
                ListaUsuario = funcion_opcion_5(ListaUsuario);
                break;

            case 6:
                EstadoMenu = false;
                GuardarUsuarios(ListaUsuario);
                GuardarMateriales(Lista);
                eliminarTodoObjeto(Lista,ListaUsuario);
                break;

            default:
                cout<<"Ingrese opcion valida: "; 
                cin>> opcionMenu; 
                break;    
        }
    }
};


vector<std::string> splitPorComillas(string linea)
{
    std::vector<std::string> elementos;
    std::istringstream ss(linea);
    std::string elemento;

    while (getline(ss, elemento, ','))  // Leer hasta encontrar una coma
    {
        elementos.push_back(elemento);  // Añadir cada elemento separado al vector
    }

    return elementos;
}



MaterialBibliografico** LecturaArch(MaterialBibliografico** ListaMaterial)
{
    int aux = 0;
    std::ifstream archivo("biblioteca.txt");
    if(!archivo.is_open())
    {
        cerr << "Error al abrir el archivo" << std::endl;
    }

    string linea;

    while (true) {
        getline(archivo, linea);
        if (linea.empty()) {
            break; // Sale del bucle si la línea está vacía
        }
        vector<string> elementos = splitPorComillas(linea);


        if (elementos[0] == "Revista") {
            aux = 0;
            string Nombre = elementos[1];
            string Autor = elementos[2];
            string ISBN = elementos[3];
            string Prestado = elementos[4];
            int NumeroEdicion = stoi(elementos[5]);
            string mesPublicacion = elementos[6];

            while (aux < 100) 
            {
                if (ListaMaterial[aux] == nullptr) 
                {
                    ListaMaterial[aux] = new revista(Nombre, Autor, ISBN, Prestado, NumeroEdicion, mesPublicacion);
                    break;
                }
                aux++;
            }
        } 
        else if (elementos[0] == "Libro") 
        {
            aux = 0;
            string Nombre = elementos[1];
            string Autor = elementos[2];
            string ISBN = elementos[3];
            string Prestado = elementos[4];
            string FechaDePublicacion = elementos[5];
            string Resumen = elementos[6];

            while (aux < 100) 
            {
                if (ListaMaterial[aux] == nullptr) 
                {
                    ListaMaterial[aux] = new libro(Nombre, Autor, ISBN, Prestado, FechaDePublicacion, Resumen);
                    break;
                }
                aux++;
            }
        }
    }
    return ListaMaterial;
}

vector<Usuario*> LecturaUsuario(vector<Usuario*> ListaUsuario, MaterialBibliografico** ListaMaterial) {
    std::ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << std::endl;
        return ListaUsuario;
    }

    string linea;

    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue; 
        }

        vector<string> elementos = splitPorComillas(linea);
        string Nombre = elementos[0]; 
        string ID = elementos[1];
        
       
        Usuario* NuevoUsuario = new Usuario(Nombre, ID);

      
        if (elementos.size() > 2) {
            for (size_t a = 2; a < elementos.size(); a++) {
                for (int aux = 0; aux < 100; aux++) {
                    if (ListaMaterial[aux] != nullptr && ListaMaterial[aux]->getNombre() == elementos[a]) {
                        NuevoUsuario->setLista(ListaMaterial[aux]);
                        break; // Salir del bucle una vez encontrado el material
                    }
                }
            }
        }

        ListaUsuario.push_back(NuevoUsuario);
    }

    return ListaUsuario; // Retornar la lista de usuarios actualizada
}



int main(){
    MaterialBibliografico* ListaMateriales[100] = {nullptr};
    vector<Usuario *> ListaUsuario;
    MaterialBibliografico** NuevosMateriales = LecturaArch(ListaMateriales);
    vector<Usuario*> NuevosUsuarios = LecturaUsuario(ListaUsuario,NuevosMateriales);
    Menu(NuevosMateriales, NuevosUsuarios);
    return 0;
}

