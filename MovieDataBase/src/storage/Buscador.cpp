#include "Buscador.hpp"
#include "Movie.hpp"
#include "Usuario.hpp"
#include <iostream>


const int CAPACIDAD_INICIAL_RESULTADOS = 10;

Buscador::Buscador() 
    : resultados(nullptr), numResultados(0), 
      capacidadResultados(CAPACIDAD_INICIAL_RESULTADOS), usuario(nullptr) {
 
    resultados = new Movie*[CAPACIDAD_INICIAL_RESULTADOS];
}

Buscador::Buscador(Usuario* user) 
    : resultados(nullptr), numResultados(0), 
      capacidadResultados(CAPACIDAD_INICIAL_RESULTADOS), usuario(user) {

    resultados = new Movie*[CAPACIDAD_INICIAL_RESULTADOS];
}

Buscador::~Buscador() {
    if (resultados != nullptr) {
        delete[] resultados;
    }
}

void Buscador::redimensionarResultados(int nuevaCapacidad) {
    Movie** nuevoArray = new Movie*[nuevaCapacidad];
    for (int i = 0; i < numResultados; ++i) {
        nuevoArray[i] = resultados[i];
    }
    if (resultados != nullptr) {
        delete[] resultados;
    }
    resultados = nuevoArray;
    capacidadResultados = nuevaCapacidad;
}

void Buscador::ejecutarBusqueda() {
    std::cout << "Ejecutando busqueda con criterio: " << criterio.obtenerTexto() << std::endl;
    
    if (usuario != nullptr) {
        std::cout << "Usuario: " << usuario->obtenerNombreUsuario().obtenerTexto() << std::endl;
    }
}

void Buscador::filtrarResultados(const MyString& genero) {
    std::cout << "Filtrando resultados por genero: " << genero.obtenerTexto() << std::endl;
}

void Buscador::ordenarPorFecha() {
    std::cout << "Ordenando resultados por fecha" << std::endl;
}

void Buscador::ordenarPorId() {
    std::cout << "Ordenando resultados por ID" << std::endl;
}

void Buscador::ordenarPorDuracion() {
    std::cout << "Ordenando resultados por duracion" << std::endl;
}

MyString Buscador::obtenerEstadisticas() {
    return MyString("Estadisticas del buscador");
}

void Buscador::asignarCriterio(const MyString& nuevoCriterio) {
    criterio = nuevoCriterio;
}

int Buscador::obtenerNumResultados() const {
    return numResultados;
}
