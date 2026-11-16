/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>
#include "Categoria.h"
using namespace std;

class Pelicula {
private:
    int id;
    string titulo;
    Categoria categoria;
    int anio;
    double calificacionPromedio;
    int numeroCalificaciones;
    int numeroResenas;

public:
    //Constructor por defecto
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Pelicula() // O(1)
        : id(0), titulo(""), categoria(), anio(0),
          calificacionPromedio(0.0), numeroCalificaciones(0),
          numeroResenas(0) {}

    //Constructor
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Pelicula(int id, string titulo, Categoria categoria, // O(1)
             int anio, double calificacionPromedio = 0.0,
             int numeroCalificaciones = 0,
             int numeroResenas = 0)
        : id(id),
          titulo(titulo),
          categoria(categoria),
          anio(anio),
          calificacionPromedio(calificacionPromedio),
          numeroCalificaciones(numeroCalificaciones),
          numeroResenas(numeroResenas) {}

    //Getters y Setters
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getId() const { // O(1)
        return id; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    string getTitulo() const { // O(1)
        return titulo; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    string getCategoria() const { // O(1)
        return categoria.getNombre(); // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getAnio() const { // O(1)
        return anio; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    double getCalificacion() const { // O(1)
        return calificacionPromedio; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getNumeroResenas() const { // O(1)
        return numeroResenas; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getNumeroCalificaciones() const { // O(1)
        return numeroCalificaciones; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getIdCategoria() const { // O(1)
        return categoria.getId(); // O(1)
    }

    // Actualiza el promedio sin recorrer calificaciones anteriores:
    // se recupera la suma con promedio * cantidad.
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    void agregarCalificacion(int calificacion) { // O(1)

        double sumaActual = // O(1)
            calificacionPromedio * numeroCalificaciones;

        numeroCalificaciones++; // O(1)

        calificacionPromedio = // O(1)
            (sumaActual + calificacion) /
            numeroCalificaciones;
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    void agregarResena() { // O(1)
        numeroResenas++; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    void mostrar() const { // O(1)
        cout << "ID: " << id << endl; // O(1)
        cout << "Titulo: " << titulo << endl; // O(1)
        cout << "Categoria: " << categoria.getNombre() << endl; // O(1)
        cout << "Anio: " << anio << endl; // O(1)
        cout << "Calificacion: " // O(1)
             << calificacionPromedio << "/5" << endl;
        cout << "Calificaciones: " // O(1)
             << numeroCalificaciones << endl;
        cout << "Resenas: " // O(1)
             << numeroResenas << endl;
    }
};

#endif