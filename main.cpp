/*
* A00842140 Edwin Arturo Salgado Santana
*/

/*
 * ==========================================================================
 *  COMPLEJIDAD FINAL DEL PROGRAMA
 * ==========================================================================
 *  n = numero de registros del sistema (peliculas, usuarios, resenas).
 *
 *  El programa tiene tres etapas:
 *
 *   1. Cargar datos (cargarDatos) ......................... O(n^2)
 *      Por cada una de las n lineas de un archivo se busca en un vector de
 *      hasta n elementos (ids repetidos, usuario y pelicula de una resena).
 *
 *   2. Menu (ejecutar). Cada opcion cuesta:
 *        1. Mostrar peliculas ............................. O(n)
 *        2. Buscar pelicula ............................... O(n)
 *        3. Escribir resena ............................... O(n)
 *        4. Consultar resenas ............................. O(n)
 *        5. Dar like ...................................... O(1)
 *        6. Ver ranking (quicksort) ....................... O(n log n) promedio,
 *                                                           O(n^2) peor caso
 *        7. Ver perfil de usuario ......................... O(n^2)
 *        8. Guardar cambios ............................... O(n)
 *      La opcion mas costosa es O(n^2).
 *
 *   3. Guardar datos al salir (guardarDatos) .............. O(n)
 *
 *  Sumando las etapas: O(n^2) + O(n^2) + O(n) = O(n^2)
 *
 *  COMPLEJIDAD FINAL EN TIEMPO: O(n^2)
 *  (por cada opcion que elige el usuario; si elige varias, el costo es
 *  O(n^2) multiplicado por el numero de opciones elegidas).
 *
 *  COMPLEJIDAD FINAL EN ESPACIO: O(n)
 *  Los vectores guardan los n registros, el historial (StackList) de todos
 *  los usuarios suma a lo mucho n nodos (uno por resena) y lo extra que se
 *  usa en una opcion (copia de una pila, recursion del quicksort) es O(n).
 * ==========================================================================
 */

#include <iostream>
#include "Sistema.h"

// Mejor, promedio y peor caso: O(n^2)  (ver la explicacion de arriba)
// Espacio: O(n)
int main(){ // O(n^2)
    Sistema sistema; // O(1)

    // Se cargan los datos dummy de Productos, Categorias, Peliculas y Reseñas respectivamente
    if (!sistema.cargarDatos("datos")) { // O(n^2)
        cout << "\nNo se cargo ninguna pelicula. Verifica que la carpeta " // O(1)
             << "'datos' este junto al programa.\n";
        return 1; // O(1)
    }

    // Inicio de programa
    sistema.ejecutar(); // O(n^2) por cada opcion elegida

    return 0; // O(1)
}
