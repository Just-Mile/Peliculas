#include "Movie.hpp"    
#include "MyString.hpp" 
#include <iostream> 

const int CAPACIDAD_INICIAL = 5; 


Movie::Movie()
    : id(0), fechaEstreno(0), calificacionIMDB(0.0), 
      calificacionRottenTomatoes(0.0), calificacionMetascore(0.0),
      esAnimacion(false),
      idiomasDisponibles(nullptr), numIdiomas(0), capacidadIdiomas(0),
      premios(nullptr), numPremios(0), capacidadPremios(0),
      directores(nullptr), numDirectores(0), capacidadDirectores(0),
      generos(nullptr), numGeneros(0), capacidadGeneros(0) {}

void Movie::redimensionarIdiomas(int nuevaCapacidad) {
    MyString* nuevoArray = new MyString[nuevaCapacidad];
    for (int i = 0; i < numIdiomas; ++i) { 
        nuevoArray[i] = idiomasDisponibles[i]; 
    }
    if (idiomasDisponibles != nullptr) { 
        delete[] idiomasDisponibles; 
    }
    idiomasDisponibles = nuevoArray;
    capacidadIdiomas = nuevaCapacidad;
}

void Movie::redimensionarPremios(int nuevaCapacidad) {
    MyString* nuevoArray = new MyString[nuevaCapacidad];
    for (int i = 0; i < numPremios; ++i) { 
        nuevoArray[i] = premios[i]; 
    }
    if (premios != nullptr) { 
        delete[] premios; 
    }
    premios = nuevoArray;
    capacidadPremios = nuevaCapacidad;
}

void Movie::redimensionarDirectores(int nuevaCapacidad) {
    MyString* nuevoArray = new MyString[nuevaCapacidad];
    for (int i = 0; i < numDirectores; ++i) { 
        nuevoArray[i] = directores[i]; 
    }
    if (directores != nullptr) { 
        delete[] directores; 
    }
    directores = nuevoArray;
    capacidadDirectores = nuevaCapacidad;
}

void Movie::redimensionarGeneros(int nuevaCapacidad) {
    MyString* nuevoArray = new MyString[nuevaCapacidad];
    for (int i = 0; i < numGeneros; ++i) { 
        nuevoArray[i] = generos[i]; 
    }
    if (generos != nullptr) { 
        delete[] generos; 
    }
    generos = nuevoArray;
    capacidadGeneros = nuevaCapacidad;
}

Movie::~Movie() {
    if (idiomasDisponibles != nullptr) { delete[] idiomasDisponibles; }
    if (premios != nullptr) { delete[] premios; }
    if (directores != nullptr) { delete[] directores; }
    if (generos != nullptr) { delete[] generos; }
}


Movie::Movie(const Movie& otro)
    : id(otro.id), titulo(otro.titulo), duracionMinutos(otro.duracionMinutos),
      estudio(otro.estudio), sinopsis(otro.sinopsis), 
      fechaEstreno(otro.fechaEstreno), calificacionIMDB(otro.calificacionIMDB),
      calificacionRottenTomatoes(otro.calificacionRottenTomatoes),
      calificacionMetascore(otro.calificacionMetascore),
      idiomaOriginal(otro.idiomaOriginal), paisOrigen(otro.paisOrigen),
      esAnimacion(otro.esAnimacion),
      numIdiomas(otro.numIdiomas), capacidadIdiomas(otro.capacidadIdiomas),
      numPremios(otro.numPremios), capacidadPremios(otro.capacidadPremios),
      numDirectores(otro.numDirectores), capacidadDirectores(otro.capacidadDirectores),
      numGeneros(otro.numGeneros), capacidadGeneros(otro.capacidadGeneros) {

    if (otro.idiomasDisponibles != nullptr) {
        idiomasDisponibles = new MyString[capacidadIdiomas];
        for (int i = 0; i < numIdiomas; ++i) { 
            idiomasDisponibles[i] = otro.idiomasDisponibles[i]; 
        }
    } else { 
        idiomasDisponibles = nullptr; 
    }

    if (otro.premios != nullptr) {
        premios = new MyString[capacidadPremios];
        for (int i = 0; i < numPremios; ++i) { 
            premios[i] = otro.premios[i]; 
        }
    } else { 
        premios = nullptr; 
    }

    if (otro.directores != nullptr) {
        directores = new MyString[capacidadDirectores];
        for (int i = 0; i < numDirectores; ++i) { 
            directores[i] = otro.directores[i]; 
        }
    } else { 
        directores = nullptr; 
    }

    if (otro.generos != nullptr) {
        generos = new MyString[capacidadGeneros];
        for (int i = 0; i < numGeneros; ++i) { 
            generos[i] = otro.generos[i]; 
        }
    } else { 
        generos = nullptr; 
    }
}

