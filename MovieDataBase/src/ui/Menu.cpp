#include "Menu.hpp"
using namespace std;

Menu::Menu(Database* database) 
    : db(database), usuarioLogueado(nullptr) {
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

    cout << "========================================" << endl;
    cout << "         INICIO DE SESION              " << endl;
    cout << "========================================" << endl;
    cout << "\nUsuarios disponibles para prueba:" << endl;
    cout << "  - admin (contrasena: 1234)" << endl;
    cout << "  - juan (contrasena: pass123)" << endl;
    cout << "  - maria (contrasena: maria456)" << endl;
    cout << "========================================\n" << endl;

    char usuario[50];
    char password[50];

    input.leerTexto("Usuario: ", usuario, 50);
    input.leerTexto("Contrasena: ", password, 50);

    Usuario* usuarioEncontrado = db->buscarUsuarioPorNombre(MyString(usuario));

    if (usuarioEncontrado != nullptr) {
        if (compararTexto(usuarioEncontrado->obtenerContrasena().obtenerTexto(), password)) {
            copiarTexto(usuarioActual, usuario);
            usuarioLogueado = usuarioEncontrado;

            display.limpiarPantalla();
            cout << "\n========================================" << endl;
            cout << "   LOGIN EXITOSO!" << endl;
            cout << "========================================" << endl;
            cout << "\nBienvenido(a), " << usuarioActual << "!" << endl;
            cout << "\nPresiona ENTER para continuar al menu principal...";
            cin.get();

            return true;
        }
    }

    display.limpiarPantalla();
    cout << "\n========================================" << endl;
    cout << "   ERROR DE AUTENTICACION" << endl;
    cout << "========================================" << endl;
    cout << "\nUsuario o contrasena incorrectos." << endl;
    cout << "Por favor, verifica tus credenciales.\n" << endl;
    display.pausar();
    return false;
}

void Menu::mostrarMenuYEjecutar() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "   SISTEMA DE PELICULAS" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    display.mostrarMenuPrincipal();

    int opcion = input.leerOpcion("\nSelecciona una opcion (1-7): ", 1, 7);
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
            mostrarActores();
            break;
        case 6:
            mostrarDirectores();
            break;
        case 7:
            cerrarSesion();
            break;
    }
}

void Menu::mostrarDetallePelicula(Movie* pelicula) {
    if (pelicula == nullptr) return;

    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       DETALLES DE LA PELICULA" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    cout << "TITULO: " << pelicula->obtenerTitulo().obtenerTexto() << endl;
    cout << "ID: " << pelicula->obtenerId() << endl;
    cout << "CALIFICACION METASCORE: " << pelicula->obtenerCalificacionMetascore() << endl;

    const MyString* generos = pelicula->obtenerGeneros();
    int numGeneros = pelicula->obtenerNumGeneros();
    if (numGeneros > 0) {
        cout << "\nGENEROS:" << endl;
        for (int j = 0; j < numGeneros; ++j) {
            cout << "  - " << generos[j].obtenerTexto() << endl;
        }
    }

    const MyString* directores = pelicula->obtenerDirectores();
    int numDirectores = pelicula->obtenerNumDirectores();
    if (numDirectores > 0) {
        cout << "\nDIRECTORES:" << endl;
        for (int j = 0; j < numDirectores; ++j) {
            cout << "  - " << directores[j].obtenerTexto() << endl;
        }
    }

    const MyString* idiomas = pelicula->obtenerIdiomas();
    int numIdiomas = pelicula->obtenerNumIdiomas();
    if (numIdiomas > 0) {
        cout << "\nIDIOMAS DISPONIBLES:" << endl;
        for (int j = 0; j < numIdiomas; ++j) {
            cout << "  - " << idiomas[j].obtenerTexto() << endl;
        }
    }

    cout << "\n========================================" << endl;
    cout << "OPCIONES:" << endl;
    cout << "1. Agregar a favoritos" << endl;
    cout << "2. Volver al menu" << endl;
    cout << "========================================" << endl;

    int opcion = input.leerOpcion("\nSelecciona una opcion (1-2): ", 1, 2);

    if (opcion == 1) {
        if (usuarioLogueado->esFavorita(pelicula)) {
            cout << "\nEsta pelicula ya esta en tus favoritos." << endl;
        } else {
            usuarioLogueado->agregarAFavoritos(pelicula);
            cout << "\n¡Pelicula agregada a favoritos exitosamente!" << endl;
        }
        display.pausar();
    }
}

