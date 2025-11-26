#include "Menu.hpp"
using namespace std;

Menu::Menu(Database* database) : db(database) {
    usuarioActual[0] = '\0';  
    sesionActiva = false;
}

bool Menu::compararTexto(const char* texto1, const char* texto2) {
    int i = 0;
    while (texto1[i] != '\0' && texto2[i] != '\0') {
        if (texto1[i] != texto2[i]) {
            return false;  
        }
        i++;
    }
  
    return texto1[i] == texto2[i];
}

void Menu::copiarTexto(char* destino, const char* origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';  
}


void Menu::iniciar() {
    while (true) {  
        if (hacerLogin()) {  
            sesionActiva = true;

            while (sesionActiva) {  
                mostrarMenuYEjecutar();
            }
        }
    }
}

bool Menu::hacerLogin() {
    display.limpiarPantalla();
    display.mostrarBienvenida();

    char usuario[50];
    char password[50];

    input.leerTexto("Usuario: ", usuario, 50);
    input.leerTexto("Contrasena: ", password, 50);

    
    if (compararTexto(usuario, "admin") && compararTexto(password, "1234")) {
        copiarTexto(usuarioActual, usuario);
        display.mostrarMensaje("Login exitoso!");
        display.pausar();
        return true;
    } else {
        display.mostrarError("Usuario o contrasena incorrectos");
        display.pausar();
        return false;
    }
}

void Menu::mostrarMenuYEjecutar() {
    display.limpiarPantalla();
    cout << "Usuario actual: " << usuarioActual << "\n\n";
    display.mostrarMenuPrincipal();
    int opcion = input.leerOpcion("Elige una opcion (1-5): ", 1, 5);
    ejecutarOpcion(opcion);
}

void Menu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            mostrarSeccionPeliculas();
            break;
        case 2:
            mostrarFavoritos();
            break;
        case 3:
            buscarPorTitulo();
            break;
        case 4:
            filtrarPorGenero();
            break;
        case 5:
            cerrarSesion();
            break;
    }
}

void Menu::mostrarSeccionPeliculas() {
    display.limpiarPantalla();
    display.mostrarMensaje("SECCION PELICULAS ");
    display.mostrarMensaje("");

    int numPeliculas = db->obtenerNumPeliculas();

    if (numPeliculas == 0) {
        cout << "No hay peliculas registradas.\n\n";
    } else {
        const Movie* peliculas = db->obtenerPeliculas();
        for (int i = 0; i < numPeliculas; ++i) {
            cout << "Pelicula " << (i + 1) << ": " 
                 << peliculas[i].obtenerTitulo().obtenerTexto() 
                 << " (ID: " << peliculas[i].obtenerId() << ")\n";
        }
        cout << "\n";
    }

    display.pausar();
}

void Menu::mostrarFavoritos() {
    display.limpiarPantalla();
    display.mostrarMensaje("FAVORITOS ");
    cout << "Aun no tienes favoritos registrados.\n\n";
    display.pausar();
}

void Menu::buscarPorTitulo() {
    display.limpiarPantalla();
    display.mostrarMensaje(" BUSCAR POR TITULO ");

    char titulo[50];
    input.leerTexto("Ingresa el titulo a buscar: ", titulo, 50);

    MyString tituloBuscar(titulo);
    int numResultados = 0;
    Movie* resultados = db->buscarPorTitulo(tituloBuscar, numResultados);

    cout << "\nBuscando coincidencias para: " << titulo << "\n";

    if (numResultados == 0) {
        cout << "No se encontraron peliculas con ese titulo.\n";
    } else {
        cout << "Se encontraron " << numResultados << " pelicula(s):\n";
        for (int i = 0; i < numResultados; ++i) {
            cout << "- " << resultados[i].obtenerTitulo().obtenerTexto() 
                 << " (ID: " << resultados[i].obtenerId() << ")\n";
        }
    }

    if (resultados != nullptr) {
        delete[] resultados;
    }

    cout << "\n";
    display.pausar();
}

void Menu::filtrarPorGenero() {
    display.limpiarPantalla();
    display.mostrarMensaje(" FILTRAR POR GENERO ");

    char genero[20];
    input.leerTexto("Genero: ", genero, 20);

    MyString generoBuscar(genero);
    int numResultados = 0;
    Movie* resultados = db->filtrarPorGenero(generoBuscar, numResultados);

    cout << "\nMostrando peliculas del genero '" << genero << "'\n";

    if (numResultados == 0) {
        cout << "No se encontraron peliculas de ese genero.\n";
    } else {
        cout << "Se encontraron " << numResultados << " pelicula(s):\n";
        for (int i = 0; i < numResultados; ++i) {
            cout << "- " << resultados[i].obtenerTitulo().obtenerTexto() 
                 << " (ID: " << resultados[i].obtenerId() << ")\n";
        }
    }

    if (resultados != nullptr) {
        delete[] resultados;
    }

    cout << "\n";
    display.pausar();
}

void Menu::cerrarSesion() {
    display.mostrarMensaje("Cerrando sesion...");
    sesionActiva = false;
    usuarioActual[0] = '\0'; 
}
