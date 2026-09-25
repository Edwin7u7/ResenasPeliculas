#include <iostream>
#include <string>
#include <vector>
#include <pelicula.h>
#include <usuario.h>
#include <reseña.h>
class Sistema {
private:
    vector<Pelicula> peliculas;
    vector<Usuario> usuarios;
    vector<Reseña> resenas;

    void quickSort(int inicio, int fin) {
        int i = inicio;
        int j = fin;

        double referencia = peliculas[(inicio + fin) / 2].getCalificacion();

        //Funcion en proceso de construcción
    }

public:
    void agregarPelicula(Pelicula pelicula) {
        peliculas.push_back(pelicula);
    }

    void ordenarPeliculasPorCalificacion() {
        if (!peliculas.empty()) {
            quickSort(0, peliculas.size() - 1);
        }
    }

    
};