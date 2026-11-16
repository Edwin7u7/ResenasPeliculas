/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <cstdio>
#include "Vector.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "Reseña.h"
#include "Categoria.h"

class Sistema {
private:
    Vector<Pelicula> peliculas;
    Vector<Usuario> usuarios;
    Vector<Resena> resenas;
    Vector<Categoria> categorias;

    int siguienteIdResena = 1;

    // Carpeta de donde se cargaron los datos; ahi mismo se guardan.
    string carpetaDatos = "datos";



    ///Inicio funciones Quicksort ///


    //Funcion para intercambiar
    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1) 
    void swap(Pelicula &a, Pelicula &b){ // O(1)
        Pelicula temporal = a; // O(1)
        a = b; // O(1)
        b = temporal; // O(1)
    }

    //Funcion de particion
    // n = numero de elementos del rango [bajo, alto]
    // Mejor, promedio y peor caso: O(n)  (siempre recorre todo el rango)
    // Espacio: O(1)
    int particion(int bajo, int alto){ // O(n)
        double pivote = peliculas[alto].getCalificacion(); // O(1), acceso por indice
        int i = bajo - 1; // O(1)
        for(int j = bajo; j <= alto -1; j++){ // O(n)

            // Orden descendente:
            // peliculas con mayor calificacion van primero
            if (peliculas[j].getCalificacion() >= pivote) { // O(1)
                i++; // O(1)

                swap(peliculas[i], peliculas[j]); // O(1)
            }
        }

        swap(peliculas[i + 1], peliculas[alto]); // O(1)

        return i + 1; // O(1)
    }

    //Funcion principal Quicksort
    // n = numero de peliculas
    // Mejor caso: O(n log n)  (el pivote parte el rango a la mitad)
    // Caso promedio: O(n log n)
    // Peor caso: O(n^2)  (el pivote queda siempre en un extremo, por
    //                     ejemplo si las peliculas ya estaban ordenadas)
    // Espacio: O(log n) mejor y promedio caso, O(n) peor caso
    void quickSort(int bajo, int alto) { // O(n log n) promedio, O(n^2) peor
        if (bajo < alto) { // O(1)

            int pi = particion(bajo, alto); // O(n)

            quickSort(bajo, pi - 1); // O(n log n) promedio, O(n^2) peor
            quickSort(pi + 1, alto); // O(n log n) promedio, O(n^2) peor
        }
    }
    /// Fin funciones Quicksort ///


    // ========================================================
    // BUSCAR PELICULA POR ID
    // ========================================================

    // Busqueda secuencial

    // Mejor caso: O(1)  (el elemento esta en la primera posicion)
    // Caso promedio: O(n)
    // Peor caso: O(n)  (no existe o esta en la ultima posicion)
    // Espacio: O(1)
    Pelicula* buscarPorId(int id) { // O(n)

        for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

            if (peliculas[i].getId() == id) { // O(1)
                return &peliculas[i]; // O(1)
            }
        }

        return nullptr; // O(1)
    }


    // ========================================================
    // BUSCAR USUARIO
    // ========================================================
    // Busqueda secuencial
    // Mejor caso: O(1)  (el elemento esta en la primera posicion)
    // Caso promedio: O(n)
    // Peor caso: O(n)  (no existe o esta en la ultima posicion)
    // Espacio: O(1)
    Usuario* buscarUsuario(int id) { // O(n)

        for (unsigned int i = 0; i < usuarios.length(); i++) { // O(n)

            if (usuarios[i].getId() == id) { // O(1)
                return &usuarios[i]; // O(1)
            }
        }

        return nullptr; // O(1)
    }
