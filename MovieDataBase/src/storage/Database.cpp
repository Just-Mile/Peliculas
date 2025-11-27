#include "Database.hpp"

const int CAPACIDAD_INICIAL_DB = 10;

Database::Database() 
    : peliculas(nullptr), numPeliculas(0), capacidadPeliculas(0),
      usuarios(nullptr), numUsuarios(0), capacidadUsuarios(0),
      actores(nullptr), numActores(0), capacidadActores(0),
      directores(nullptr), numDirectores(0), capacidadDirectores(0) {

    peliculas = new Movie[CAPACIDAD_INICIAL_DB];
    capacidadPeliculas = CAPACIDAD_INICIAL_DB;

    usuarios = new Usuario[CAPACIDAD_INICIAL_DB];
    capacidadUsuarios = CAPACIDAD_INICIAL_DB;

    actores = new Actor[CAPACIDAD_INICIAL_DB];
    capacidadActores = CAPACIDAD_INICIAL_DB;

    directores = new Director[CAPACIDAD_INICIAL_DB];
    capacidadDirectores = CAPACIDAD_INICIAL_DB;
}

Database::~Database() {
    if (peliculas != nullptr) delete[] peliculas;
    if (usuarios != nullptr) delete[] usuarios;
    if (actores != nullptr) delete[] actores;
    if (directores != nullptr) delete[] directores;
}

Database::Database(const Database& otro)
    : numPeliculas(otro.numPeliculas), capacidadPeliculas(otro.capacidadPeliculas),
      numUsuarios(otro.numUsuarios), capacidadUsuarios(otro.capacidadUsuarios),
      numActores(otro.numActores), capacidadActores(otro.capacidadActores),
      numDirectores(otro.numDirectores), capacidadDirectores(otro.capacidadDirectores) {

    peliculas = new Movie[capacidadPeliculas];
    for (int i = 0; i < numPeliculas; ++i) {
        peliculas[i] = otro.peliculas[i];
    }

    usuarios = new Usuario[capacidadUsuarios];
    for (int i = 0; i < numUsuarios; ++i) {
        usuarios[i] = otro.usuarios[i];
    }

    actores = new Actor[capacidadActores];
    for (int i = 0; i < numActores; ++i) {
        actores[i] = otro.actores[i];
    }

    directores = new Director[capacidadDirectores];
    for (int i = 0; i < numDirectores; ++i) {
        directores[i] = otro.directores[i];
    }
}

Database& Database::operator=(const Database& otro) {
    if (this == &otro) return *this;

    if (peliculas != nullptr) delete[] peliculas;
    if (usuarios != nullptr) delete[] usuarios;
    if (actores != nullptr) delete[] actores;
    if (directores != nullptr) delete[] directores;

    numPeliculas = otro.numPeliculas;
    capacidadPeliculas = otro.capacidadPeliculas;
    numUsuarios = otro.numUsuarios;
    capacidadUsuarios = otro.capacidadUsuarios;
    numActores = otro.numActores;
    capacidadActores = otro.capacidadActores;
    numDirectores = otro.numDirectores;
    capacidadDirectores = otro.capacidadDirectores;

    peliculas = new Movie[capacidadPeliculas];
    for (int i = 0; i < numPeliculas; ++i) {
        peliculas[i] = otro.peliculas[i];
    }

    usuarios = new Usuario[capacidadUsuarios];
    for (int i = 0; i < numUsuarios; ++i) {
        usuarios[i] = otro.usuarios[i];
    }

    actores = new Actor[capacidadActores];
    for (int i = 0; i < numActores; ++i) {
        actores[i] = otro.actores[i];
    }

    directores = new Director[capacidadDirectores];
    for (int i = 0; i < numDirectores; ++i) {
        directores[i] = otro.directores[i];
    }

    return *this;
}



void Database::redimensionarPeliculas(int nuevaCapacidad) {
    Movie* nuevoArray = new Movie[nuevaCapacidad];
    for (int i = 0; i < numPeliculas; ++i) {
        nuevoArray[i] = peliculas[i];
    }
    delete[] peliculas;
    peliculas = nuevoArray;
    capacidadPeliculas = nuevaCapacidad;
}

int Database::buscarIndicePeliculaPorId(int id) const {
    for (int i = 0; i < numPeliculas; ++i) {
        if (peliculas[i].obtenerId() == id) {
            return i;
        }
    }
    return -1;
}

bool Database::agregarPelicula(const Movie& pelicula) {
    if (numPeliculas == capacidadPeliculas) {
        redimensionarPeliculas(capacidadPeliculas * 2);
    }
    peliculas[numPeliculas] = pelicula;
    numPeliculas++;
    return true;
}

