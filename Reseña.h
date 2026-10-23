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
    Resena()
        : id(0), contenido(""), nombreUsuario(""),
          idPelicula(0), calificacion(0), likes(0) {}

    //Constructor
    Resena(int id, string contenido, string nombreUsuario,
           int idPelicula, int calificacion, int likes = 0)
        : id(id),
          contenido(contenido),
          nombreUsuario(nombreUsuario),
          idPelicula(idPelicula),
          calificacion(calificacion),
          likes(likes) {}
    

    //Getters 
    int getId() const {
        return id;
    }

    int getIdPelicula() const {
        return idPelicula;
    }

    int getLikes() const {
        return likes;
    }

    int getCalificacion() const {
        return calificacion;
    }

    string getNombreUsuario() const {
        return nombreUsuario;
    }

    string getContenido() const {
        return contenido;
    }

    void darLike() {
        likes++;
    }

    void mostrar() const {
        cout << "\n----------------------------------------\n";
        cout << "Usuario: " << nombreUsuario << endl;
        cout << "Calificacion: " << calificacion << "/5" << endl;
        cout << "Resena: " << contenido << endl;
        cout << "Likes: " << likes << endl;
        cout << "----------------------------------------\n";
    }
};

#endif