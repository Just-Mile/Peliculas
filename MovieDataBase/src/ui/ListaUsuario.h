#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#include "Usuario.hpp"

class ListaUsuario {
private:
    Usuario** usuarios;
    int numUsuarios;
    int capacidadUsuarios;

    void redimensionar(int nuevaCapacidad);

public:
    ListaUsuario();
    ~ListaUsuario();
    ListaUsuario(const ListaUsuario& otro);
    ListaUsuario& operator=(const ListaUsuario& otro);

    void agregar(Usuario* usuario);
    void remover(int indice);
    void removerPorId(int id);
    Usuario* obtenerEnIndice(int indice);
    const Usuario* obtenerEnIndice(int indice) const;
    int obtenerTamanio() const;
    void limpiar();
    bool estaVacia() const;
    Usuario* buscarPorNombre(const MyString& nombre);
    Usuario** obtenerArray();
    const Usuario** obtenerArray() const;
};

#endif
