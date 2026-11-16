/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef RESENA_H
#define RESENA_H
using namespace std;

#include <iostream>
#include <string>

class Resena {
private:
    int id;
    string contenido;
    string nombreUsuario;
    int idPelicula;
    int calificacion;
    int likes;

public:
    //Constructor por defecto
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Resena() // O(1)
        : id(0), contenido(""), nombreUsuario(""),
          idPelicula(0), calificacion(0), likes(0) {}

    //Constructor
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    Resena(int id, string contenido, string nombreUsuario, // O(1)
           int idPelicula, int calificacion, int likes = 0)
        : id(id),
          contenido(contenido),
          nombreUsuario(nombreUsuario),
          idPelicula(idPelicula),
          calificacion(calificacion),
          likes(likes) {}


    //Getters
    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getId() const { // O(1)
        return id; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getIdPelicula() const { // O(1)
        return idPelicula; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getLikes() const { // O(1)
        return likes; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    int getCalificacion() const { // O(1)
        return calificacion; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    string getNombreUsuario() const { // O(1)
        return nombreUsuario; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    string getContenido() const { // O(1)
        return contenido; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    void darLike() { // O(1)
        likes++; // O(1)
    }

    // Mejor, promedio y peor caso: O(1). Espacio: O(1)
    void mostrar() const { // O(1)
        cout << "\n----------------------------------------\n"; // O(1)
        cout << "Usuario: " << nombreUsuario << endl; // O(1)
        cout << "Calificacion: " << calificacion << "/5" << endl; // O(1)
        cout << "Resena: " << contenido << endl; // O(1)
        cout << "Likes: " << likes << endl; // O(1)
        cout << "----------------------------------------\n"; // O(1)
    }
};

#endif