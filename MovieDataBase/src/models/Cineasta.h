#ifndef CINEASTA_H
#define CINEASTA_H

#include "MyString.hpp"

class Movie;

class Cineasta {
protected:
    int id;
    MyString nombre;
    MyString apellido;
    int edad;
    MyString nacionalidad;
    MyString biografia;
    MyString fechaNacimiento;
    MyString lugarNacimiento;

public:
    Cineasta();
    Cineasta(int idCineasta, const MyString& nom, const MyString& apel);
    Cineasta(const Cineasta& otro);
    Cineasta& operator=(const Cineasta& otro);
    virtual ~Cineasta();

    virtual void abrirPerfil() = 0;
    virtual void mostrarFilmografia() = 0;

    void obtenerPeliculas();
    int calcularEdad() const;
    void actualizarBiografia(const MyString& texto);

    int obtenerId() const;
    MyString obtenerNombre() const;
    MyString obtenerApellido() const;

    void asignarId(int nuevoId);
    void asignarNombre(const MyString& nuevoNombre);
    void asignarApellido(const MyString& nuevoApellido);
};

#endif
