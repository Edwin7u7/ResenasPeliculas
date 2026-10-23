/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef USUARIO_H
#define USUARIO_H
using namespace std;

#include <iostream>
#include <string>
#include "StackVector.h"

// Capacidad maxima de calificaciones por usuario
const unsigned int MAX_CALIFICACIONES = 100;

class Usuario {
private:
    int id;
    string nombre;
    //Estructura de datos StackVector para guardar las calificaciones de las peliculas
    StackVector<int> peliculasCalificadas;

public:
    //Constructor por defecto
    Usuario()
        : id(0), nombre(""),
          peliculasCalificadas(MAX_CALIFICACIONES) {}

    //Constructor
    Usuario(int id, string nombre)
        : id(id), nombre(nombre),
          peliculasCalificadas(MAX_CALIFICACIONES) {}

    int getId() const {
        return id;
    }

    string getNombre() const {
        return nombre;
    }

    // Uso de la funcion push de stackVector: Tiempo O(1).
    void registrarCalificacion(int idPelicula) {
        peliculasCalificadas.push(idPelicula);
    }
    // Regresa una copia de la pila para consultarla sin modificar
    // la original. Tiempo O(c), Espacio O(c).
    StackVector<int> getPeliculasCalificadas() const {
        return peliculasCalificadas;
    }

    //Funcion para contar los elementos de la pila.
    // Se cuentan las calificaciones sacando todo de una copia de la pila
    // Tiempo O(k) (k = calificaciones), Espacio O(MAX_CALIFICACIONES).
    int numeroPeliculasCalificadas() const {
        StackVector<int> copiaPeliculasCalificadas = peliculasCalificadas;
        int total = 0;

        while (!copiaPeliculasCalificadas.empty()) {
            total++;
            copiaPeliculasCalificadas.pop();
        }
        return total;
    }

    void mostrarInformacion() const {
        cout << "ID: " << id << endl;
        cout << "Usuario: " << nombre << endl;
        cout << "Peliculas calificadas: "
             << numeroPeliculasCalificadas() << endl;
    }
};
#endif
