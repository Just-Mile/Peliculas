#include "Movie.hpp"


Movie::Movie()
    : id(0), fechaEstreno(0), duracionMinutos(0),
      numIdiomas(0), numGeneros(0), numPremios(0),
      numDirectores(0),
      calificacionRottenTomatoes(0), calificacionIMDb(0),
      calificacionMetascore(0), calificacionPopular(0),
      esAnimacion(false),
      resenaCalificacion(0), resenaLikes(0), resenaDislikes(0),
      resenaAutor(nullptr),
      generoId(0) {}


//setters
void Movie::asignarId(int v) { id = v; }
void Movie::asignarTitulo(const MyString& s) { titulo = s; }
void Movie::asignarFechaEstreno(int f) { fechaEstreno = f; }
void Movie::asignarDuracionMinutos(int d) { duracionMinutos = d; }
void Movie::asignarSinopsis(const MyString& s) { sinopsis = s; }
void Movie::asignarEstudio(const MyString& e) { estudio = e; }
void Movie::asignarIdiomaOriginal(const MyString& i) { idiomaOriginal = i; }

void Movie::agregarIdiomaDisponible(const MyString& i) {
    if (numIdiomas < 20) idiomasDisponibles[numIdiomas++] = i;
}

void Movie::agregarIdioma(const MyString& i) {
    agregarIdiomaDisponible(i);
}

void Movie::agregarGenero(const MyString& g) {
    if (numGeneros < 20) generos[numGeneros++] = g;
}

void Movie::agregarPremio(const MyString& p) {
    if (numPremios < 20) premios[numPremios++] = p;
}

void Movie::agregarDirector(const MyString& d) {
    if (numDirectores < 20) directores[numDirectores++] = d;
}

void Movie::asignarCalificacionRotten(double c) { calificacionRottenTomatoes = c; }
void Movie::asignarCalificacionIMDb(double c) { calificacionIMDb = c; }
void Movie::asignarCalificacionMetascore(double c) { calificacionMetascore = c; }
void Movie::asignarCalificacionPopular(double c) { calificacionPopular = c; }

void Movie::asignarPaisOrigen(const MyString& p) { paisOrigen = p; }
void Movie::asignarEsAnimacion(bool v) { esAnimacion = v; }
void Movie::asignarClasificacion(const MyString& c) { clasificacion = c; }

void Movie::asignarResenaContenido(const MyString& c) { resenaContenido = c; }
void Movie::asignarResenaCalificacion(double cal) { resenaCalificacion = cal; }
void Movie::asignarResenaFecha(const MyString& f) { resenaFecha = f; }
void Movie::asignarResenaLikes(int n) { resenaLikes = n; }
void Movie::asignarResenaDislikes(int n) { resenaDislikes = n; }
void Movie::asignarResenaAutor(Usuario* u) { resenaAutor = u; }

void Movie::asignarGeneroId(int g) { generoId = g; }

// Getters

int Movie::obtenerId() const { return id; }
MyString Movie::obtenerTitulo() const { return titulo; }
int Movie::obtenerFechaEstreno() const { return fechaEstreno; }
int Movie::obtenerDuracionMinutos() const { return duracionMinutos; }
MyString Movie::obtenerSinopsis() const { return sinopsis; }
MyString Movie::obtenerEstudio() const { return estudio; }
MyString Movie::obtenerIdiomaOriginal() const { return idiomaOriginal; }

const MyString* Movie::obtenerIdiomasDisponibles() const { return idiomasDisponibles; }
const MyString* Movie::obtenerIdiomas() const { return idiomasDisponibles; }
int Movie::obtenerNumIdiomas() const { return numIdiomas; }

const MyString* Movie::obtenerGeneros() const { return generos; }
int Movie::obtenerNumGeneros() const { return numGeneros; }

const MyString* Movie::obtenerPremios() const { return premios; }
int Movie::obtenerNumPremios() const { return numPremios; }

const MyString* Movie::obtenerDirectores() const { return directores; }
int Movie::obtenerNumDirectores() const { return numDirectores; }

double Movie::obtenerCalificacionRotten() const { return calificacionRottenTomatoes; }
double Movie::obtenerCalificacionIMDb() const { return calificacionIMDb; }
double Movie::obtenerCalificacionMetascore() const { return calificacionMetascore; }
double Movie::obtenerCalificacionPopular() const { return calificacionPopular; }

MyString Movie::obtenerPaisOrigen() const { return paisOrigen; }
bool Movie::obtenerEsAnimacion() const { return esAnimacion; }
MyString Movie::obtenerClasificacion() const { return clasificacion; }

MyString Movie::obtenerResenaContenido() const { return resenaContenido; }
double Movie::obtenerResenaCalificacion() const { return resenaCalificacion; }
MyString Movie::obtenerResenaFecha() const { return resenaFecha; }
int Movie::obtenerResenaLikes() const { return resenaLikes; }
int Movie::obtenerResenaDislikes() const { return resenaDislikes; }
Usuario* Movie::obtenerResenaAutor() const { return resenaAutor; }

int Movie::obtenerGeneroId() const { return generoId; }
