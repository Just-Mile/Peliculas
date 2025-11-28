#ifndef USUARIO_H
#define USUARIO_H

#include "MyString.hpp"

class Movie;

class Usuario {
private:
    
    int id;
    MyString nombreUsuario;
    MyString contrasena;

    Movie** peliculasFavoritas;
    int numFavoritas;
    int capacidadFavoritas;

    MyString* resenaEscritas;
    int numResenas;
    int capacidadResenas;

    void redimensionarFavoritas(int nuevaCapacidad);
    void redimensionarResenas(int nuevaCapacidad);

public:
    Usuario();
    Usuario(int idUsuario, const MyString& nombre, const MyString& pass);
    ~Usuario();
    Usuario(const Usuario& otro);
    Usuario& operator=(const Usuario& otro);

    void iniciarSesionUsuario(const MyString& nombre, const MyString& pass);
    void cerrarSesion();
    void buscarPeliculas(const MyString& criterio);
    void filtrarPeliculas(const MyString& genero);

    void agregarAFavoritos(Movie* pelicula);
    void removerDeFavoritos(Movie* pelicula);
    void obtenerFavoritas();
    bool esFavorita(Movie* pelicula) const;
    void escribirResena(Movie* pelicula, const MyString& titulo, const MyString& texto, double calificacion);

    void editarPerfilUsuario(const MyString& nuevoNombre, const MyString& nuevaEmail);

    int obtenerId() const;
    MyString obtenerNombreUsuario() const;
    MyString obtenerContrasena() const;
    int obtenerNumFavoritas() const;
};

#endif
