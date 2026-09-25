#include <iostream>
#include <string>
#include <vector>
#include <pelicula.h>
using namespace std;

// ==========================================
// CLASE USUARIO
// ==========================================
class Usuario {
private:
    int id;
    string nombre;

public:
    Usuario(int id, string nombre)
        : id(id), nombre(nombre) {}

    void calificarPelicula(Pelicula& pelicula, double calificacion) {
        pelicula.agregarCalificacion(calificacion);
    }

    string getNombre() {
        return nombre;
    }
};