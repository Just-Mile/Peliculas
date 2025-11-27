#ifndef MOVIE_H
#define MOVIE_H

#include "MyString.hpp" 

class Movie {
private:
    
    int id;
    MyString titulo;          
    MyString duracionMinutos; 
    MyString estudio;         
    MyString sinopsis;        
    int fechaEstreno;
    double calificacionIMDB;
    double calificacionRottenTomatoes;
    double calificacionMetascore;
    MyString idiomaOriginal;      
    MyString paisOrigen;          
    bool esAnimacion;

    MyString* idiomasDisponibles; 
    int numIdiomas;              
    int capacidadIdiomas;        

    MyString* premios;           
    int numPremios;              
    int capacidadPremios;        

    MyString* directores;
    int numDirectores;
    int capacidadDirectores;

    MyString* generos;
    int numGeneros;
    int capacidadGeneros;

    void redimensionarIdiomas(int nuevaCapacidad);
    void redimensionarPremios(int nuevaCapacidad);
    void redimensionarDirectores(int nuevaCapacidad);
    void redimensionarGeneros(int nuevaCapacidad);

public:
    Movie(); 
    Movie(const Movie& otro);
    Movie& operator=(const Movie& otro);
    ~Movie();

    int obtenerId() const;
    void asignarId(int nuevoId);

    MyString obtenerTitulo() const;
    void asignarTitulo(const MyString& nuevoTitulo);

    MyString obtenerIdiomaOriginal() const;
    void asignarIdiomaOriginal(const MyString& idioma); 

    MyString obtenerPaisOrigen() const;
    void asignarPaisOrigen(const MyString& pais);

    double obtenerCalificacionMetascore() const;
    void asignarCalificacionMetascore(double calificacion);

    void agregarIdioma(const MyString& idioma);
    void agregarPremio(const MyString& premio);   
    void agregarDirector(const MyString& director);
    void agregarGenero(const MyString& genero); 

    const MyString* obtenerIdiomas() const; 
    int obtenerNumIdiomas() const;

    const MyString* obtenerGeneros() const;
    int obtenerNumGeneros() const;

    const MyString* obtenerDirectores() const;
    int obtenerNumDirectores() const;

    void mostrarInformacionCompleta() const;
    double calcularRT() const;
};

#endif