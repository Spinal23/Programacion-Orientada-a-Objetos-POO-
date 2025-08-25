// c++ Biblioteca POO. Tarea 1. Leandro Amaya
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Libro {
public:
    int anio;
    int pasillo;
    string titulo;
    string autor;
    bool estado = true;

    void mostrardetalles() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Ano: " << anio << endl;
        cout << "Pasillo: " << pasillo << endl;
        cout << "Estado: " << (estado ? "Disponible" : "No disponible") << endl;
    }
};

class Biblioteca {
private:
    vector<Libro> coleccion;

public:
    void agregarLibro() {
        Libro libro;
        cout << "Ingrese el titulo del libro: ";
        getline(cin, libro.titulo);
        cout << "Ingrese el nombre del autor: ";
        getline(cin, libro.autor);
        cout << "Ingrese el ano de publicacion: ";
        cin >> libro.anio;
        cout << "Ingrese el pasillo: ";
        cin >> libro.pasillo;
        libro.estado = true;
        coleccion.push_back(libro);
        cout << "Libro agregado exitosamente." << endl;
    }

    void mostrarInventario() {
        if (coleccion.empty()) {
            cout << "No hay libros en la biblioteca." << endl;
            return;
        }
        cout << "\n--- INVENTARIO DE LIBROS ---" << endl;
        for (Libro &libro : coleccion) {
            libro.mostrardetalles();
            cout << "-------------------------" << endl;
        }
    }

    bool prestarLibro(const string& titulo) {
        for (Libro &libro : coleccion) {
            if (libro.titulo == titulo && libro.estado) {
                libro.estado = false;
                return true;
            }
        }
        return false;
    }

    bool devolverLibro(const string& titulo) {
        for (Libro &libro : coleccion) {
            if (libro.titulo == titulo && !libro.estado) {
                libro.estado = true;
                return true;
            }
        }
        return false;
    }
};

int main() {
    Biblioteca miBiblioteca;
    int opcion = 0;

    while (opcion != 5) {
        cout << "\n--- BIBLIOTECA DIGITAL ---" << endl;
        cout << "1. Anadir libro" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Prestar libro" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer antes de getline

        if (opcion == 1) {
            miBiblioteca.agregarLibro();
        }
        else if (opcion == 2) {
            miBiblioteca.mostrarInventario();
        }
        else if (opcion == 3) {
            string titulo;
            cout << "Ingrese el titulo del libro a prestar: ";
            getline(cin, titulo);
            if (miBiblioteca.prestarLibro(titulo)) {
                cout << "Libro prestado exitosamente." << endl;
            } else {
                cout << "El libro no esta disponible." << endl;
            }
        }
        else if (opcion == 4) {
            string titulo;
            cout << "Ingrese el titulo del libro a devolver: ";
            getline(cin, titulo);
            if (miBiblioteca.devolverLibro(titulo)) {
                cout << "Libro devuelto exitosamente." << endl;
            } else {
                cout << "El libro no se encuentra en la biblioteca o ya esta disponible." << endl;
            }
        }
        else if (opcion == 5) {
            cout << "Saliendo del programa..." << endl;
        }
        else {
            cout << "Opcion invalida, intente de nuevo." << endl;
        }
    }

    return 0;
}
