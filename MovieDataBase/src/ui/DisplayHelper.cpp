#include "DisplayHelper.hpp"
#include <cstdlib>
using namespace std;

void DisplayHelper::limpiarPantalla() {
    #ifdef _WIN32
        int resultado = system("cls");
        (void)resultado;
    #else
        int resultado = system("clear");
        (void)resultado;
    #endif
}

void DisplayHelper::mostrarBienvenida() {
   
    
    cout << "   SISTEMA DE GESTION DE PELICULAS     " << endl;
    
}

void DisplayHelper::mostrarMenuPrincipal() {
    cout << "   MENU PRINCIPAL" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 1. Ver catalogo de peliculas" << endl;
    cout << " 2. Mis peliculas favoritas" << endl;
    cout << " 3. Buscar pelicula por titulo" << endl;
    cout << " 4. Filtrar peliculas por genero" << endl;
    cout << " 5. Cerrar sesion" << endl;
    cout << "========================================" << endl;
}

void DisplayHelper::mostrarMensaje(const char* msg) {
    cout << msg << endl;
}

void DisplayHelper::mostrarError(const char* error) {
    cout << "\n[ ERROR ] " << error << endl;
}

void DisplayHelper::pausar() {
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore(1000, '\n');
    cin.get();
}