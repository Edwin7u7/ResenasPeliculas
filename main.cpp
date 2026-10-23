/*
* A00842140 Edwin Arturo Salgado Santana
*/

#include <iostream>
#include "Sistema.h"

int main(){
    Sistema sistema;

    // Se cargan los datos dummy de Productos, Categorias, Peliculas y Reseñas respectivamente
    if (!sistema.cargarDatos("datos")) {
        cout << "\nNo se cargo ninguna pelicula. Verifica que la carpeta "
             << "'datos' este junto al programa.\n";
        return 1;
    }

    // Inicio de programa
    sistema.ejecutar();

    return 0;
}
