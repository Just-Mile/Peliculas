#include "Usuario.hpp"
#include "Movie.hpp"
#include <iostream>

const int CAPACIDAD_INICIAL_FAVORITAS = 5;
const int CAPACIDAD_INICIAL_RESENAS = 10;


Usuario::Usuario() 
    : id(0), nombreUsuario(), contrasena(),
      peliculasFavoritas(nullptr), numFavoritas(0), capacidadFavoritas(0), 
      resenaEscritas(nullptr), numResenas(0), capacidadResenas(0) {}

Usuario::Usuario(int idUsuario, const MyString& nombre, const MyString& pass)
    : id(idUsuario), nombreUsuario(nombre), contrasena(pass),
      peliculasFavoritas(nullptr), numFavoritas(0), capacidadFavoritas(0),
      resenaEscritas(nullptr), numResenas(0), capacidadResenas(0) {}

Usuario::~Usuario() {
    if (peliculasFavoritas != nullptr) {
        delete[] peliculasFavoritas;
    }
    if (resenaEscritas != nullptr) {
        delete[] resenaEscritas;
    }
}

Usuario::Usuario(const Usuario& otro)
    : id(otro.id), nombreUsuario(otro.nombreUsuario), contrasena(otro.contrasena),
      peliculasFavoritas(nullptr), numFavoritas(otro.numFavoritas), 
      capacidadFavoritas(otro.capacidadFavoritas),
      resenaEscritas(nullptr), numResenas(otro.numResenas), 
      capacidadResenas(otro.capacidadResenas) {

    if (otro.peliculasFavoritas != nullptr) {
        peliculasFavoritas = new Movie*[capacidadFavoritas];  
        for (int i = 0; i < numFavoritas; ++i) {
            peliculasFavoritas[i] = otro.peliculasFavoritas[i];
        }
    }

    if (otro.resenaEscritas != nullptr) {
        resenaEscritas = new MyString[capacidadResenas];
        for (int i = 0; i < numResenas; ++i) {
            resenaEscritas[i] = otro.resenaEscritas[i];
        }
    }
}

Usuario& Usuario::operator=(const Usuario& otro) {
    if (this == &otro) return *this;

    if (peliculasFavoritas != nullptr) delete[] peliculasFavoritas;
    if (resenaEscritas != nullptr) delete[] resenaEscritas;

    id = otro.id;
    nombreUsuario = otro.nombreUsuario;
    contrasena = otro.contrasena;
    numFavoritas = otro.numFavoritas;
    capacidadFavoritas = otro.capacidadFavoritas;
    numResenas = otro.numResenas;
    capacidadResenas = otro.capacidadResenas;

    if (otro.peliculasFavoritas != nullptr) {
        peliculasFavoritas = new Movie*[capacidadFavoritas];  
        for (int i = 0; i < numFavoritas; ++i) {
            peliculasFavoritas[i] = otro.peliculasFavoritas[i];
        }
    } else {
        peliculasFavoritas = nullptr;
    }

    if (otro.resenaEscritas != nullptr) {
        resenaEscritas = new MyString[capacidadResenas];
        for (int i = 0; i < numResenas; ++i) {
            resenaEscritas[i] = otro.resenaEscritas[i];
        }
    } else {
        resenaEscritas = nullptr;
    }

    return *this;
}

void Usuario::redimensionarFavoritas(int nuevaCapacidad) {
    Movie** nuevoArray = new Movie*[nuevaCapacidad];  
    for (int i = 0; i < numFavoritas; ++i) {
        nuevoArray[i] = peliculasFavoritas[i];
    }
    if (peliculasFavoritas != nullptr) {
        delete[] peliculasFavoritas;
    }
    peliculasFavoritas = nuevoArray;
    capacidadFavoritas = nuevaCapacidad;
}

void Usuario::redimensionarResenas(int nuevaCapacidad) {
    MyString* nuevoArray = new MyString[nuevaCapacidad];
    for (int i = 0; i < numResenas; ++i) {
        nuevoArray[i] = resenaEscritas[i];
    }
    if (resenaEscritas != nullptr) {
        delete[] resenaEscritas;
    }
    resenaEscritas = nuevoArray;
    capacidadResenas = nuevaCapacidad;
}

void Usuario::iniciarSesionUsuario(const MyString& nombre, const MyString& pass) {
    nombreUsuario = nombre;
    contrasena = pass;
    std::cout << "Sesion iniciada para: " << nombreUsuario.obtenerTexto() << std::endl;
}

void Usuario::cerrarSesion() {
    std::cout << "Sesion cerrada para: " << nombreUsuario.obtenerTexto() << std::endl;
}

void Usuario::buscarPeliculas(const MyString& criterio) {
    std::cout << "Buscando peliculas con criterio: " << criterio.obtenerTexto() << std::endl;
}

void Usuario::filtrarPeliculas(const MyString& genero) {
    std::cout << "Filtrando peliculas por genero: " << genero.obtenerTexto() << std::endl;
}

void Usuario::agregarAFavoritos(Movie* pelicula) {  
    if (numFavoritas == capacidadFavoritas) {
        int nuevaCapacidad = (capacidadFavoritas == 0) ? CAPACIDAD_INICIAL_FAVORITAS : capacidadFavoritas * 2;
        redimensionarFavoritas(nuevaCapacidad);
    }
    peliculasFavoritas[numFavoritas] = pelicula;
    numFavoritas++;
}

void Usuario::removerDeFavoritos(Movie* pelicula) {  
    for (int i = 0; i < numFavoritas; ++i) {
        if (peliculasFavoritas[i] == pelicula) {
            for (int j = i; j < numFavoritas - 1; ++j) {
                peliculasFavoritas[j] = peliculasFavoritas[j + 1];
            }
            numFavoritas--;
            break;
        }
    }
}

void Usuario::obtenerFavoritas() {
    for (int i = 0; i < numFavoritas; ++i) {
        if (peliculasFavoritas[i] != nullptr) {
            std::cout << "[" << (i + 1) << "] " 
                     << peliculasFavoritas[i]->obtenerTitulo().obtenerTexto()
                     << " (Metascore: " 
                     << peliculasFavoritas[i]->obtenerCalificacionMetascore() 
                     << ")" << std::endl;
        }
    }
}

bool Usuario::esFavorita(Movie* pelicula) const {  
    for (int i = 0; i < numFavoritas; ++i) {
        if (peliculasFavoritas[i] == pelicula) {
            return true;
        }
    }
    return false;
}

void Usuario::escribirResena(Movie* pelicula, const MyString& titulo, const MyString& texto, double calificacion) {  
    if (numResenas == capacidadResenas) {
        int nuevaCapacidad = (capacidadResenas == 0) ? CAPACIDAD_INICIAL_RESENAS : capacidadResenas * 2;
        redimensionarResenas(nuevaCapacidad);
    }
    resenaEscritas[numResenas] = titulo;
    numResenas++;
    std::cout << "Resena escrita para pelicula. Calificacion: " << calificacion << std::endl;
}

void Usuario::editarPerfilUsuario(const MyString& nuevoNombre, const MyString& nuevaEmail) {
    nombreUsuario = nuevoNombre;
    std::cout << "Perfil actualizado" << std::endl;
}

int Usuario::obtenerId() const {
    return id;
}

MyString Usuario::obtenerNombreUsuario() const {
    return nombreUsuario;
}

MyString Usuario::obtenerContrasena() const {
    return contrasena;
}

int Usuario::obtenerNumFavoritas() const {
    return numFavoritas;
}