bool Database::eliminarPelicula(int id) {
    int indice = buscarIndicePeliculaPorId(id);
    if (indice == -1) return false;

    for (int i = indice; i < numPeliculas - 1; ++i) {
        peliculas[i] = peliculas[i + 1];
    }
    numPeliculas--;
    return true;
}

Movie* Database::buscarPeliculaPorId(int id) {
    int indice = buscarIndicePeliculaPorId(id);
    if (indice == -1) return nullptr;
    return &peliculas[indice];
}

const Movie* Database::buscarPeliculaPorId(int id) const {
    int indice = buscarIndicePeliculaPorId(id);
    if (indice == -1) return nullptr;
    return &peliculas[indice];
}

bool Database::textoContiene(const MyString& textoGrande, const MyString& textoPequeno) const {
    const char* grande = textoGrande.obtenerTexto();
    const char* pequeno = textoPequeno.obtenerTexto();

    int lenGrande = textoGrande.obtenerLongitud();
    int lenPequeno = textoPequeno.obtenerLongitud();

    if (lenPequeno == 0) return true;
    if (lenPequeno > lenGrande) return false;

    for (int i = 0; i <= lenGrande - lenPequeno; ++i) {
        bool encontrado = true;
        for (int j = 0; j < lenPequeno; ++j) {
            char c1 = grande[i + j];
            char c2 = pequeno[j];
            if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32;
            if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32;
            if (c1 != c2) {
                encontrado = false;
                break;
            }
        }
        if (encontrado) return true;
    }
    return false;
}

Movie* Database::buscarPeliculasPorTitulo(const MyString& titulo, int& numResultados) {
    numResultados = 0;
    if (titulo.obtenerLongitud() == 0) return nullptr;

    for (int i = 0; i < numPeliculas; ++i) {
        if (textoContiene(peliculas[i].obtenerTitulo(), titulo)) {
            numResultados++;
        }
    }

    if (numResultados == 0) return nullptr;

    Movie* resultados = new Movie[numResultados];
    int indiceResultado = 0;

    for (int i = 0; i < numPeliculas; ++i) {
        if (textoContiene(peliculas[i].obtenerTitulo(), titulo)) {
            resultados[indiceResultado] = peliculas[i];
            indiceResultado++;
        }
    }

    return resultados;
}

Movie* Database::filtrarPeliculasPorGenero(const MyString& genero, int& numResultados) {
    numResultados = 0;
    if (genero.obtenerLongitud() == 0) return nullptr;

    for (int i = 0; i < numPeliculas; ++i) {
        const MyString* generos = peliculas[i].obtenerGeneros();
        int numGeneros = peliculas[i].obtenerNumGeneros();

        for (int j = 0; j < numGeneros; ++j) {
            if (textoContiene(generos[j], genero)) {
                numResultados++;
                break;
            }
        }
    }

    if (numResultados == 0) return nullptr;

    Movie* resultados = new Movie[numResultados];
    int indiceResultado = 0;

    for (int i = 0; i < numPeliculas; ++i) {
        const MyString* generos = peliculas[i].obtenerGeneros();
        int numGeneros = peliculas[i].obtenerNumGeneros();

        for (int j = 0; j < numGeneros; ++j) {
            if (textoContiene(generos[j], genero)) {
                resultados[indiceResultado] = peliculas[i];
                indiceResultado++;
                break;
            }
        }
    }

    return resultados;
}

int Database::obtenerNumPeliculas() const {
    return numPeliculas;
}

const Movie* Database::obtenerPeliculas() const {
    return peliculas;
}



void Database::redimensionarUsuarios(int nuevaCapacidad) {
    Usuario* nuevoArray = new Usuario[nuevaCapacidad];
    for (int i = 0; i < numUsuarios; ++i) {
        nuevoArray[i] = usuarios[i];
    }
    delete[] usuarios;
    usuarios = nuevoArray;
    capacidadUsuarios = nuevaCapacidad;
}

int Database::buscarIndiceUsuarioPorId(int id) const {
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].obtenerId() == id) {
            return i;
        }
    }
    return -1;
}

bool Database::agregarUsuario(const Usuario& usuario) {
    if (numUsuarios == capacidadUsuarios) {
        redimensionarUsuarios(capacidadUsuarios * 2);
    }
    usuarios[numUsuarios] = usuario;
    numUsuarios++;
    return true;
}

bool Database::eliminarUsuario(int id) {
    int indice = buscarIndiceUsuarioPorId(id);
    if (indice == -1) return false;

    for (int i = indice; i < numUsuarios - 1; ++i) {
        usuarios[i] = usuarios[i + 1];
    }
    numUsuarios--;
    return true;
}

Usuario* Database::buscarUsuarioPorId(int id) {
    int indice = buscarIndiceUsuarioPorId(id);
    if (indice == -1) return nullptr;
    return &usuarios[indice];
}

