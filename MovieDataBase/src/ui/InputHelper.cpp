#include "InputHelper.hpp"
using namespace std;

void InputHelper::leerTexto(const char* mensaje, char* buffer, int maxSize) {
    cout << mensaje;
    cin.getline(buffer, maxSize);

  
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        buffer[0] = '\0';
    }
}

int InputHelper::leerOpcion(const char* mensaje, int min, int max) {
    int opcion;
    while (true) {
        cout << mensaje;

        if (cin >> opcion) {
            cin.ignore(10000, '\n'); 

            if (opcion >= min && opcion <= max) {
                return opcion;
            }
            cout << "Opcion invalida. Debe ser entre " << min << " y " << max << endl;
        } else {
            cout << "Entrada invalida. Debes ingresar un numero." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
