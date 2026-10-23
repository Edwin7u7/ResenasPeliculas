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
    Categoria() : id(0), nombre("") {}

    //Constructor
    Categoria(int id, string nombre)
        : id(id), nombre(nombre) {}

    //Getters
    int getId() const {
        return id;
    }

    string getNombre() const {
        return nombre;
    }
    
};

#endif