public:
    // Llama a quickSort con todo el vector de peliculas.
    // Mejor caso: O(n log n)
    // Caso promedio: O(n log n)
    // Peor caso: O(n^2)
    // Espacio: O(log n) promedio, O(n) peor caso
    void ordenarPeliculasPorCalificacionDescendente() { // O(n log n) promedio, O(n^2) peor
        if (!peliculas.empty()) { // O(1)
            quickSort(0, peliculas.length() - 1); // O(n log n) promedio, O(n^2) peor
        }
    }

     // ========================================================
    // MOSTRAR TODAS LAS PELICULAS
    // ========================================================

    // Mejor, promedio y peor caso: O(n)  (recorre todas las peliculas)
    // Espacio: O(1)
    void mostrarPeliculas() { // O(n)

        cout << "\n========================================\n"; // O(1)
        cout << "          LISTA DE PELICULAS\n"; // O(1)
        cout << "========================================\n"; // O(1)

        for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

            const Pelicula& pelicula = peliculas[i]; // O(1)

            pelicula.mostrar(); // O(1)

            cout << "----------------------------------------\n"; // O(1)
        }
    }


    // ========================================================
    // BUSCAR PELICULA
    // ========================================================

    // Mejor, promedio y peor caso: O(n)  (siempre recorre todas las peliculas)
    // Espacio: O(1)
    void buscarPelicula() { // O(n)

        int opcion; // O(1)

        cout << "\nBuscar por:\n"; // O(1)
        cout << "1. Nombre\n"; // O(1)
        cout << "2. Categoria\n"; // O(1)
        cout << "3. Anio\n"; // O(1)
        cout << "Opcion: "; // O(1)
        cin >> opcion; // O(1)

        cin.ignore(); // O(1)

        if (opcion == 1) { // O(1)

            string nombre; // O(1)

            cout << "Nombre: "; // O(1)
            getline(cin, nombre); // O(1)

            bool encontrada = false; // O(1)

            for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

                const Pelicula& pelicula = peliculas[i]; // O(1)

                if ( // O(1)
                    pelicula.getTitulo().find(nombre)
                    != string::npos
                ) {

                    pelicula.mostrar(); // O(1)
                    cout << endl; // O(1)

                    encontrada = true; // O(1)
                }
            }

            if (!encontrada) { // O(1)
                cout << "No se encontraron peliculas.\n"; // O(1)
            }
        }


        else if (opcion == 2) { // O(1)

            string categoria; // O(1)

            cout << "Categoria: "; // O(1)
            getline(cin, categoria); // O(1)

            bool encontrada = false; // O(1)

            for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

                const Pelicula& pelicula = peliculas[i]; // O(1)

                if (pelicula.getCategoria() == categoria) { // O(1)

                    pelicula.mostrar(); // O(1)
                    cout << endl; // O(1)

                    encontrada = true; // O(1)
                }
            }

            if (!encontrada) { // O(1)
                cout << "No se encontraron peliculas.\n"; // O(1)
            }
        }


        else if (opcion == 3) { // O(1)

            int anio; // O(1)

            cout << "Anio: "; // O(1)
            cin >> anio; // O(1)

            bool encontrada = false; // O(1)

            for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

                const Pelicula& pelicula = peliculas[i]; // O(1)

                if (pelicula.getAnio() == anio) { // O(1)

                    pelicula.mostrar(); // O(1)
                    cout << endl; // O(1)

                    encontrada = true; // O(1)
                }
            }

            if (!encontrada) { // O(1)
                cout << "No se encontraron peliculas.\n"; // O(1)
            }
        }
    }


    // ========================================================
    // CREAR RESEÑA
    // ========================================================

    // Mejor caso: O(1)  (el usuario y la pelicula estan en las primeras posiciones)
    // Caso promedio: O(n)  (buscar al usuario y a la pelicula)
    // Peor caso: O(n)
    // Espacio: O(1)   (O(n) si el vector de resenas tiene que crecer)
    void crearResena() { // O(n)

        int idUsuario; // O(1)
        int idPelicula; // O(1)
        int calificacion; // O(1)
        string contenido; // O(1)

        cout << "\nID del usuario: "; // O(1)
        cin >> idUsuario; // O(1)

        Usuario* usuario = // O(n)
            buscarUsuario(idUsuario);

        if (usuario == nullptr) { // O(1)

            cout << "Usuario no encontrado.\n"; // O(1)
            return; // O(1)
        }


        cout << "ID de la pelicula: "; // O(1)
        cin >> idPelicula; // O(1)

        Pelicula* pelicula = // O(n)
            buscarPorId(idPelicula);

        if (pelicula == nullptr) { // O(1)

            cout << "Pelicula no encontrada.\n"; // O(1)
            return; // O(1)
        }


        cout << "Calificacion (1-5): "; // O(1)
        cin >> calificacion; // O(1)

        if (calificacion < 1 || calificacion > 5) { // O(1)

            cout << "Calificacion invalida.\n"; // O(1)
            return; // O(1)
        }


        cin.ignore(); // O(1)

        cout << "Escribe tu resena: "; // O(1)
        getline(cin, contenido); // O(1)

        // Una resena vacia no se podria volver a cargar desde el archivo.
        if (limpiar(contenido).empty()) { // O(1)

            cout << "La resena no puede estar vacia.\n"; // O(1)
            return; // O(1)
        }


        Resena nuevaResena( // O(1)
            siguienteIdResena,
            contenido,
            usuario->getNombre(),
            idPelicula,
            calificacion
        );


        usuario->registrarCalificacion(idPelicula); // O(1), push a la pila

        resenas.push_back(nuevaResena); // O(1)  

        siguienteIdResena++; // O(1)

        pelicula->agregarResena(); // O(1)

        pelicula->agregarCalificacion(calificacion); // O(1)


        cout << "\nResena agregada correctamente.\n"; // O(1)
    }


    // ========================================================
    // MOSTRAR RESEÑAS
    // ========================================================

    // Mejor, promedio y peor caso: O(n)  (recorre todas las resenas)
    // Espacio: O(1)
    void mostrarResenas() { // O(n)

        int idPelicula; // O(1)

        cout << "\nID de la pelicula: "; // O(1)
        cin >> idPelicula; // O(1)

        bool encontrada = false; // O(1)

        for (unsigned int i = 0; i < resenas.length(); i++) { // O(n)

            if (resenas[i].getIdPelicula() == idPelicula) { // O(1)

                resenas[i].mostrar(); // O(1)

                encontrada = true; // O(1)
            }
        }

        if (!encontrada) { // O(1)

            cout << "Esta pelicula no tiene resenas.\n"; // O(1)
        }
    }


    // ========================================================
    // DAR LIKE
    // ========================================================

    // Mejor, promedio y peor caso: O(1) 
    // Espacio: O(1)
    void darLike() { // O(1)

        int idResena; // O(1)

        cout << "\nID de la resena: "; // O(1)
        cin >> idResena; // O(1)

        if ( // O(1)
            idResena < 1 ||
            (unsigned int) idResena > resenas.length() ||
            resenas[idResena - 1].getId() != idResena
        ) {
            cout << "Resena no encontrada.\n"; // O(1)
            return; // O(1)
        }

        resenas[idResena - 1].darLike(); // O(1)

        cout << "Like agregado correctamente.\n"; // O(1)
    }


    // ========================================================
    // RANKING DE PELICULAS
    // ========================================================

    // Mejor caso: O(n log n)
    // Caso promedio: O(n log n)
    // Peor caso: O(n^2)  (quicksort en su peor caso; imprimir es O(n))
    // Espacio: O(log n) promedio, O(n) peor caso  (recursion del quicksort)
    void mostrarRanking() { // O(n log n) promedio, O(n^2) peor

        cout << "\n========================================\n"; // O(1)
        cout << "          RANKING DE PELICULAS\n"; // O(1)
        cout << "========================================\n"; // O(1)

        ordenarPeliculasPorCalificacionDescendente(); // O(n log n) promedio, O(n^2) peor


        int posicion = 1; // O(1)

        for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

            const Pelicula& pelicula = peliculas[i]; // O(1)

            cout << posicion // O(1)
                 << ". "
                 << pelicula.getTitulo()
                 << " - "
                //  << fixed
                //  << setprecision(1)
                 << pelicula.getCalificacion()
                 << "/5\n";

            posicion++; // O(1)
        }
    }


    // ========================================================
    // VER PERFIL DE USUARIO
    // ========================================================
    // Muestra el historial de peliculas calificadas, guardado en un
    // StackList. Se recorre una COPIA de la pila con top() y pop(), asi
    // las peliculas salen de la mas reciente a la mas antigua (LIFO) y la
    // pila original del usuario no se modifica.

    // Mejor caso: O(1)  (el usuario esta al inicio y no tiene historial)
    // Caso promedio: O(n^2)  (por cada pelicula del historial se busca
    //   su titulo en el vector de peliculas, O(n) cada una)
    // Peor caso: O(n^2)
    // Espacio: O(n)  (copia de la pila del historial)
    void verPerfilUsuario() { // O(n^2)

        int idUsuario; // O(1)

        cout << "\nID del usuario: "; // O(1)
        cin >> idUsuario; // O(1)

        Usuario* usuario = // O(n)
            buscarUsuario(idUsuario);

        if (usuario == nullptr) { // O(1)

            cout << "Usuario no encontrado.\n"; // O(1)
            return; // O(1)
        }

        cout << "\n========================================\n"; // O(1)
        cout << "           PERFIL DE USUARIO\n"; // O(1)
        cout << "========================================\n"; // O(1)

        usuario->mostrarInformacion(); // O(n), cuenta los elementos de la pila

        StackList<int> historial = // O(n), copia la pila
            usuario->getPeliculasCalificadas();

        if (historial.empty()) { // O(1)

            cout << "\nAun no ha calificado peliculas.\n"; // O(1)
            return; // O(1)
        }

        // top(): consulta la ultima pelicula calificada
        Pelicula* ultima = buscarPorId(historial.top()); // O(n)

        if (ultima != nullptr) { // O(1)
            cout << "\nUltima pelicula calificada: " // O(1)
                 << ultima->getTitulo() << endl;
        }

        cout << "\nHistorial (de la mas reciente a la mas antigua):\n"; // O(1)

        int posicion = 1; // O(1)

        while (!historial.empty()) { // O(n)

            Pelicula* pelicula = buscarPorId(historial.top()); // O(n)

            if (pelicula != nullptr) { // O(1)
                cout << posicion << ". " // O(1)
                     << pelicula->getTitulo() << endl;
                posicion++; // O(1)
            }

            historial.pop(); // O(1)
        }
    }


    // ========================================================
    // GUARDAR DATOS EN ARCHIVOS
    // ========================================================

    // Mejor, promedio y peor caso: O(n)  (escribe cada vector una vez)
    // Espacio: O(1)
    bool guardarDatos(const string &carpeta) { // O(n)

        cout << "\nGuardando datos en la carpeta '" << carpeta << "'...\n"; // O(1)

        int totalCategorias = guardarCategorias(carpeta + "/categorias.csv"); // O(n)
        int totalUsuarios   = guardarUsuarios(carpeta + "/usuarios.csv"); // O(n)
        int totalPeliculas  = guardarPeliculas(carpeta + "/peliculas.csv"); // O(n)
        int totalResenas    = guardarResenas(carpeta + "/resenas.csv"); // O(n)

        if (totalCategorias < 0 || totalUsuarios < 0 || // O(1)
            totalPeliculas < 0 || totalResenas < 0) {

            cout << "No se pudieron guardar todos los datos.\n"; // O(1)
            return false; // O(1)
        }

        cout << "Datos guardados. Categorias: " << totalCategorias // O(1)
             << " | Usuarios: " << totalUsuarios
             << " | Peliculas: " << totalPeliculas
             << " | Resenas: " << totalResenas << endl;

        return true; // O(1)
    }


    //// Menu principal ////
    // Cada vuelta del menu cuesta lo que cueste la opcion elegida:
    //   Mejor caso: O(1)  (dar like u opcion invalida)
    //   Peor caso: O(n^2)  (ver perfil, o ranking en su peor caso)
    // El ciclo se repite una vez por cada opcion que elige el usuario.
    // Espacio: O(n)  (lo maximo es la copia de la pila en ver perfil)
    void ejecutar() { // O(n^2) por cada opcion

        int opcion; // O(1)

        do { // se repite una vez por cada opcion que elige el usuario

            cout << "\n\n"; // O(1)
            cout << "========================================\n"; // O(1)
            cout << "       SISTEMA DE RESENAS DE PELICULAS\n"; // O(1)
            cout << "========================================\n"; // O(1)

            cout << "1. Mostrar peliculas\n"; // O(1)
            cout << "2. Buscar pelicula\n"; // O(1)
            cout << "3. Escribir resena\n"; // O(1)
            cout << "4. Consultar resenas\n"; // O(1)
            cout << "5. Dar like a una resena\n"; // O(1)
            cout << "6. Ver ranking de peliculas\n"; // O(1)
            cout << "7. Ver perfil de usuario\n"; // O(1)
            cout << "8. Guardar cambios\n"; // O(1)
            cout << "0. Salir\n"; // O(1)

            cout << "\nSelecciona una opcion: "; // O(1)
            cin >> opcion; // O(1)


            switch (opcion) { // O(1)

            case 1:
                mostrarPeliculas(); // O(n)
                break; // O(1)

            case 2:
                buscarPelicula(); // O(n)
                break; // O(1)

            case 3:
                crearResena(); // O(n)
                break; // O(1)

            case 4:
                mostrarResenas(); // O(n)
                break; // O(1)

            case 5:
                darLike(); // O(1)
                break; // O(1)

            case 6:
                mostrarRanking(); // O(n log n) promedio, O(n^2) peor
                break; // O(1)

            case 7:
                verPerfilUsuario(); // O(n^2)
                break; // O(1)

            case 8:
                guardarDatos(carpetaDatos); // O(n)
                break; // O(1)

            case 0:
                preguntarGuardarAlSalir(); // O(n)
                cout << "\nSaliendo del programa...\n"; // O(1)
                break; // O(1)

            default:
                cout << "\nOpcion invalida.\n"; // O(1)
            }

        } while (opcion != 0); // O(1)
    }

    // Cargar datos en los vectores desde archivos .csv

    // Lee los 4 archivos CSV de la carpeta indicada. Formato de cada uno:
    //   - Separador ';' (se abren en el Bloc de notas y en Excel).
    //   - La primera linea es el encabezado y se ignora.
    //   - Las lineas vacias se saltan; las lineas con errores se reportan
    //     (archivo y numero de linea) y se omiten sin detener la carga.


    // Mejor, promedio y peor caso: O(n^2)  (es la suma de las 4 cargas)
    // Espacio: O(n)  (todos los registros cargados)
    bool cargarDatos(const string &carpeta) { // O(n^2)

        carpetaDatos = carpeta; // O(1)

        cout << "Cargando datos desde la carpeta '" << carpeta << "'...\n"; // O(1)

        int totalCategorias = cargarCategorias(carpeta + "/categorias.csv"); // O(n^2)
        int totalUsuarios   = cargarUsuarios(carpeta + "/usuarios.csv"); // O(n^2)
        int totalPeliculas  = cargarPeliculas(carpeta + "/peliculas.csv"); // O(n^2)
        int totalResenas    = cargarResenas(carpeta + "/resenas.csv"); // O(n^2)

        cout << "Categorias: " << totalCategorias // O(1)
             << " | Usuarios: " << totalUsuarios
             << " | Peliculas: " << totalPeliculas
             << " | Resenas: " << totalResenas << endl;

        return totalPeliculas > 0; // O(1)
    }

