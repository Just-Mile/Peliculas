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
    m1.asignarFechaEstreno(1999);
    m1.asignarDuracionMinutos(136);
    m1.asignarEstudio(MyString("Warner Bros"));
    m1.asignarClasificacion(MyString("R"));
    m1.asignarPaisOrigen(MyString("USA"));
    m1.asignarCalificacionIMDB(8.7);
    m1.asignarCalificacionRottenTomatoes(88.0);
    m1.asignarCalificacionMetascore(73.0);
    m1.agregarGenero(MyString("Accion"));
    m1.agregarGenero(MyString("Ciencia Ficcion"));
    m1.agregarDirector(MyString("Lana Wachowski"));
    m1.agregarIdioma(MyString("Ingles"));
    m1.agregarIdioma(MyString("Espanol"));
    m1.agregarPremio(MyString("Oscar Mejores Efectos Visuales"));
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
    db.agregarPelicula(m2);

    
    Movie m3;
    m3.asignarId(3);
    m3.asignarTitulo(MyString("Toy Story"));
    m3.asignarCalificacionMetascore(95.0);
    m3.agregarGenero(MyString("Animacion"));
    m3.agregarGenero(MyString("Familia"));
    m3.agregarDirector(MyString("John Lasseter"));
    m3.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m3);

    
    Movie m4;
    m4.asignarId(4);
    m4.asignarTitulo(MyString("Inception"));
    m4.asignarCalificacionMetascore(74.0);
    m4.agregarGenero(MyString("Accion"));
    m4.agregarGenero(MyString("Thriller"));
    m4.agregarDirector(MyString("Christopher Nolan"));
    m4.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m4);

    
    Movie m5;
    m5.asignarId(5);
    m5.asignarTitulo(MyString("The Dark Knight"));
    m5.asignarCalificacionMetascore(84.0);
    m5.agregarGenero(MyString("Accion"));
    m5.agregarGenero(MyString("Drama"));
    m5.agregarDirector(MyString("Christopher Nolan"));
    m5.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m5);

    
    Movie m6;
    m6.asignarId(6);
    m6.asignarTitulo(MyString("Pulp Fiction"));
    m6.asignarCalificacionMetascore(94.0);
    m6.agregarGenero(MyString("Drama"));
    m6.agregarGenero(MyString("Crimen"));
    m6.agregarDirector(MyString("Quentin Tarantino"));
    m6.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m6);

    
    Movie m7;
    m7.asignarId(7);
    m7.asignarTitulo(MyString("Forrest Gump"));
    m7.asignarCalificacionMetascore(82.0);
    m7.agregarGenero(MyString("Drama"));
    m7.agregarGenero(MyString("Romance"));
    m7.agregarDirector(MyString("Robert Zemeckis"));
    m7.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m7);

    
    Movie m8;
    m8.asignarId(8);
    m8.asignarTitulo(MyString("Interstellar"));
    m8.asignarCalificacionMetascore(74.0);
    m8.agregarGenero(MyString("Ciencia Ficcion"));
    m8.agregarGenero(MyString("Aventura"));
    m8.agregarDirector(MyString("Christopher Nolan"));
    m8.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m8);

    
    Movie m9;
    m9.asignarId(9);
    m9.asignarTitulo(MyString("Parasite"));
    m9.asignarCalificacionMetascore(96.0);
    m9.agregarGenero(MyString("Drama"));
    m9.agregarGenero(MyString("Thriller"));
    m9.agregarDirector(MyString("Bong Joon-ho"));
    m9.agregarIdioma(MyString("Coreano"));
    db.agregarPelicula(m9);


    Movie m10;
    m10.asignarId(10);
    m10.asignarTitulo(MyString("The Godfather"));
    m10.asignarCalificacionMetascore(100.0);
    m10.agregarGenero(MyString("Drama"));
    m10.agregarGenero(MyString("Crimen"));
    m10.agregarDirector(MyString("Francis Ford Coppola"));
    m10.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m10);

    
    Movie m11;
    m11.asignarId(11);
    m11.asignarTitulo(MyString("Titanic"));
    m11.asignarCalificacionMetascore(75.0);
    m11.agregarGenero(MyString("Romance"));
    m11.agregarGenero(MyString("Drama"));
    m11.agregarDirector(MyString("James Cameron"));
    m11.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m11);

    
    Movie m12;
    m12.asignarId(12);
    m12.asignarTitulo(MyString("Avatar"));
    m12.asignarCalificacionMetascore(83.0);
    m12.agregarGenero(MyString("Ciencia Ficcion"));
    m12.agregarGenero(MyString("Aventura"));
    m12.agregarDirector(MyString("James Cameron"));
    m12.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m12);

    
    Movie m13;
    m13.asignarId(13);
    m13.asignarTitulo(MyString("Jurassic Park"));
    m13.asignarCalificacionMetascore(68.0);
    m13.agregarGenero(MyString("Aventura"));
    m13.agregarGenero(MyString("Ciencia Ficcion"));
    m13.agregarDirector(MyString("Steven Spielberg"));
    m13.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m13);

    
    Movie m14;
    m14.asignarId(14);
    m14.asignarTitulo(MyString("Star Wars"));
    m14.asignarCalificacionMetascore(90.0);
    m14.agregarGenero(MyString("Ciencia Ficcion"));
    m14.agregarGenero(MyString("Aventura"));
    m14.agregarDirector(MyString("George Lucas"));
    m14.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m14);

    
    Movie m15;
    m15.asignarId(15);
    m15.asignarTitulo(MyString("Gladiator"));
    m15.asignarCalificacionMetascore(67.0);
    m15.agregarGenero(MyString("Accion"));
    m15.agregarGenero(MyString("Drama"));
    m15.agregarDirector(MyString("Ridley Scott"));
    m15.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m15);

    
    Movie m16;
    m16.asignarId(16);
    m16.asignarTitulo(MyString("Shrek"));
    m16.asignarCalificacionMetascore(84.0);
    m16.agregarGenero(MyString("Animacion"));
    m16.agregarGenero(MyString("Comedia"));
    m16.agregarGenero(MyString("Familia"));
    m16.agregarDirector(MyString("Andrew Adamson"));
    m16.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m16);

    
    Movie m17;
    m17.asignarId(17);
    m17.asignarTitulo(MyString("Finding Nemo"));
    m17.asignarCalificacionMetascore(90.0);
    m17.agregarGenero(MyString("Animacion"));
    m17.agregarGenero(MyString("Familia"));
    m17.agregarDirector(MyString("Andrew Stanton"));
    m17.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m17);

   
    Movie m18;
    m18.asignarId(18);
    m18.asignarTitulo(MyString("The Lion King"));
    m18.asignarCalificacionMetascore(88.0);
    m18.agregarGenero(MyString("Animacion"));
    m18.agregarGenero(MyString("Familia"));
    m18.agregarGenero(MyString("Drama"));
    m18.agregarDirector(MyString("Roger Allers"));
    m18.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m18);

   
    Movie m19;
    m19.asignarId(19);
    m19.asignarTitulo(MyString("Avengers Endgame"));
    m19.asignarCalificacionMetascore(78.0);
    m19.agregarGenero(MyString("Accion"));
    m19.agregarGenero(MyString("Aventura"));
    m19.agregarDirector(MyString("Russo Brothers"));
    m19.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m19);

    
    Movie m20;
    m20.asignarId(20);
    m20.asignarTitulo(MyString("Spider-Man No Way Home"));
    m20.asignarCalificacionMetascore(71.0);
    m20.agregarGenero(MyString("Accion"));
    m20.agregarGenero(MyString("Aventura"));
    m20.agregarDirector(MyString("Jon Watts"));
    m20.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m20);

    
    Movie m21;
    m21.asignarId(21);
    m21.asignarTitulo(MyString("Coco"));
    m21.asignarCalificacionMetascore(81.0);
    m21.agregarGenero(MyString("Animacion"));
    m21.agregarGenero(MyString("Familia"));
    m21.agregarDirector(MyString("Lee Unkrich"));
    m21.agregarIdioma(MyString("Espanol"));
    m21.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m21);

    
    Movie m22;
    m22.asignarId(22);
    m22.asignarTitulo(MyString("The Shawshank Redemption"));
    m22.asignarCalificacionMetascore(80.0);
    m22.agregarGenero(MyString("Drama"));
    m22.agregarDirector(MyString("Frank Darabont"));
    m22.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m22);

   
    Movie m23;
    m23.asignarId(23);
    m23.asignarTitulo(MyString("Fight Club"));
    m23.asignarCalificacionMetascore(66.0);
    m23.agregarGenero(MyString("Drama"));
    m23.agregarGenero(MyString("Thriller"));
    m23.agregarDirector(MyString("David Fincher"));
    m23.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m23);

    
    Movie m24;
    m24.asignarId(24);
    m24.asignarTitulo(MyString("The Silence of the Lambs"));
    m24.asignarCalificacionMetascore(85.0);
    m24.agregarGenero(MyString("Thriller"));
    m24.agregarGenero(MyString("Crimen"));
    m24.agregarDirector(MyString("Jonathan Demme"));
    m24.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m24);

    
    Movie m25;
    m25.asignarId(25);
    m25.asignarTitulo(MyString("Joker"));
    m25.asignarCalificacionMetascore(59.0);
    m25.agregarGenero(MyString("Drama"));
    m25.agregarGenero(MyString("Thriller"));
    m25.agregarDirector(MyString("Todd Phillips"));
    m25.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m25);

   
    Movie m26;
    m26.asignarId(26);
    m26.asignarTitulo(MyString("Back to the Future"));
    m26.asignarCalificacionMetascore(87.0);
    m26.agregarGenero(MyString("Ciencia Ficcion"));
    m26.agregarGenero(MyString("Comedia"));
    m26.agregarDirector(MyString("Robert Zemeckis"));
    m26.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m26);

   
    Movie m27;
    m27.asignarId(27);
    m27.asignarTitulo(MyString("The Matrix Reloaded"));
    m27.asignarCalificacionMetascore(62.0);
    m27.agregarGenero(MyString("Accion"));
    m27.agregarGenero(MyString("Ciencia Ficcion"));
    m27.agregarDirector(MyString("Lana Wachowski"));
    m27.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m27);

 
    Movie m28;
    m28.asignarId(28);
    m28.asignarTitulo(MyString("Frozen"));
    m28.asignarCalificacionMetascore(74.0);
    m28.agregarGenero(MyString("Animacion"));
    m28.agregarGenero(MyString("Familia"));
    m28.agregarDirector(MyString("Chris Buck"));
    m28.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m28);


    Movie m29;
    m29.asignarId(29);
    m29.asignarTitulo(MyString("Up"));
    m29.asignarCalificacionMetascore(88.0);
    m29.agregarGenero(MyString("Animacion"));
    m29.agregarGenero(MyString("Familia"));
    m29.agregarDirector(MyString("Pete Docter"));
    m29.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m29);

 
    Movie m30;
    m30.asignarId(30);
    m30.asignarTitulo(MyString("Harry Potter"));
    m30.asignarCalificacionMetascore(64.0);
    m30.agregarGenero(MyString("Fantasia"));
    m30.agregarGenero(MyString("Aventura"));
    m30.agregarDirector(MyString("Chris Columbus"));
    m30.agregarIdioma(MyString("Ingles"));
    db.agregarPelicula(m30);

    
    Actor actor1(1, MyString("Leonardo"), MyString("DiCaprio"), MyString("Protagonista"));
    actor1.agregarPremio(MyString("Oscar Mejor Actor"));
    actor1.agregarPremio(MyString("Globo de Oro"));
    db.agregarActor(actor1);

    Actor actor2(2, MyString("Keanu"), MyString("Reeves"), MyString("Protagonista"));
    actor2.agregarPremio(MyString("MTV Movie Award"));
    db.agregarActor(actor2);

    Actor actor3(3, MyString("Elijah"), MyString("Wood"), MyString("Protagonista"));
    actor3.agregarPremio(MyString("SAG Award"));
    db.agregarActor(actor3);

    Actor actor4(4, MyString("Tom"), MyString("Hanks"), MyString("Voz"));
    actor4.agregarPremio(MyString("Oscar Mejor Actor"));
    db.agregarActor(actor4);

    Actor actor5(5, MyString("Christian"), MyString("Bale"), MyString("Protagonista"));
    actor5.agregarPremio(MyString("Oscar Mejor Actor Reparto"));
    db.agregarActor(actor5);

   
    Director dir1(1, MyString("Christopher"), MyString("Nolan"), MyString("Thriller Psicologico"));
    dir1.agregarPremio(MyString("BAFTA Mejor Director"));
    dir1.agregarPremio(MyString("Oscar Mejor Director"));
    db.agregarDirector(dir1);

    Director dir2(2, MyString("Peter"), MyString("Jackson"), MyString("Fantasia Epica"));
    dir2.agregarPremio(MyString("Oscar Mejor Director"));
    dir2.agregarPremio(MyString("BAFTA Mejor Director"));
    db.agregarDirector(dir2);

    Director dir3(3, MyString("Lana"), MyString("Wachowski"), MyString("Ciencia Ficcion"));
    dir3.agregarPremio(MyString("Saturn Award"));
    db.agregarDirector(dir3);

    Director dir4(4, MyString("John"), MyString("Lasseter"), MyString("Animacion"));
    dir4.agregarPremio(MyString("Oscar Mejor Pelicula Animada"));
    db.agregarDirector(dir4);


    
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
