#include "MyString.hpp"

void MyString::liberarMemoria() {
    if (datos != nullptr) {
        delete[] datos; 
        datos = nullptr;
    }
    longitud = 0;
    capacidad = 0;
}

void MyString::copiarTexto(const char* texto) {
    if (texto == nullptr) {
        longitud = 0;
        if (datos != nullptr && capacidad > 0) datos[0] = '\0'; 
        return;
    }
    int len = 0;
    while (texto[len] != '\0') {
        len++;
    }
    for (int i = 0; i <= len; ++i) { 
        datos[i] = texto[i];
    }
    longitud = len;
}

void MyString::redimensionar(int nuevaCapacidad) {
    if (nuevaCapacidad <= capacidad) return;
    char* nuevoDatos = new char[nuevaCapacidad]; 
    if (datos != nullptr) {
        for (int i = 0; i <= longitud; ++i) { 
            nuevoDatos[i] = datos[i];
        }
    } else {
        nuevoDatos[0] = '\0';
    }

    liberarMemoria(); 
    datos = nuevoDatos;
    capacidad = nuevaCapacidad;
}

MyString::MyString() : datos(nullptr), longitud(0), capacidad(0) {}

MyString::MyString(const char* texto) : datos(nullptr), longitud(0), capacidad(0) {
    asignar(texto); 
}

MyString::~MyString() {
    liberarMemoria();
}

MyString::MyString(const MyString& otro) : datos(nullptr), longitud(0), capacidad(0) {
    if (otro.datos != nullptr) {
        int nuevaCapacidad = otro.longitud + 1;
        datos = new char[nuevaCapacidad]; 
        capacidad = nuevaCapacidad;
        longitud = otro.longitud;
        for (int i = 0; i <= otro.longitud; ++i) { 
            datos[i] = otro.datos[i];
        }
    }
}

MyString& MyString::operator=(const MyString& otro) {
    if (this == &otro) {
        return *this;
    }

    if (otro.datos == nullptr) {
        liberarMemoria();
        return *this;
    }

    int capacidadRequerida = otro.longitud + 1;

    if (capacidad < capacidadRequerida) {
        liberarMemoria();
        datos = new char[capacidadRequerida];
        capacidad = capacidadRequerida;
    }

    longitud = otro.longitud;
    for (int i = 0; i <= otro.longitud; ++i) {
        datos[i] = otro.datos[i];
    }

    return *this;
}

void MyString::asignar(const char* texto) {
    if (texto == nullptr) {
        liberarMemoria();
        return;
    }

    int nuevaLongitud = 0;
    while (texto[nuevaLongitud] != '\0') {
        nuevaLongitud++;
    }

    int capacidadRequerida = nuevaLongitud + 1; 

    if (capacidad < capacidadRequerida) {
        redimensionar(capacidadRequerida); 
    }

    copiarTexto(texto); 
}

void MyString::concatenar(const char* texto) {
    if (texto == nullptr || texto[0] == '\0') {
        return; 
    }

    int len_a_aniadir = 0;
    while (texto[len_a_aniadir] != '\0') {
        len_a_aniadir++;
    }

    int nuevaLongitud = longitud + len_a_aniadir;
    int capacidadRequerida = nuevaLongitud + 1;

    if (capacidad < capacidadRequerida) {
        int nuevaCapacidad = capacidad * 2;
        if (nuevaCapacidad < capacidadRequerida) {
            nuevaCapacidad = capacidadRequerida;
        }
        redimensionar(nuevaCapacidad);
    }

    int indice_inicio = longitud;
    for (int i = 0; i <= len_a_aniadir; ++i) {
        datos[indice_inicio + i] = texto[i]; 
    }

    longitud = nuevaLongitud;
}

int MyString::obtenerLongitud() const {
    return longitud;
}


const char* MyString::obtenerTexto() const {
    return (datos != nullptr) ? datos : "";
}