#include "Director.hpp"
#include <iostream>

const int CAPACIDAD_INICIAL_PREMIOS_DIR = 5;

Director::Director() : Cineasta(), premios(nullptr), numPremios(0), 
                       capacidadPremios(0), anosExperiencia(0) {}

Director::Director(int idDirector, const MyString& nom, const MyString& apel, const MyString& estilo)
    : Cineasta(idDirector, nom, apel), estiloDirector(estilo), 
      premios(nullptr), numPremios(0), capacidadPremios(0), anosExperiencia(0) {}

Director::~Director() {
    if (premios != nullptr) {
        delete[] premios;
    }
}

Director::Director(const Director& otro)
    : Cineasta(otro), estiloDirector(otro.estiloDirector), 
      numPremios(otro.numPremios), capacidadPremios(otro.capacidadPremios),
      anosExperiencia(otro.anosExperiencia) {

    if (otro.premios != nullptr) {
        premios = new MyString[capacidadPremios];
        for (int i = 0; i < numPremios; ++i) {
            premios[i] = otro.premios[i];
        }
    } else {
        premios = nullptr;
    }
}

Director& Director::operator=(const Director& otro) {
    if (this == &otro) return *this;

    Cineasta::operator=(otro);

    if (premios != nullptr) delete[] premios;

    estiloDirector = otro.estiloDirector;
    numPremios = otro.numPremios;
    capacidadPremios = otro.capacidadPremios;
    anosExperiencia = otro.anosExperiencia;

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

void Director::redimensionarPremios(int nuevaCapacidad) {
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

void Director::abrirPerfil() {
    std::cout << "=== Perfil de Director ===" << std::endl;
    std::cout << "Nombre: " << nombre.obtenerTexto() << " " << apellido.obtenerTexto() << std::endl;
    std::cout << "Estilo: " << estiloDirector.obtenerTexto() << std::endl;
    std::cout << "Premios: " << numPremios << std::endl;
    std::cout << "Anos de experiencia: " << anosExperiencia << std::endl;
}

void Director::mostrarFilmografia() {
    std::cout << "Filmografia del director " << nombre.obtenerTexto() << ":" << std::endl;
    std::cout << "(Lista de peliculas dirigidas)" << std::endl;
}

void Director::obtenerPeliculasDirigidas() {
    std::cout << "Peliculas dirigidas por " << nombre.obtenerTexto() << std::endl;
}

int Director::calcularProductividad() {
    return anosExperiencia;
}

void Director::agregarPremio(const MyString& premio) {
    if (numPremios == capacidadPremios) {
        int nuevaCapacidad = (capacidadPremios == 0) ? CAPACIDAD_INICIAL_PREMIOS_DIR : capacidadPremios * 2;
        redimensionarPremios(nuevaCapacidad);
    }
    premios[numPremios] = premio;
    numPremios++;
}

MyString Director::obtenerEstiloDirector() const {
    return estiloDirector;
}