private:

    // Quita espacios, tabuladores y '\r' al inicio y al final.
    // (Los archivos guardados en Windows terminan cada linea en "\r\n".)
    // Mejor, promedio y peor caso: O(1)  
    // Espacio: O(1)
    string limpiar(const string &texto) { // O(1)

        size_t inicio = texto.find_first_not_of(" \t\r\n"); // O(1)

        if (inicio == string::npos) { // O(1)
            return ""; // O(1)
        }

        size_t fin = texto.find_last_not_of(" \t\r\n"); // O(1)

        return texto.substr(inicio, fin - inicio + 1); // O(1)
    }

    // Separa una linea en campos usando ';'.
    // Mejor, promedio y peor caso: O(1) 
    // Espacio: O(1)
    Vector<string> separar(const string &linea, unsigned int numCampos) { // O(1)

        Vector<string> campos; // O(1)
        size_t inicio = 0; // O(1)

        while (campos.length() + 1 < numCampos) { // O(1), a lo mucho 7 campos

            size_t pos = linea.find(';', inicio); // O(1)

            if (pos == string::npos) { // O(1)
                break; // O(1)
            }

            campos.push_back(limpiar(linea.substr(inicio, pos - inicio))); // O(1)  
            inicio = pos + 1; // O(1)
        }

        campos.push_back(limpiar(linea.substr(inicio))); // O(1)  

        return campos; // O(1)
    }

    // Convierte texto a entero. Lanza excepcion si no es un numero
    
    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1)
    int aEntero(const string &texto) { // O(1)

        size_t usados = 0; // O(1)
        int valor = stoi(texto, &usados); // O(1)

        if (usados != texto.length()) { // O(1)
            throw invalid_argument(texto); // O(1)
        }

        return valor; // O(1)
    }

    // Convierte texto a decimal
    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1)
    double aDecimal(string texto) { // O(1)

        for (unsigned int i = 0; i < texto.length(); i++) { // O(1), el texto es corto
            if (texto[i] == ',') { // O(1)
                texto[i] = '.'; // O(1)
            }
        }

        size_t usados = 0; // O(1)
        double valor = stod(texto, &usados); // O(1)

        if (usados != texto.length()) { // O(1)
            throw invalid_argument(texto); // O(1)
        }

        return valor; // O(1)
    }

    // Abre el archivo y salta la linea de encabezado.
    // Regresa false si el archivo no existe o no se puede abrir.
    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1)
    bool abrirArchivo(ifstream &archivo, const string &ruta) { // O(1)

        archivo.open(ruta); // O(1)

        if (!archivo.is_open()) { // O(1)
            cout << "  No se pudo abrir el archivo: " << ruta << endl; // O(1)
            return false; // O(1)
        }

        string encabezado; // O(1)
        getline(archivo, encabezado); // O(1)

        return true; // O(1)
    }

    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1)
    void reportarError(const string &ruta, int numLinea, const string &motivo) { // O(1)
        cout << "  [" << ruta << ", linea " << numLinea << "] " // O(1)
             << motivo << ". Se omite la linea.\n";
    }

    // Busqueda secuencial.
    // Mejor caso: O(1)  (el elemento esta en la primera posicion)
    // Caso promedio: O(n)
    // Peor caso: O(n)  (no existe o esta en la ultima posicion)
    // Espacio: O(1)
    Categoria* buscarCategoria(int id) { // O(n)

        for (unsigned int i = 0; i < categorias.length(); i++) { // O(n)

            if (categorias[i].getId() == id) { // O(1)
                return &categorias[i]; // O(1)
            }
        }

        return nullptr; // O(1)
    }

    // Busqueda secuencial por nombre.
    // Mejor caso: O(1)  (el elemento esta en la primera posicion)
    // Caso promedio: O(n)
    // Peor caso: O(n)  (no existe o esta en la ultima posicion)
    // Espacio: O(1)
    Usuario* buscarUsuarioPorNombre(const string &nombre) { // O(n)

        for (unsigned int i = 0; i < usuarios.length(); i++) { // O(n)

            if (usuarios[i].getNombre() == nombre) { // O(1)
                return &usuarios[i]; // O(1)
            }
        }

        return nullptr; // O(1)
    }

    // Formato: id;nombre
    // Mejor, promedio y peor caso: O(n^2) 
    // Espacio: O(n)
    int cargarCategorias(const string &ruta) { // O(n^2)

        ifstream archivo; // O(1)

        if (!abrirArchivo(archivo, ruta)) { // O(1)
            return 0; // O(1)
        }

        string linea; // O(1)
        int numLinea = 1; // O(1)
        int cargados = 0; // O(1)

        while (getline(archivo, linea)) { // O(n)

            numLinea++; // O(1)

            if (limpiar(linea).empty()) { // O(1)
                continue; // O(1)
            }

            Vector<string> campos = separar(linea, 2); // O(1)

            if (campos.length() != 2 || campos[1].empty()) { // O(1)
                reportarError(ruta, numLinea, "se esperaba id;nombre"); // O(1)
                continue; // O(1)
            }

            try {
                int id = aEntero(campos[0]); // O(1)

                if (buscarCategoria(id) != nullptr) { // O(n)
                    reportarError(ruta, numLinea, "id de categoria repetido"); // O(1)
                    continue; // O(1)
                }

                categorias.push_back(Categoria(id, campos[1])); // O(1) 
                cargados++; // O(1)

            } catch (const exception &) {
                reportarError(ruta, numLinea, "id no es un numero valido"); // O(1)
            }
        }

        archivo.close(); // O(1)

        return cargados; // O(1)
    }

    // Formato: id;nombre
    // Mejor, promedio y peor caso: O(n^2) 
    // Espacio: O(n)  
    int cargarUsuarios(const string &ruta) { // O(n^2)

        ifstream archivo; // O(1)

        if (!abrirArchivo(archivo, ruta)) { // O(1)
            return 0; // O(1)
        }

        string linea; // O(1)
        int numLinea = 1; // O(1)
        int cargados = 0; // O(1)

        while (getline(archivo, linea)) { // O(n)

            numLinea++; // O(1)

            if (limpiar(linea).empty()) { // O(1)
                continue; // O(1)
            }

            Vector<string> campos = separar(linea, 2); // O(1)

            if (campos.length() != 2 || campos[1].empty()) { // O(1)
                reportarError(ruta, numLinea, "se esperaba id;nombre"); // O(1)
                continue; // O(1)
            }

            try {
                int id = aEntero(campos[0]); // O(1)

                if (buscarUsuario(id) != nullptr) { // O(n)
                    reportarError(ruta, numLinea, "id de usuario repetido"); // O(1)
                    continue; // O(1)
                }

                usuarios.push_back(Usuario(id, campos[1])); // O(1)  
                cargados++; // O(1)

            } catch (const exception &) {
                reportarError(ruta, numLinea, "id no es un numero valido"); // O(1)
            }
        }

        archivo.close(); // O(1)

        return cargados; // O(1)
    }

    // Formato:
    // id;titulo;idCategoria;anio;calificacion;numeroCalificaciones;numeroResenas
    // Mejor, promedio y peor caso: O(n^2) 
    // Espacio: O(n) 
    int cargarPeliculas(const string &ruta) { // O(n^2)

        ifstream archivo; // O(1)

        if (!abrirArchivo(archivo, ruta)) { // O(1)
            return 0; // O(1)
        }

        string linea; // O(1)
        int numLinea = 1; // O(1)
        int cargados = 0; // O(1)

        while (getline(archivo, linea)) { // O(n)

            numLinea++; // O(1)

            if (limpiar(linea).empty()) { // O(1)
                continue; // O(1)
            }

            Vector<string> campos = separar(linea, 7); // O(1)

            if (campos.length() != 7 || campos[1].empty()) { // O(1)
                reportarError(ruta, numLinea, "se esperaban 7 campos"); // O(1)
                continue; // O(1)
            }

            try {
                int id = aEntero(campos[0]); // O(1)
                int idCategoria = aEntero(campos[2]); // O(1)
                int anio = aEntero(campos[3]); // O(1)
                double calificacion = aDecimal(campos[4]); // O(1)
                int numeroCalificaciones = aEntero(campos[5]); // O(1)
                int numeroResenas = aEntero(campos[6]); // O(1)

                if (buscarPorId(id) != nullptr) { // O(n)
                    reportarError(ruta, numLinea, "id de pelicula repetido"); // O(1)
                    continue; // O(1)
                }

                Categoria* categoria = buscarCategoria(idCategoria); // O(n)

                if (categoria == nullptr) { // O(1)
                    reportarError(ruta, numLinea, "la categoria no existe"); // O(1)
                    continue; // O(1)
                }

                if (calificacion < 0 || calificacion > 5 || // O(1)
                    numeroCalificaciones < 0 || numeroResenas < 0) {
                    reportarError(ruta, numLinea, "valores fuera de rango"); // O(1)
                    continue; // O(1)
                }

                peliculas.push_back( // O(1)  
                    Pelicula(
                        id,
                        campos[1],
                        *categoria,
                        anio,
                        calificacion,
                        numeroCalificaciones,
                        numeroResenas
                    )
                );
                cargados++; // O(1)

            } catch (const exception &) {
                reportarError(ruta, numLinea, "algun dato numerico no es valido"); // O(1)
            }
        }

        archivo.close(); // O(1)

        return cargados; // O(1)
    }

    // Formato: usuario;idPelicula;calificacion;likes;contenido
    // El id de cada resena se asigna en orden (1, 2, 3, ...) 
    // Mejor, promedio y peor caso: O(n^2)  
    // Espacio: O(n) 
    int cargarResenas(const string &ruta) { // O(n^2)

        ifstream archivo; // O(1)

        if (!abrirArchivo(archivo, ruta)) { // O(1)
            return 0; // O(1)
        }

        string linea; // O(1)
        int numLinea = 1; // O(1)
        int cargados = 0; // O(1)

        while (getline(archivo, linea)) { // O(n)

            numLinea++; // O(1)

            if (limpiar(linea).empty()) { // O(1)
                continue; // O(1)
            }

            Vector<string> campos = separar(linea, 5); // O(1)

            if (campos.length() != 5 || campos[4].empty()) { // O(1)
                reportarError(ruta, numLinea, "se esperaban 5 campos"); // O(1)
                continue; // O(1)
            }

            try {
                int idPelicula = aEntero(campos[1]); // O(1)
                int calificacion = aEntero(campos[2]); // O(1)
                int likes = aEntero(campos[3]); // O(1)

                Usuario* usuario = buscarUsuarioPorNombre(campos[0]); // O(n)

                if (usuario == nullptr) { // O(1)
                    reportarError(ruta, numLinea, "el usuario no existe"); // O(1)
                    continue; // O(1)
                }

                if (buscarPorId(idPelicula) == nullptr) { // O(n)
                    reportarError(ruta, numLinea, "la pelicula no existe"); // O(1)
                    continue; // O(1)
                }

                if (calificacion < 1 || calificacion > 5 || likes < 0) { // O(1)
                    reportarError(ruta, numLinea, "valores fuera de rango"); // O(1)
                    continue; // O(1)
                }

                // La pelicula tambien queda en el historial del usuario
                // (push a su StackList).
                usuario->registrarCalificacion(idPelicula); // O(1)

                resenas.push_back( // O(1)  
                    Resena(
                        siguienteIdResena++,
                        campos[4],
                        campos[0],
                        idPelicula,
                        calificacion,
                        likes
                    )
                );
                cargados++; // O(1)

            } catch (const exception &) {
                reportarError(ruta, numLinea, "algun dato numerico no es valido"); // O(1)
            }
        }

        archivo.close(); // O(1)

        return cargados; // O(1)
    }

    // ========================================================
    // ESCRITURA DE ARCHIVOS
    // ========================================================

    // Al salir pregunta si se quieren guardar los cambios.
    // Mejor caso: O(1)  (el usuario responde que no)
    // Peor caso: O(n)  (se guardan los datos)
    // Espacio: O(1)
    void preguntarGuardarAlSalir() { // O(n)

        char respuesta = 'n'; // O(1)

        cout << "\nDeseas guardar los cambios antes de salir? (s/n): "; // O(1)
        cin >> respuesta; // O(1)

        if (respuesta == 's' || respuesta == 'S') { // O(1)
            guardarDatos(carpetaDatos); // O(n)
        }
    }

    // Abre el archivo temporal (ruta + ".tmp") donde se va a escribir.
    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1)
    bool abrirArchivoEscritura(ofstream &archivo, const string &ruta) { // O(1)

        archivo.open((ruta + ".tmp").c_str()); // O(1)

        if (!archivo.is_open()) { // O(1)
            cout << "  No se pudo crear el archivo: " << ruta << endl; // O(1)
            return false; // O(1)
        }

        return true; // O(1)
    }

    // Cierra el temporal y, si todo se escribio bien, reemplaza el
    // archivo original por el temporal.
    // Mejor, promedio y peor caso: O(1)
    // Espacio: O(1)
    bool cerrarArchivoEscritura(ofstream &archivo, const string &ruta) { // O(1)

        bool correcto = archivo.good(); // O(1)
        archivo.close(); // O(1)

        string temporal = ruta + ".tmp"; // O(1)

        if (!correcto) { // O(1)
            remove(temporal.c_str()); // O(1)
            cout << "  Error al escribir el archivo: " << ruta << endl; // O(1)
            return false; // O(1)
        }

        remove(ruta.c_str()); // O(1)

        if (rename(temporal.c_str(), ruta.c_str()) != 0) { // O(1)
            cout << "  No se pudo reemplazar el archivo: " << ruta // O(1)
                 << " (los datos quedaron en " << temporal << ")\n";
            return false; // O(1)
        }

        return true; // O(1)
    }

    // Formato: id;nombre
    // Regresa cuantos registros escribio, o -1 si hubo un error.
    // Mejor, promedio y peor caso: O(n)
    // Espacio: O(1)
    int guardarCategorias(const string &ruta) { // O(n)

        ofstream archivo; // O(1)

        if (!abrirArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        archivo << "id;nombre\n"; // O(1)

        for (unsigned int i = 0; i < categorias.length(); i++) { // O(n)

            archivo << categorias[i].getId() << ';' // O(1)
                    << categorias[i].getNombre() << '\n';
        }

        if (!cerrarArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        return categorias.length(); // O(1)
    }

    // Formato: id;nombre
    // El historial (StackList) de cada usuario no se guarda aparte: se
    // reconstruye al cargar resenas.csv, porque cada resena registra la
    // pelicula en el historial de su usuario.
    // Mejor, promedio y peor caso: O(n)
    // Espacio: O(1)
    int guardarUsuarios(const string &ruta) { // O(n)

        ofstream archivo; // O(1)

        if (!abrirArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        archivo << "id;nombre\n"; // O(1)

        for (unsigned int i = 0; i < usuarios.length(); i++) { // O(n)

            archivo << usuarios[i].getId() << ';' // O(1)
                    << usuarios[i].getNombre() << '\n';
        }

        if (!cerrarArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        return usuarios.length(); // O(1)
    }

    // Formato:
    // id;titulo;idCategoria;anio;calificacion;numeroCalificaciones;numeroResenas
    // Mejor, promedio y peor caso: O(n)
    // Espacio: O(1)
    int guardarPeliculas(const string &ruta) { // O(n)

        ofstream archivo; // O(1)

        if (!abrirArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        archivo << "id;titulo;idCategoria;anio;calificacion;" // O(1)
                << "numeroCalificaciones;numeroResenas\n";

        // 15 cifras para no perder precision en el promedio al recargarlo.
        archivo << setprecision(15); // O(1)

        for (unsigned int i = 0; i < peliculas.length(); i++) { // O(n)

            archivo << peliculas[i].getId() << ';' // O(1)
                    << peliculas[i].getTitulo() << ';'
                    << peliculas[i].getIdCategoria() << ';'
                    << peliculas[i].getAnio() << ';'
                    << peliculas[i].getCalificacion() << ';'
                    << peliculas[i].getNumeroCalificaciones() << ';'
                    << peliculas[i].getNumeroResenas() << '\n';
        }

        if (!cerrarArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        return peliculas.length(); // O(1)
    }

    // Formato: usuario;idPelicula;calificacion;likes;contenido
    // Mejor, promedio y peor caso: O(n)
    // Espacio: O(1)
    int guardarResenas(const string &ruta) { // O(n)

        ofstream archivo; // O(1)

        if (!abrirArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        archivo << "usuario;idPelicula;calificacion;likes;contenido\n"; // O(1)

        for (unsigned int i = 0; i < resenas.length(); i++) { // O(n)

            archivo << resenas[i].getNombreUsuario() << ';' // O(1)
                    << resenas[i].getIdPelicula() << ';'
                    << resenas[i].getCalificacion() << ';'
                    << resenas[i].getLikes() << ';'
                    << resenas[i].getContenido() << '\n';
        }

        if (!cerrarArchivoEscritura(archivo, ruta)) { // O(1)
            return -1; // O(1)
        }

        return resenas.length(); // O(1)
    }
};
#endif
