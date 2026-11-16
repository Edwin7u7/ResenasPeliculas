/*
* A00842140 Edwin Arturo Salgado Santana
*/
#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
using namespace std;


class Categoria {
private:
    int id;
    string nombre;

public:
    //Constructor por defecto
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Categoria() : id(0), nombre("") {} // O(1)

    //Constructor
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Categoria(int id, string nombre) // O(1)
        : id(id), nombre(nombre) {}

    //Getters
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getId() const { // O(1)
        return id; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    string getNombre() const { // O(1)
        return nombre; // O(1)
    }

};

#endif