void Menu::mostrarSeccionPeliculas() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       CATALOGO DE PELICULAS" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    int numPeliculas = db->obtenerNumPeliculas();

    if (numPeliculas == 0) {
        cout << "No hay peliculas registradas en el sistema.\n" << endl;
        display.pausar();
        return;
    }

    cout << "Total de peliculas: " << numPeliculas << "\n" << endl;

    const Movie* peliculas = db->obtenerPeliculas();
    for (int i = 0; i < numPeliculas; ++i) {
        cout << "[" << (i + 1) << "] " << peliculas[i].obtenerTitulo().obtenerTexto();
        cout << " (Metascore: " << peliculas[i].obtenerCalificacionMetascore() << ")" << endl;
    }

    cout << "\n[0] Volver al menu principal" << endl;
    cout << "========================================" << endl;

    int opcion = input.leerOpcion("\nIngresa el numero de la pelicula (0 para salir): ", 0, numPeliculas);

    if (opcion > 0) {
        Movie* peliculaSeleccionada = db->buscarPeliculaPorId(peliculas[opcion - 1].obtenerId());
        mostrarDetallePelicula(peliculaSeleccionada);
    }
}

void Menu::mostrarFavoritos() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       MIS PELICULAS FAVORITAS" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    if (usuarioLogueado != nullptr) {
        int numFavoritas = usuarioLogueado->obtenerNumFavoritas();

        if (numFavoritas == 0) {
            cout << "Aun no tienes peliculas favoritas." << endl;
            cout << "\nPuedes agregar peliculas desde el catalogo" << endl;
            cout << "o desde los resultados de busqueda.\n" << endl;
        } else {
            cout << "Tienes " << numFavoritas << " pelicula(s) favorita(s):\n" << endl;
            usuarioLogueado->obtenerFavoritas();
            cout << endl;
        }
    } else {
        cout << "Error: No hay usuario logueado.\n" << endl;
    }

    display.pausar();
}

void Menu::buscarPorTitulo() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       BUSCAR PELICULA POR TITULO" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    cout << "Peliculas disponibles:" << endl;
    int total = db->obtenerNumPeliculas();
    const Movie* todasLasPeliculas = db->obtenerPeliculas();
    for (int i = 0; i < total; ++i) {
        cout << "  - " << todasLasPeliculas[i].obtenerTitulo().obtenerTexto() << endl;
    }
    cout << "========================================\n" << endl;

    char titulo[100];
    input.leerTexto("Ingresa el titulo (o parte): ", titulo, 100);

    MyString tituloBuscar(titulo);
    int numResultados = 0;
    Movie* resultados = db->buscarPeliculasPorTitulo(tituloBuscar, numResultados);

    cout << "\n========================================" << endl;
    cout << "  RESULTADOS" << endl;
    cout << "========================================" << endl;

    if (numResultados == 0) {
        cout << "No se encontraron peliculas.\n" << endl;

        if (resultados != nullptr) {
            delete[] resultados;
        }

        display.pausar();
        return;
    }

    cout << "Se encontraron " << numResultados << " pelicula(s):\n" << endl;

    for (int i = 0; i < numResultados; ++i) {
        cout << "[" << (i + 1) << "] " << resultados[i].obtenerTitulo().obtenerTexto();
        cout << " (Metascore: " << resultados[i].obtenerCalificacionMetascore() << ")" << endl;
    }

    cout << "\n[0] Volver" << endl;
    cout << "========================================" << endl;

    int opcion = input.leerOpcion("\nSelecciona (0 para salir): ", 0, numResultados);

    if (opcion > 0) {
        Movie* peliculaSeleccionada = db->buscarPeliculaPorId(resultados[opcion - 1].obtenerId());
        mostrarDetallePelicula(peliculaSeleccionada);
    }

    if (resultados != nullptr) {
        delete[] resultados;
    }
}

