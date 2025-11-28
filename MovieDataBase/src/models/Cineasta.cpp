#include "Cineasta.hpp"
#include <iostream>

Cineasta::Cineasta() : id(0), edad(0) {}

Cineasta::Cineasta(int idCineasta, const MyString& nom, const MyString& apel)
    : id(idCineasta), nombre(nom), apellido(apel), edad(0) {}

Cineasta::Cineasta(const Cineasta& otro)
    : id(otro.id), nombre(otro.nombre), apellido(otro.apellido),
      edad(otro.edad), nacionalidad(otro.nacionalidad),
      biografia(otro.biografia), fechaNacimiento(otro.fechaNacimiento),
      lugarNacimiento(otro.lugarNacimiento) {}

Cineasta& Cineasta::operator=(const Cineasta& otro) {
    if (this == &otro) return *this;

    id = otro.id;
    nombre = otro.nombre;
    apellido = otro.apellido;
    edad = otro.edad;
    nacionalidad = otro.nacionalidad;
    biografia = otro.biografia;
    fechaNacimiento = otro.fechaNacimiento;
    lugarNacimiento = otro.lugarNacimiento;

    return *this;
}

Cineasta::~Cineasta() {}

void Cineasta::obtenerPeliculas() {
    std::cout << "Peliculas relacionadas con " << nombre.obtenerTexto() 
              << " " << apellido.obtenerTexto() << std::endl;
}

int Cineasta::calcularEdad() const {
    return edad;
}

void Cineasta::actualizarBiografia(const MyString& texto) {
    biografia = texto;
    std::cout << "Biografia actualizada para " << nombre.obtenerTexto() << std::endl;
}

int Cineasta::obtenerId() const {
    return id;
}

MyString Cineasta::obtenerNombre() const {
    return nombre;
}

MyString Cineasta::obtenerApellido() const {
    return apellido;
}

void Cineasta::asignarId(int nuevoId) {
    id = nuevoId;
}

void Cineasta::asignarNombre(const MyString& nuevoNombre) {
    nombre = nuevoNombre;
}

void Cineasta::asignarApellido(const MyString& nuevoApellido) {
    apellido = nuevoApellido;
}
