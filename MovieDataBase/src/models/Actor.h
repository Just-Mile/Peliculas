#ifndef ACTOR_H
#define ACTOR_H

#include "Cineasta.hpp"

class Actor : public Cineasta {
private:
   
    MyString* premios;
    int numPremios;
    int capacidadPremios;
    MyString tipoActor;  
    void redimensionarPremios(int nuevaCapacidad);

public:
    Actor();
    Actor(int idActor, const MyString& nom, const MyString& apel, const MyString& tipo);
    ~Actor();
    Actor(const Actor& otro);
    Actor& operator=(const Actor& otro);

    void abrirPerfil() override;
    void mostrarFilmografia() override;

    void obtenerPersonajes();
    int calcularAnosCarrera();
    void agregarPremio(const MyString& premio);
    MyString obtenerTipoActor() const;
};

#endif