Usuario* Database::buscarUsuarioPorNombre(const MyString& nombre) {
    for (int i = 0; i < numUsuarios; ++i) {
        if (textoContiene(usuarios[i].obtenerNombreUsuario(), nombre)) {
            return &usuarios[i];
        }
    }
    return nullptr;
}

int Database::obtenerNumUsuarios() const {
    return numUsuarios;
}

const Usuario* Database::obtenerUsuarios() const {
    return usuarios;
}



void Database::redimensionarActores(int nuevaCapacidad) {
    Actor* nuevoArray = new Actor[nuevaCapacidad];
    for (int i = 0; i < numActores; ++i) {
        nuevoArray[i] = actores[i];
    }
    delete[] actores;
    actores = nuevoArray;
    capacidadActores = nuevaCapacidad;
}

int Database::buscarIndiceActorPorId(int id) const {
    for (int i = 0; i < numActores; ++i) {
        if (actores[i].obtenerId() == id) {
            return i;
        }
    }
    return -1;
}

bool Database::agregarActor(const Actor& actor) {
    if (numActores == capacidadActores) {
        redimensionarActores(capacidadActores * 2);
    }
    actores[numActores] = actor;
    numActores++;
    return true;
}

bool Database::eliminarActor(int id) {
    int indice = buscarIndiceActorPorId(id);
    if (indice == -1) return false;

    for (int i = indice; i < numActores - 1; ++i) {
        actores[i] = actores[i + 1];
    }
    numActores--;
    return true;
}

Actor* Database::buscarActorPorId(int id) {
    int indice = buscarIndiceActorPorId(id);
    if (indice == -1) return nullptr;
    return &actores[indice];
}

Actor* Database::buscarActoresPorNombre(const MyString& nombre, int& numResultados) {
    numResultados = 0;
    if (nombre.obtenerLongitud() == 0) return nullptr;

    for (int i = 0; i < numActores; ++i) {
        if (textoContiene(actores[i].obtenerNombre(), nombre) ||
            textoContiene(actores[i].obtenerApellido(), nombre)) {
            numResultados++;
        }
    }

    if (numResultados == 0) return nullptr;

    Actor* resultados = new Actor[numResultados];
    int indiceResultado = 0;

    for (int i = 0; i < numActores; ++i) {
        if (textoContiene(actores[i].obtenerNombre(), nombre) ||
            textoContiene(actores[i].obtenerApellido(), nombre)) {
            resultados[indiceResultado] = actores[i];
            indiceResultado++;
        }
    }

    return resultados;
}

int Database::obtenerNumActores() const {
    return numActores;
}

const Actor* Database::obtenerActores() const {
    return actores;
}



void Database::redimensionarDirectores(int nuevaCapacidad) {
    Director* nuevoArray = new Director[nuevaCapacidad];
    for (int i = 0; i < numDirectores; ++i) {
        nuevoArray[i] = directores[i];
    }
    delete[] directores;
    directores = nuevoArray;
    capacidadDirectores = nuevaCapacidad;
}

int Database::buscarIndiceDirectorPorId(int id) const {
    for (int i = 0; i < numDirectores; ++i) {
        if (directores[i].obtenerId() == id) {
            return i;
        }
    }
    return -1;
}

bool Database::agregarDirector(const Director& director) {
    if (numDirectores == capacidadDirectores) {
        redimensionarDirectores(capacidadDirectores * 2);
    }
    directores[numDirectores] = director;
    numDirectores++;
    return true;
}

bool Database::eliminarDirector(int id) {
    int indice = buscarIndiceDirectorPorId(id);
    if (indice == -1) return false;

    for (int i = indice; i < numDirectores - 1; ++i) {
        directores[i] = directores[i + 1];
    }
    numDirectores--;
    return true;
}

Director* Database::buscarDirectorPorId(int id) {
    int indice = buscarIndiceDirectorPorId(id);
    if (indice == -1) return nullptr;
    return &directores[indice];
}

Director* Database::buscarDirectoresPorNombre(const MyString& nombre, int& numResultados) {
    numResultados = 0;
    if (nombre.obtenerLongitud() == 0) return nullptr;

    for (int i = 0; i < numDirectores; ++i) {
        if (textoContiene(directores[i].obtenerNombre(), nombre) ||
            textoContiene(directores[i].obtenerApellido(), nombre)) {
            numResultados++;
        }
    }

    if (numResultados == 0) return nullptr;

    Director* resultados = new Director[numResultados];
    int indiceResultado = 0;

    for (int i = 0; i < numDirectores; ++i) {
        if (textoContiene(directores[i].obtenerNombre(), nombre) ||
            textoContiene(directores[i].obtenerApellido(), nombre)) {
            resultados[indiceResultado] = directores[i];
            indiceResultado++;
        }
    }

    return resultados;
}

int Database::obtenerNumDirectores() const {
    return numDirectores;
}

const Director* Database::obtenerDirectores() const {
    return directores;
}