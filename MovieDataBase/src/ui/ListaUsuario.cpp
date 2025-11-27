#include "ListaUsuario.hpp"

const int CAPACIDAD_INICIAL_LISTA_USUARIOS = 10;

ListaUsuario::ListaUsuario() 
    : usuarios(nullptr), numUsuarios(0), capacidadUsuarios(0) {
    usuarios = new Usuario*[CAPACIDAD_INICIAL_LISTA_USUARIOS];
    capacidadUsuarios = CAPACIDAD_INICIAL_LISTA_USUARIOS;
}

ListaUsuario::~ListaUsuario() {
    if (usuarios != nullptr) {
        delete[] usuarios;
    }
}

ListaUsuario::ListaUsuario(const ListaUsuario& otro)
    : numUsuarios(otro.numUsuarios), 
      capacidadUsuarios(otro.capacidadUsuarios) {

    usuarios = new Usuario*[capacidadUsuarios];
    for (int i = 0; i < numUsuarios; ++i) {
        usuarios[i] = otro.usuarios[i];
    }
}

ListaUsuario& ListaUsuario::operator=(const ListaUsuario& otro) {
    if (this == &otro) return *this;

    if (usuarios != nullptr) delete[] usuarios;

    numUsuarios = otro.numUsuarios;
    capacidadUsuarios = otro.capacidadUsuarios;
    usuarios = new Usuario*[capacidadUsuarios];

    for (int i = 0; i < numUsuarios; ++i) {
        usuarios[i] = otro.usuarios[i];
    }

    return *this;
}

void ListaUsuario::redimensionar(int nuevaCapacidad) {
    Usuario** nuevoArray = new Usuario*[nuevaCapacidad];
    for (int i = 0; i < numUsuarios; ++i) {
        nuevoArray[i] = usuarios[i];
    }
    delete[] usuarios;
    usuarios = nuevoArray;
    capacidadUsuarios = nuevaCapacidad;
}

void ListaUsuario::agregar(Usuario* usuario) {
    if (numUsuarios == capacidadUsuarios) {
        redimensionar(capacidadUsuarios * 2);
    }
    usuarios[numUsuarios] = usuario;
    numUsuarios++;
}

void ListaUsuario::remover(int indice) {
    if (indice < 0 || indice >= numUsuarios) return;

    for (int i = indice; i < numUsuarios - 1; ++i) {
        usuarios[i] = usuarios[i + 1];
    }
    numUsuarios--;
}

void ListaUsuario::removerPorId(int id) {
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i]->obtenerId() == id) {
            remover(i);
            break;
        }
    }
}

Usuario* ListaUsuario::obtenerEnIndice(int indice) {
    if (indice < 0 || indice >= numUsuarios) return nullptr;
    return usuarios[indice];
}

const Usuario* ListaUsuario::obtenerEnIndice(int indice) const {
    if (indice < 0 || indice >= numUsuarios) return nullptr;
    return usuarios[indice];
}

int ListaUsuario::obtenerTamanio() const {
    return numUsuarios;
}

void ListaUsuario::limpiar() {
    numUsuarios = 0;
}

bool ListaUsuario::estaVacia() const {
    return numUsuarios == 0;
}

Usuario* ListaUsuario::buscarPorNombre(const MyString& nombre) {
    for (int i = 0; i < numUsuarios; ++i) {
        const char* nombreUsuario = usuarios[i]->obtenerNombreUsuario().obtenerTexto();
        const char* buscar = nombre.obtenerTexto();

        bool coincide = true;
        int j = 0;
        while (nombreUsuario[j] != '\0' && buscar[j] != '\0') {
            char c1 = nombreUsuario[j];
            char c2 = buscar[j];

            if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32;
            if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32;

            if (c1 != c2) {
                coincide = false;
                break;
            }
            j++;
        }

        if (coincide && nombreUsuario[j] == '\0' && buscar[j] == '\0') {
            return usuarios[i];
        }
    }
    return nullptr;
}

Usuario** ListaUsuario::obtenerArray() {
    return usuarios;
}

const Usuario** ListaUsuario::obtenerArray() const {
    return const_cast<const Usuario**>(usuarios);
}