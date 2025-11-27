#ifndef BUSCADOR_H
#define BUSCADOR_H

#include "MyString.hpp"

class Usuario;
class Movie;

class Buscador {
private:
    MyString criterio;
    Movie** resultados;
    int numResultados;
    int capacidadResultados;
    Usuario* usuario;

    void redimensionarResultados(int nuevaCapacidad);

public:
    Buscador();
    Buscador(Usuario* user);
    ~Buscador();

    void ejecutarBusqueda();
    void filtrarResultados(const MyString& genero);
    void ordenarPorFecha();
    void ordenarPorId();
    void ordenarPorDuracion();
    MyString obtenerEstadisticas();
    void asignarCriterio(const MyString& nuevoCriterio);
    int obtenerNumResultados() const;
};

#endif
