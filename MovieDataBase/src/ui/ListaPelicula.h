#ifndef LISTAPELICULA_H
#define LISTAPELICULA_H

#include "Movie.hpp"

class ListaPelicula {
private:
    Movie** peliculas;
    int numPeliculas;
    int capacidadPeliculas;

    void redimensionar(int nuevaCapacidad);

public:
    ListaPelicula();
    ~ListaPelicula();
    ListaPelicula(const ListaPelicula& otro);
    ListaPelicula& operator=(const ListaPelicula& otro);

    void agregar(Movie* pelicula);
    void remover(int indice);
    void removerPorId(int id);
    Movie* obtenerEnIndice(int indice);
    const Movie* obtenerEnIndice(int indice) const;
    int obtenerTamanio() const;
    void limpiar();
    bool estaVacia() const;
    Movie** obtenerArray();
    const Movie** obtenerArray() const;
};

#endif
