#include "InputHelper.hpp"
using namespace std;

void InputHelper::leerTexto(const char* mensaje, char* buffer, int maxSize) {
    cout << mensaje;
    cin.getline(buffer, maxSize);
}

int InputHelper::leerOpcion(const char* mensaje, int min, int max) {
    int opcion;
    while (true) {
        cout << mensaje;
        cin >> opcion;
        if (opcion >= min && opcion <= max) {
            return opcion;
        }
        cout << "Opción inválida. Debe ser entre " << min << " y " << max << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}