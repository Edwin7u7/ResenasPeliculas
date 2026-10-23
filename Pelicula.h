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
    Pelicula()
        : id(0), titulo(""), categoria(), anio(0),
          calificacionPromedio(0.0), numeroCalificaciones(0),
          numeroResenas(0) {}

    //Constructor
    Pelicula(int id, string titulo, Categoria categoria,
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
    int getId() const {
        return id;
    }

    string getTitulo() const {
        return titulo;
    }

    string getCategoria() const {
        return categoria.getNombre();
    }

    int getAnio() const {
        return anio;
    }

    double getCalificacion() const {
        return calificacionPromedio;
    }

    int getNumeroResenas() const {
        return numeroResenas;
    }

    void agregarCalificacion(int calificacion) {

        double sumaActual =
            calificacionPromedio * numeroCalificaciones;

        numeroCalificaciones++;

        calificacionPromedio =
            (sumaActual + calificacion) /
            numeroCalificaciones;
    }

    void agregarResena() {
        numeroResenas++;
    }

    void mostrar() const {
        cout << "ID: " << id << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Categoria: " << categoria.getNombre() << endl;
        cout << "Anio: " << anio << endl;
        cout << "Calificacion: "
             << calificacionPromedio << "/5" << endl;
        cout << "Calificaciones: "
             << numeroCalificaciones << endl;
        cout << "Resenas: "
             << numeroResenas << endl;
    }
};

#endif