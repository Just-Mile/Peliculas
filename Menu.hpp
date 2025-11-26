#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include "InputHelper.hpp"
#include "DisplayHelper.hpp"
#include "Database.hpp"

class Menu {
private:
    char usuarioActual[50];
    bool sesionActiva;
    InputHelper input;
    DisplayHelper display;
    Database* db;

    bool hacerLogin();
    void mostrarMenuYEjecutar();
    void ejecutarOpcion(int opcion);
    void mostrarSeccionPeliculas();
    void mostrarFavoritos();
    void buscarPorTitulo();
    void filtrarPorGenero();
    void cerrarSesion();

    bool compararTexto(const char* texto1, const char* texto2);
    void copiarTexto(char* destino, const char* origen);

public:
    Menu(Database* database);
    void iniciar(); 
};

#endif
