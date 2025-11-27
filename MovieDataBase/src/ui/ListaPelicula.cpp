#include "ListaPelicula.hpp"

const int CAPACIDAD_INICIAL_LISTA = 10;

ListaPelicula::ListaPelicula() 
    : peliculas(nullptr), numPeliculas(0), capacidadPeliculas(0) {
    peliculas = new Movie*[CAPACIDAD_INICIAL_LISTA];
    capacidadPeliculas = CAPACIDAD_INICIAL_LISTA;
}

ListaPelicula::~ListaPelicula() {
    if (peliculas != nullptr) {
        delete[] peliculas;
    }
}

ListaPelicula::ListaPelicula(const ListaPelicula& otro)
    : numPeliculas(otro.numPeliculas), 
      capacidadPeliculas(otro.capacidadPeliculas) {
    peliculas = new Movie*[capacidadPeliculas];
    for (int i = 0; i < numPeliculas; ++i) {
        peliculas[i] = otro.peliculas[i];
    }
}

ListaPelicula& ListaPelicula::operator=(const ListaPelicula& otro) {
    if (this == &otro) return *this;

    if (peliculas != nullptr) delete[] peliculas;

    numPeliculas = otro.numPeliculas;
    capacidadPeliculas = otro.capacidadPeliculas;

    peliculas = new Movie*[capacidadPeliculas];
    for (int i = 0; i < numPeliculas; ++i) {
        peliculas[i] = otro.peliculas[i];
    }

    return *this;
}

void ListaPelicula::redimensionar(int nuevaCapacidad) {
    Movie** nuevoArray = new Movie*[nuevaCapacidad];
    for (int i = 0; i < numPeliculas; ++i) {
        nuevoArray[i] = peliculas[i];
    }
    delete[] peliculas;
    peliculas = nuevoArray;
    capacidadPeliculas = nuevaCapacidad;
}

void ListaPelicula::agregar(Movie* pelicula) {
    if (numPeliculas == capacidadPeliculas) {
        redimensionar(capacidadPeliculas * 2);
    }
    peliculas[numPeliculas] = pelicula;
    numPeliculas++;
}

void ListaPelicula::remover(int indice) {
    if (indice < 0 || indice >= numPeliculas) return;

    for (int i = indice; i < numPeliculas - 1; ++i) {
        peliculas[i] = peliculas[i + 1];
    }
    numPeliculas--;
}

void ListaPelicula::removerPorId(int id) {
    for (int i = 0; i < numPeliculas; ++i) {
        if (peliculas[i]->obtenerId() == id) {
            remover(i);
            break;
        }
    }
}

Movie* ListaPelicula::obtenerEnIndice(int indice) {
    if (indice < 0 || indice >= numPeliculas) return nullptr;
    return peliculas[indice];
}

const Movie* ListaPelicula::obtenerEnIndice(int indice) const {
    if (indice < 0 || indice >= numPeliculas) return nullptr;
    return peliculas[indice];
}

int ListaPelicula::obtenerTamanio() const {
    return numPeliculas;
}

void ListaPelicula::limpiar() {
    numPeliculas = 0;
}

bool ListaPelicula::estaVacia() const {
    return numPeliculas == 0;
}

Movie** ListaPelicula::obtenerArray() {
    return peliculas;
}

const Movie** ListaPelicula::obtenerArray() const {
    return const_cast<const Movie**>(peliculas);
}
