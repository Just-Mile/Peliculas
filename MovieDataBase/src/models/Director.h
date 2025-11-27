#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Cineasta.hpp"

class Director : public Cineasta {
private:


    MyString estiloDirector;  
    MyString* premios;
    int numPremios;
    int capacidadPremios;
    int anosExperiencia;

    void redimensionarPremios(int nuevaCapacidad);

public:
    Director();
    Director(int idDirector, const MyString& nom, const MyString& apel, const MyString& estilo);
    ~Director();
    Director(const Director& otro);
    Director& operator=(const Director& otro);

    void abrirPerfil() override;
    void mostrarFilmografia() override;

    void obtenerPeliculasDirigidas();
    int calcularProductividad();
    void agregarPremio(const MyString& premio);
    MyString obtenerEstiloDirector() const;
};

#endif