Movie& Movie::operator=(const Movie& otro) {
    if (this == &otro) { return *this; } 

    if (idiomasDisponibles != nullptr) delete[] idiomasDisponibles;
    if (premios != nullptr) delete[] premios;
    if (directores != nullptr) delete[] directores;
    if (generos != nullptr) delete[] generos;

    id = otro.id;
    titulo = otro.titulo; 
    duracionMinutos = otro.duracionMinutos; 
    estudio = otro.estudio; 
    sinopsis = otro.sinopsis;
    fechaEstreno = otro.fechaEstreno;
    calificacionIMDB = otro.calificacionIMDB;
    calificacionRottenTomatoes = otro.calificacionRottenTomatoes;
    calificacionMetascore = otro.calificacionMetascore;
    idiomaOriginal = otro.idiomaOriginal; 
    paisOrigen = otro.paisOrigen;         
    esAnimacion = otro.esAnimacion;
    numIdiomas = otro.numIdiomas; 
    capacidadIdiomas = otro.capacidadIdiomas;
    numPremios = otro.numPremios; 
    capacidadPremios = otro.capacidadPremios;
    numDirectores = otro.numDirectores; 
    capacidadDirectores = otro.capacidadDirectores;
    numGeneros = otro.numGeneros; 
    capacidadGeneros = otro.capacidadGeneros;

    if (otro.idiomasDisponibles != nullptr) {
        idiomasDisponibles = new MyString[capacidadIdiomas];
        for (int i = 0; i < numIdiomas; ++i) { 
            idiomasDisponibles[i] = otro.idiomasDisponibles[i]; 
        }
    } else { 
        idiomasDisponibles = nullptr; 
    }

    if (otro.premios != nullptr) {
        premios = new MyString[capacidadPremios];
        for (int i = 0; i < numPremios; ++i) { 
            premios[i] = otro.premios[i]; 
        }
    } else { 
        premios = nullptr; 
    }

    if (otro.directores != nullptr) {
        directores = new MyString[capacidadDirectores];
        for (int i = 0; i < numDirectores; ++i) { 
            directores[i] = otro.directores[i]; 
        }
    } else { 
        directores = nullptr; 
    }

    if (otro.generos != nullptr) {
        generos = new MyString[capacidadGeneros];
        for (int i = 0; i < numGeneros; ++i) { 
            generos[i] = otro.generos[i]; 
        }
    } else { 
        generos = nullptr; 
    }

    return *this;
}

void Movie::agregarIdioma(const MyString& idioma) {
    if (numIdiomas == capacidadIdiomas) {
        int nuevaCapacidad = (capacidadIdiomas == 0) ? CAPACIDAD_INICIAL : capacidadIdiomas * 2;
        redimensionarIdiomas(nuevaCapacidad);
    }
    idiomasDisponibles[numIdiomas] = idioma; 
    numIdiomas++;
}

void Movie::agregarPremio(const MyString& premio) {
    if (numPremios == capacidadPremios) {
        int nuevaCapacidad = (capacidadPremios == 0) ? CAPACIDAD_INICIAL : capacidadPremios * 2;
        redimensionarPremios(nuevaCapacidad);
    }
    premios[numPremios] = premio; 
    numPremios++;
}

void Movie::agregarDirector(const MyString& director) {
    if (numDirectores == capacidadDirectores) {
        int nuevaCapacidad = (capacidadDirectores == 0) ? CAPACIDAD_INICIAL : capacidadDirectores * 2;
        redimensionarDirectores(nuevaCapacidad);
    }
    directores[numDirectores] = director; 
    numDirectores++;
}

void Movie::agregarGenero(const MyString& genero) {
    if (numGeneros == capacidadGeneros) {
        int nuevaCapacidad = (capacidadGeneros == 0) ? CAPACIDAD_INICIAL : capacidadGeneros * 2;
        redimensionarGeneros(nuevaCapacidad);
    }
    generos[numGeneros] = genero; 
    numGeneros++;
}

void Movie::asignarIdiomaOriginal(const MyString& idioma) {
    idiomaOriginal = idioma;
}

void Movie::asignarPaisOrigen(const MyString& pais) {
    paisOrigen = pais;
}

MyString Movie::obtenerIdiomaOriginal() const {
    return idiomaOriginal;
}

MyString Movie::obtenerPaisOrigen() const {
    return paisOrigen;
}

double Movie::obtenerCalificacionMetascore() const {
    return calificacionMetascore;
}

void Movie::asignarCalificacionMetascore(double calificacion) {
    calificacionMetascore = calificacion;
}

int Movie::obtenerId() const {
    return id;
}

void Movie::asignarId(int nuevoId) {
    id = nuevoId;
}

MyString Movie::obtenerTitulo() const {
    return titulo;
}

void Movie::asignarTitulo(const MyString& nuevoTitulo) {
    titulo = nuevoTitulo; 
}

const MyString* Movie::obtenerIdiomas() const {
    return idiomasDisponibles;
}

int Movie::obtenerNumIdiomas() const {
    return numIdiomas;
}

const MyString* Movie::obtenerGeneros() const {
    return generos;
}

int Movie::obtenerNumGeneros() const {
    return numGeneros;
}

const MyString* Movie::obtenerDirectores() const {
    return directores;
}

int Movie::obtenerNumDirectores() const {
    return numDirectores;
}

void Movie::mostrarInformacionCompleta() const {
    std::cout << "--- Pelicula: " << titulo.obtenerTexto() << " ---" << std::endl;
    std::cout << "ID: " << id << " | Estreno: " << fechaEstreno << std::endl;
    std::cout << "Pais: " << paisOrigen.obtenerTexto() << " | Idioma Original: " << idiomaOriginal.obtenerTexto() << std::endl;
    std::cout << "Calificaciones: IMDB=" << calificacionIMDB << ", RT=" << calificacionRottenTomatoes << ", Metascore=" << calificacionMetascore << std::endl;
}

double Movie::calcularRT() const {
    return calificacionRottenTomatoes;
}