#ifndef DATABASE_H
#define DATABASE_H

#include "Movie.hpp"
#include "Usuario.hpp"
#include "Actor.hpp"
#include "Director.hpp"

class Database {
private:
    Movie* peliculas;
    int numPeliculas;
    int capacidadPeliculas;

    Usuario* usuarios;
    int numUsuarios;
    int capacidadUsuarios;

    Actor* actores;
    int numActores;
    int capacidadActores;

    Director* directores;
    int numDirectores;
    int capacidadDirectores;

    void redimensionarPeliculas(int nuevaCapacidad);
    void redimensionarUsuarios(int nuevaCapacidad);
    void redimensionarActores(int nuevaCapacidad);
    void redimensionarDirectores(int nuevaCapacidad);

    int buscarIndicePeliculaPorId(int id) const;
    int buscarIndiceUsuarioPorId(int id) const;
    int buscarIndiceActorPorId(int id) const;
    int buscarIndiceDirectorPorId(int id) const;

    bool textoContiene(const MyString& textoGrande, const MyString& textoPequeno) const;

public:
    Database();
    ~Database();
    Database(const Database& otro);
    Database& operator=(const Database& otro);


   
    bool agregarPelicula(const Movie& pelicula);
    bool eliminarPelicula(int id);
    Movie* buscarPeliculaPorId(int id);
    const Movie* buscarPeliculaPorId(int id) const;
    Movie* buscarPeliculasPorTitulo(const MyString& titulo, int& numResultados);
    Movie* filtrarPeliculasPorGenero(const MyString& genero, int& numResultados);
    int obtenerNumPeliculas() const;
    const Movie* obtenerPeliculas() const;



    bool agregarUsuario(const Usuario& usuario);
    bool eliminarUsuario(int id);
    Usuario* buscarUsuarioPorId(int id);
    Usuario* buscarUsuarioPorNombre(const MyString& nombre);
    int obtenerNumUsuarios() const;
    const Usuario* obtenerUsuarios() const;



    bool agregarActor(const Actor& actor);
    bool eliminarActor(int id);
    Actor* buscarActorPorId(int id);
    Actor* buscarActoresPorNombre(const MyString& nombre, int& numResultados);
    int obtenerNumActores() const;
    const Actor* obtenerActores() const;

    
    bool agregarDirector(const Director& director);
    bool eliminarDirector(int id);
    Director* buscarDirectorPorId(int id);
    Director* buscarDirectoresPorNombre(const MyString& nombre, int& numResultados);
    int obtenerNumDirectores() const;
    const Director* obtenerDirectores() const;
};

#endif