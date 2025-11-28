#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <iostream>

class InputHelper {
public:
    void leerTexto(const char* mensaje, char* buffer, int maxSize);
    int leerOpcion(const char* mensaje, int min, int max);
};

#endif
