#include "Actor.hpp"
#include <iostream>

const int CAPACIDAD_INICIAL_PREMIOS = 5;

Actor::Actor() 
    : Cineasta(), premios(nullptr), numPremios(0), capacidadPremios(0), tipoActor() {}

Actor::Actor(int idActor, const MyString& nom, const MyString& apel, const MyString& tipo)
    : Cineasta(idActor, nom, apel), 
      premios(nullptr), numPremios(0), capacidadPremios(0), tipoActor(tipo) {}

Actor::~Actor() {
    if (premios != nullptr) {
        delete[] premios;
    }
}

Actor::Actor(const Actor& otro)
    : Cineasta(otro), 
      premios(nullptr), numPremios(otro.numPremios), 
      capacidadPremios(otro.capacidadPremios), tipoActor(otro.tipoActor) {

    if (otro.premios != nullptr) {
        premios = new MyString[capacidadPremios];
        for (int i = 0; i < numPremios; ++i) {
            premios[i] = otro.premios[i];
        }
    }
}

Actor& Actor::operator=(const Actor& otro) {
    if (this == &otro) return *this;

    Cineasta::operator=(otro);

    if (premios != nullptr) delete[] premios;

    numPremios = otro.numPremios;
    capacidadPremios = otro.capacidadPremios;
    tipoActor = otro.tipoActor;

    if (otro.premios != nullptr) {
        premios = new MyString[capacidadPremios];
        for (int i = 0; i < numPremios; ++i) {
            premios[i] = otro.premios[i];
        }
    } else {
        premios = nullptr;
    }

    return *this;
}

void Actor::redimensionarPremios(int nuevaCapacidad) {
    MyString* nuevoArray = new MyString[nuevaCapacidad];
    for (int i = 0; i < numPremios; ++i) {
        nuevoArray[i] = premios[i];
    }
    if (premios != nullptr) {
        delete[] premios;
    }
    premios = nuevoArray;
    capacidadPremios = nuevaCapacidad;
}

void Actor::abrirPerfil() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       PERFIL DE ACTOR" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Nombre: " << nombre.obtenerTexto() << " " << apellido.obtenerTexto() << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Tipo: " << tipoActor.obtenerTexto() << std::endl;

    if (numPremios > 0) {
        std::cout << "\nPREMIOS (" << numPremios << "):" << std::endl;
        for (int i = 0; i < numPremios; ++i) {
            std::cout << "  - " << premios[i].obtenerTexto() << std::endl;
        }
    } else {
        std::cout << "\nNo tiene premios registrados." << std::endl;
    }

    std::cout << "========================================" << std::endl;
}

void Actor::mostrarFilmografia() {
    std::cout << "\nFilmografia del actor " << nombre.obtenerTexto() << ":" << std::endl;
    std::cout << "(Lista de peliculas en las que ha actuado)" << std::endl;
}

void Actor::obtenerPersonajes() {
    std::cout << "Personajes interpretados por " << nombre.obtenerTexto() << std::endl;
}

int Actor::calcularAnosCarrera() {
    return edad;
}

void Actor::agregarPremio(const MyString& premio) {
    if (numPremios == capacidadPremios) {
        int nuevaCapacidad = (capacidadPremios == 0) ? CAPACIDAD_INICIAL_PREMIOS : capacidadPremios * 2;
        redimensionarPremios(nuevaCapacidad);
    }
    premios[numPremios] = premio;
    numPremios++;
}

MyString Actor::obtenerTipoActor() const {
    return tipoActor;
}
