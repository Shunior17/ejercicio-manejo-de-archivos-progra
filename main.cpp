#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void crearArchivo() {
    string nombreArchivo, contenido;
    cout << "Ingrese el directorio y nombre del archivo a crear: ";
    cin >> nombreArchivo;

    cout << "Ingrese el contenido del archivo:" << endl;
    cin.ignore();
    getline(cin, contenido);

    ofstream archivo(nombreArchivo);
    archivo<< contenido << endl;
    archivo.close();
}

void leerArchivo() {
    string nombreArchivo;
    cout << "Ingrese el directorio y nombre del archivo a leer: ";
    cin >> nombreArchivo;

    ifstream archivoEntrada(nombreArchivo);
    if (archivoEntrada.is_open()) {
        string linea;
        while (getline(archivoEntrada, linea)) {
            cout << linea << endl;
        }
        archivoEntrada.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}

void escribirArchivo() {
    string nombreArchivo, contenido;
    cout << "Ingrese el directorio y nombre del archivo en el que desea escribir: ";
    cin >> nombreArchivo;

    cout << "Ingrese el contenido a añadir al archivo:" << endl;
    cin.ignore();
    getline(cin, contenido);

    ofstream archivoEscritura(nombreArchivo, ios::app);
    if (archivoEscritura.is_open()) {
        archivoEscritura << contenido << endl;
        archivoEscritura.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

void eliminarArchivo() {
    string nombreArchivo;
    cout << "Ingrese el directorio y nombre del archivo a eliminar: ";
    cin >> nombreArchivo;

    if (remove(nombreArchivo.c_str()) != 0) {
        cout << "Error al intentar eliminar el archivo." << endl;
    } else {
        cout << "Archivo eliminado exitosamente." << endl;
    }
}


int main() {
    int opcion;
    cout << "Seleccione una opcion: \n"
            "1. Crear archivo\n"
            "2. Leer archivo\n"
            "3. Escribir en archivo\n"
            "4. Eliminar archivo\n"
            "Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            crearArchivo();
            break;
        case 2:
            leerArchivo();
            break;
        case 3:
            escribirArchivo();
            break;
        case 4:
            eliminarArchivo();
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
    return 0;
}