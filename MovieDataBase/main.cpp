#include "Menu.hpp"
#include "Database.hpp"
#include "ListaPelicula.hpp"
#include "ListaUsuario.hpp"
#include "MyString.hpp"
#include <iostream>

using namespace std;

int main() {
    Database db;

  
    Movie m1;
    m1.asignarId(1);
    m1.asignarTitulo(MyString("Matrix"));
    m1.asignarCalificacionMetascore(73.0);
    m1.agregarGenero(MyString("Accion"));
    m1.agregarGenero(MyString("Ciencia Ficcion"));
    m1.agregarDirector(MyString("Lana Wachowski"));
    m1.agregarDirector(MyString("Lilly Wachowski"));
    m1.agregarIdioma(MyString("Ingles"));
    m1.agregarIdioma(MyString("Espanol"));
    db.agregarPelicula(m1);

    Movie m2;
    m2.asignarId(2);
    m2.asignarTitulo(MyString("El Senor de los Anillos"));
    m2.asignarCalificacionMetascore(92.0);
    m2.agregarGenero(MyString("Aventura"));
    m2.agregarGenero(MyString("Fantasia"));
    m2.agregarDirector(MyString("Peter Jackson"));
    m2.agregarIdioma(MyString("Ingles"));
    m2.agregarIdioma(MyString("Espanol"));
    m2.agregarIdioma(MyString("Frances"));
    db.agregarPelicula(m2);

    Movie m3;
    m3.asignarId(3);
    m3.asignarTitulo(MyString("Toy Story"));
    m3.asignarCalificacionMetascore(95.0);
    m3.agregarGenero(MyString("Animacion"));
    m3.agregarGenero(MyString("Familia"));
    m3.agregarDirector(MyString("John Lasseter"));
    m3.agregarIdioma(MyString("Ingles"));
    m3.agregarIdioma(MyString("Espanol"));
    db.agregarPelicula(m3);

    Movie m4;
    m4.asignarId(4);
    m4.asignarTitulo(MyString("Inception"));
    m4.asignarCalificacionMetascore(74.0);
    m4.agregarGenero(MyString("Accion"));
    m4.agregarGenero(MyString("Thriller"));
    m4.agregarDirector(MyString("Christopher Nolan"));
    m4.agregarIdioma(MyString("Ingles"));
    m4.agregarIdioma(MyString("Espanol"));
    m4.agregarIdioma(MyString("Japones"));
    db.agregarPelicula(m4);

    Movie m5;
    m5.asignarId(5);
    m5.asignarTitulo(MyString("The Dark Knight"));
    m5.asignarCalificacionMetascore(84.0);
    m5.agregarGenero(MyString("Accion"));
    m5.agregarGenero(MyString("Drama"));
    m5.agregarDirector(MyString("Christopher Nolan"));
    m5.agregarIdioma(MyString("Ingles"));
    m5.agregarIdioma(MyString("Espanol"));
    db.agregarPelicula(m5);

   
    Actor actor1(1, MyString("Leonardo"), MyString("DiCaprio"), MyString("Protagonista"));
    actor1.agregarPremio(MyString("Oscar"));
    db.agregarActor(actor1);

    Actor actor2(2, MyString("Keanu"), MyString("Reeves"), MyString("Protagonista"));
    db.agregarActor(actor2);

    Actor actor3(3, MyString("Elijah"), MyString("Wood"), MyString("Protagonista"));
    db.agregarActor(actor3);


    Director dir1(1, MyString("Christopher"), MyString("Nolan"), MyString("Thriller Psicologico"));
    dir1.agregarPremio(MyString("BAFTA"));
    db.agregarDirector(dir1);

    Director dir2(2, MyString("Peter"), MyString("Jackson"), MyString("Fantasia Epica"));
    dir2.agregarPremio(MyString("Oscar Mejor Director"));
    db.agregarDirector(dir2);

    Director dir3(3, MyString("Wachowski"), MyString("Sisters"), MyString("Ciencia Ficcion"));
    db.agregarDirector(dir3);

    
    Usuario user1(1, MyString("admin"), MyString("1234"));
    db.agregarUsuario(user1);

    Usuario user2(2, MyString("juan"), MyString("pass123"));
    db.agregarUsuario(user2);

    Usuario user3(3, MyString("maria"), MyString("maria456"));
    db.agregarUsuario(user3);


    Menu menu(&db);
    menu.iniciar();

    return 0;
}