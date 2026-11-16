/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef USUARIO_H
#define USUARIO_H
using namespace std;

#include <iostream>
#include <string>
#include "StackList.h"

class Usuario {
private:
    int id;
    string nombre;
    //Estructura de datos dinamica StackList (pila sobre lista ligada) para
    //guardar el historial de peliculas calificadas. Crece segun se necesite.
    StackList<int> peliculasCalificadas;

public:
    //Constructor por defecto
    // Mejor, promedio y peor caso: O(1)  (la pila empieza vacia)
    // Espacio: O(1)
    Usuario() // O(1)
        : id(0), nombre("") {}

    //Constructor
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Usuario(int id, string nombre) // O(1)
        : id(id), nombre(nombre) {}

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getId() const { // O(1)
        return id; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    string getNombre() const { // O(1)
        return nombre; // O(1)
    }

    // Uso de la funcion push de StackList.
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)  (un nodo nuevo)
    void registrarCalificacion(int idPelicula) { // O(1)
        peliculasCalificadas.push(idPelicula); // O(1)
    }

    // Regresa una copia de la pila para consultarla sin modificar
    // la original.
    // Mejor, promedio y peor caso: O(n). Espacio: O(n)
    StackList<int> getPeliculasCalificadas() const { // O(n)
        return peliculasCalificadas; // O(n), copia todos los nodos
    }

    //Funcion para contar los elementos de la pila.
    // Se cuentan las calificaciones sacando todo de una copia de la pila
    // Mejor, promedio y peor caso: O(n). Espacio: O(n)
    int numeroPeliculasCalificadas() const { // O(n)
        StackList<int> copiaPeliculasCalificadas = peliculasCalificadas; // O(n)
        int total = 0; // O(1)

        while (!copiaPeliculasCalificadas.empty()) { // O(n)
            total++; // O(1)
            copiaPeliculasCalificadas.pop(); // O(1)
        }
        return total; // O(1)
    }

    // Mejor, promedio y peor caso: O(n)  (por numeroPeliculasCalificadas)
    // Espacio: O(n)
    void mostrarInformacion() const { // O(n)
        cout << "ID: " << id << endl; // O(1)
        cout << "Usuario: " << nombre << endl; // O(1)
        cout << "Peliculas calificadas: " // O(n)
             << numeroPeliculasCalificadas() << endl;
    }
};
#endif
