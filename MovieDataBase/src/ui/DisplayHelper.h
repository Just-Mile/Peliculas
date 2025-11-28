#ifndef DISPLAYHELPER_H
#define DISPLAYHELPER_H

#include <iostream>

class DisplayHelper {
public:
    void limpiarPantalla();
    void mostrarBienvenida();
    void mostrarMenuPrincipal();
    void mostrarMensaje(const char* msg);
    void mostrarError(const char* error);
    void pausar();
};

#endif
