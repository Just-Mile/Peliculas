#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "MyString.hpp"
#include "Usuario.hpp"

class Movie {
private:
   
    int id;
    MyString titulo;
    int fechaEstreno;
    int duracionMinutos;
    MyString sinopsis;
    MyString estudio;
    MyString idiomaOriginal;

    
    MyString idiomasDisponibles[20];
    int numIdiomas;

    MyString generos[20];
    int numGeneros;

    MyString premios[20];
    int numPremios;

   
    MyString directores[20];
    int numDirectores;

    
    double calificacionRottenTomatoes;
    double calificacionIMDb;
    double calificacionMetascore;
    double calificacionPopular;

  
    MyString paisOrigen;
    bool esAnimacion;
    MyString clasificacion;

    
    MyString resenaContenido;
    double resenaCalificacion;
    MyString resenaFecha;
    int resenaLikes;
    int resenaDislikes;
    Usuario* resenaAutor;

    
    int generoId;

public:
    Movie();

    // Setters
    void asignarId(int);
    void asignarTitulo(const MyString&);
    void asignarFechaEstreno(int);
    void asignarDuracionMinutos(int);
    void asignarSinopsis(const MyString&);
    void asignarEstudio(const MyString&);
    void asignarIdiomaOriginal(const MyString&);

    void agregarIdiomaDisponible(const MyString&);
    void agregarIdioma(const MyString&);  

    void agregarGenero(const MyString&);
    void agregarPremio(const MyString&);

    void agregarDirector(const MyString&); 

    void asignarCalificacionRotten(double);
    void asignarCalificacionIMDb(double);
    void asignarCalificacionMetascore(double);
    void asignarCalificacionPopular(double);

    
    void asignarCalificacionIMDB(double c) { asignarCalificacionIMDb(c); }
    void asignarCalificacionRottenTomatoes(double c) { asignarCalificacionRotten(c); }

    void asignarPaisOrigen(const MyString&);
    void asignarEsAnimacion(bool);
    void asignarClasificacion(const MyString&);

    void asignarResenaContenido(const MyString&);
    void asignarResenaCalificacion(double);
    void asignarResenaFecha(const MyString&);
    void asignarResenaLikes(int);
    void asignarResenaDislikes(int);
    void asignarResenaAutor(Usuario*);

    void asignarGeneroId(int);

    // Getters
    int obtenerId() const;
    MyString obtenerTitulo() const;
    int obtenerFechaEstreno() const;
    int obtenerDuracionMinutos() const;
    MyString obtenerSinopsis() const;
    MyString obtenerEstudio() const;
    MyString obtenerIdiomaOriginal() const;

    const MyString* obtenerIdiomasDisponibles() const;
    const MyString* obtenerIdiomas() const; 
    int obtenerNumIdiomas() const;

    const MyString* obtenerGeneros() const;
    int obtenerNumGeneros() const;

    const MyString* obtenerPremios() const;
    int obtenerNumPremios() const;

    const MyString* obtenerDirectores() const;  
    int obtenerNumDirectores() const;

    double obtenerCalificacionRotten() const;
    double obtenerCalificacionIMDb() const;
    double obtenerCalificacionMetascore() const;
    double obtenerCalificacionPopular() const;

    MyString obtenerPaisOrigen() const;
    bool obtenerEsAnimacion() const;
    MyString obtenerClasificacion() const;

    MyString obtenerResenaContenido() const;
    double obtenerResenaCalificacion() const;
    MyString obtenerResenaFecha() const;
    int obtenerResenaLikes() const;
    int obtenerResenaDislikes() const;
    Usuario* obtenerResenaAutor() const;

    int obtenerGeneroId() const;
};

#endif