void Menu::filtrarPorGenero() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       FILTRAR POR GENERO" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    cout << "Generos: Accion, Drama, Animacion, Thriller, Aventura, Fantasia, Familia, Ciencia Ficcion\n" << endl;

    char genero[50];
    input.leerTexto("Ingresa el genero: ", genero, 50);

    MyString generoBuscar(genero);
    int numResultados = 0;
    Movie* resultados = db->filtrarPeliculasPorGenero(generoBuscar, numResultados);

    cout << "\n========================================" << endl;
    cout << "  RESULTADOS" << endl;
    cout << "========================================" << endl;

    if (numResultados == 0) {
        cout << "No se encontraron peliculas.\n" << endl;

        if (resultados != nullptr) {
            delete[] resultados;
        }

        display.pausar();
        return;
    }

    cout << "Se encontraron " << numResultados << " pelicula(s):\n" << endl;

    for (int i = 0; i < numResultados; ++i) {
        cout << "[" << (i + 1) << "] " << resultados[i].obtenerTitulo().obtenerTexto();
        cout << " (Metascore: " << resultados[i].obtenerCalificacionMetascore() << ")" << endl;
    }

    cout << "\n[0] Volver" << endl;
    cout << "========================================" << endl;

    int opcion = input.leerOpcion("\nSelecciona (0 para salir): ", 0, numResultados);

    if (opcion > 0) {
        Movie* peliculaSeleccionada = db->buscarPeliculaPorId(resultados[opcion - 1].obtenerId());
        mostrarDetallePelicula(peliculaSeleccionada);
    }

    if (resultados != nullptr) {
        delete[] resultados;
    }
}

void Menu::mostrarActores() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       LISTA DE ACTORES" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    int numActores = db->obtenerNumActores();

    if (numActores == 0) {
        cout << "No hay actores registrados.\n" << endl;
        display.pausar();
        return;
    }

    cout << "Total de actores: " << numActores << "\n" << endl;

    const Actor* actores = db->obtenerActores();
    for (int i = 0; i < numActores; ++i) {
        cout << "[" << (i + 1) << "] " 
             << actores[i].obtenerNombre().obtenerTexto() << " "
             << actores[i].obtenerApellido().obtenerTexto() 
             << " - " << actores[i].obtenerTipoActor().obtenerTexto() << endl;
    }

    cout << "\n[0] Volver" << endl;
    cout << "========================================" << endl;

    int opcion = input.leerOpcion("\nSelecciona (0 para salir): ", 0, numActores);

    if (opcion > 0) {
        display.limpiarPantalla();

     
        Actor* actorSeleccionado = db->buscarActorPorId(actores[opcion - 1].obtenerId());
        if (actorSeleccionado != nullptr) {
            actorSeleccionado->abrirPerfil();
        }

        display.pausar();
    }
}

void Menu::mostrarDirectores() {
    display.limpiarPantalla();

    cout << "========================================" << endl;
    cout << "       LISTA DE DIRECTORES" << endl;
    cout << "========================================" << endl;
    cout << "Usuario: " << usuarioActual << endl;
    cout << "========================================\n" << endl;

    int numDirectores = db->obtenerNumDirectores();

    if (numDirectores == 0) {
        cout << "No hay directores registrados.\n" << endl;
        display.pausar();
        return;
    }

    cout << "Total de directores: " << numDirectores << "\n" << endl;

    const Director* directores = db->obtenerDirectores();
    for (int i = 0; i < numDirectores; ++i) {
        cout << "[" << (i + 1) << "] " 
             << directores[i].obtenerNombre().obtenerTexto() << " "
             << directores[i].obtenerApellido().obtenerTexto() 
             << " - " << directores[i].obtenerEstiloDirector().obtenerTexto() << endl;
    }

    cout << "\n[0] Volver" << endl;
    cout << "========================================" << endl;

    int opcion = input.leerOpcion("\nSelecciona (0 para salir): ", 0, numDirectores);

    if (opcion > 0) {
        display.limpiarPantalla();

        
        Director* directorSeleccionado = db->buscarDirectorPorId(directores[opcion - 1].obtenerId());
        if (directorSeleccionado != nullptr) {
            directorSeleccionado->abrirPerfil();
        }

        display.pausar();
    }
}

void Menu::cerrarSesion() {
    display.limpiarPantalla();

    cout << "\n========================================" << endl;
    cout << "       CERRANDO SESION..." << endl;
    cout << "========================================" << endl;
    cout << "\nHasta pronto, " << usuarioActual << "!" << endl;
    cout << "\nGracias por usar el Sistema de Peliculas.\n" << endl;
    cout << "========================================\n" << endl;

    display.pausar();

    sesionActiva = false;
    usuarioActual[0] = '\0';
    usuarioLogueado = nullptr;
}
