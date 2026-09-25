#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==========================================
// CLASE PELICULA
// ==========================================

class Pelicula {
private:
    int id;
    string titulo;
    string genero;
    string descripcion;
    int anio;
    double calificacionPromedio;

public:
    Pelicula(int id, string titulo, string genero, int anio)
        : id(id), titulo(titulo), genero(genero),
          anio(anio), calificacionPromedio(0.0) {}

    void mostrarInformacion() {
        cout << titulo << " (" << anio << ")" << endl;
        cout << "Genero: " << genero << endl;
        cout << "Calificacion: " << calificacionPromedio << endl;
    }

    void agregarCalificacion(double calificacion) {
        calificacionPromedio = calificacion;
    }

    string getTitulo() {
        return titulo;
    }

    string getDescripcion() {
        return descripcion;
    }

    double getCalificacion() {
        return calificacionPromedio;
    }
};