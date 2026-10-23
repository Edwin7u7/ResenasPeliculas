/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Vector.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "Reseña.h"
#include "Categoria.h"


// Estructuras de datos:
//   - peliculas  : Vector<Pelicula>  (quicksort necesita acceso por indice)
//   - usuarios   : Vector<Usuario>
//   - resenas    : Vector<Resena>
//   - categorias : Vector<Categoria>
//   - Usuario::peliculasCalificadas : StackVector<int> (Usuario.h)


class Sistema {
private:
    Vector<Pelicula> peliculas;
    Vector<Usuario> usuarios;
    Vector<Resena> resenas;
    Vector<Categoria> categorias;

    int siguienteIdResena = 1;

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

    Pelicula* buscarPorId(int id) {

        for (unsigned int i = 0; i < peliculas.length(); i++) {

            if (peliculas[i].getId() == id) {
                return &peliculas[i];
            }
        }

        return nullptr;
    }


    // ========================================================
    // BUSCAR USUARIO
    // ========================================================
    // Busqueda secuencial
    Usuario* buscarUsuario(int id) {

        for (unsigned int i = 0; i < usuarios.length(); i++) {

            if (usuarios[i].getId() == id) {
                return &usuarios[i];
            }
        }

        return nullptr;
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

    void mostrarPeliculas() {

        cout << "\n========================================\n";
        cout << "          LISTA DE PELICULAS\n";
        cout << "========================================\n";

        for (unsigned int i = 0; i < peliculas.length(); i++) {

            const Pelicula& pelicula = peliculas[i];

            pelicula.mostrar();

            cout << "----------------------------------------\n";
        }
    }


    // ========================================================
    // BUSCAR PELICULA
    // ========================================================

    void buscarPelicula() {

        int opcion;

        cout << "\nBuscar por:\n";
        cout << "1. Nombre\n";
        cout << "2. Categoria\n";
        cout << "3. Anio\n";
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        if (opcion == 1) {

            string nombre;

            cout << "Nombre: ";
            getline(cin, nombre);

            bool encontrada = false;

            for (unsigned int i = 0; i < peliculas.length(); i++) {

                const Pelicula& pelicula = peliculas[i];

                if (
                    pelicula.getTitulo().find(nombre)
                    != string::npos
                ) {

                    pelicula.mostrar();
                    cout << endl;

                    encontrada = true;
                }
            }

            if (!encontrada) {
                cout << "No se encontraron peliculas.\n";
            }
        }


        else if (opcion == 2) {

            string categoria;

            cout << "Categoria: ";
            getline(cin, categoria);

            bool encontrada = false;

            for (unsigned int i = 0; i < peliculas.length(); i++) {

                const Pelicula& pelicula = peliculas[i];

                if (pelicula.getCategoria() == categoria) {

                    pelicula.mostrar();
                    cout << endl;

                    encontrada = true;
                }
            }

            if (!encontrada) {
                cout << "No se encontraron peliculas.\n";
            }
        }


        else if (opcion == 3) {

            int anio;

            cout << "Anio: ";
            cin >> anio;

            bool encontrada = false;

            for (unsigned int i = 0; i < peliculas.length(); i++) {

                const Pelicula& pelicula = peliculas[i];

                if (pelicula.getAnio() == anio) {

                    pelicula.mostrar();
                    cout << endl;

                    encontrada = true;
                }
            }

            if (!encontrada) {
                cout << "No se encontraron peliculas.\n";
            }
        }
    }


    // ========================================================
    // CREAR RESEÑA
    // ========================================================

    void crearResena() {

        int idUsuario;
        int idPelicula;
        int calificacion;
        string contenido;

        cout << "\nID del usuario: ";
        cin >> idUsuario;

        Usuario* usuario =
            buscarUsuario(idUsuario);

        if (usuario == nullptr) {

            cout << "Usuario no encontrado.\n";
            return;
        }


        cout << "ID de la pelicula: ";
        cin >> idPelicula;

        Pelicula* pelicula =
            buscarPorId(idPelicula);

        if (pelicula == nullptr) {

            cout << "Pelicula no encontrada.\n";
            return;
        }


        cout << "Calificacion (1-5): ";
        cin >> calificacion;

        if (calificacion < 1 || calificacion > 5) {

            cout << "Calificacion invalida.\n";
            return;
        }


        cin.ignore();

        cout << "Escribe tu resena: ";
        getline(cin, contenido);


        Resena nuevaResena(
            siguienteIdResena,
            contenido,
            usuario->getNombre(),
            idPelicula,
            calificacion
        );


        try {
            usuario->registrarCalificacion(idPelicula);   // push a la pila
        } catch (Overflow&) {
            cout << "El usuario alcanzo el limite de calificaciones.\n";
            return;
        }

        resenas.push_back(nuevaResena);

        siguienteIdResena++;

        pelicula->agregarResena();

        pelicula->agregarCalificacion(calificacion);


        cout << "\nResena agregada correctamente.\n";
    }


    // ========================================================
    // MOSTRAR RESEÑAS
    // ========================================================

    void mostrarResenas() {

        int idPelicula;

        cout << "\nID de la pelicula: ";
        cin >> idPelicula;

        bool encontrada = false;

        for (unsigned int i = 0; i < resenas.length(); i++) {

            if (resenas[i].getIdPelicula() == idPelicula) {

                resenas[i].mostrar();

                encontrada = true;
            }
        }

        if (!encontrada) {

            cout << "Esta pelicula no tiene resenas.\n";
        }
    }


    // ========================================================
    // DAR LIKE
    // ========================================================

    void darLike() {

        int idResena;

        cout << "\nID de la resena: ";
        cin >> idResena;

        if (
            idResena < 1 ||
            (unsigned int) idResena > resenas.length() ||
            resenas[idResena - 1].getId() != idResena
        ) {
            cout << "Resena no encontrada.\n";
            return;
        }

        resenas[idResena - 1].darLike();

        cout << "Like agregado correctamente.\n";
    }


    // ========================================================
    // RANKING DE PELICULAS
    // ========================================================

    void mostrarRanking() {

        cout << "\n========================================\n";
        cout << "          RANKING DE PELICULAS\n";
        cout << "========================================\n";

        ordenarPeliculasPorCalificacionDescendente();


        int posicion = 1;

        for (unsigned int i = 0; i < peliculas.length(); i++) {

            const Pelicula& pelicula = peliculas[i];

            cout << posicion
                 << ". "
                 << pelicula.getTitulo()
                 << " - "
                //  << fixed
                //  << setprecision(1)
                 << pelicula.getCalificacion()
                 << "/5\n";

            posicion++;
        }
    }


    // ========================================================
    // VER PERFIL DE USUARIO
    // ========================================================
    // Muestra el historial de peliculas calificadas, guardado en un
    // StackVector. Se recorre una COPIA de la pila con top() y pop(), asi
    // las peliculas salen de la mas reciente a la mas antigua (LIFO) y la
    // pila original del usuario no se modifica.

    void verPerfilUsuario() {

        int idUsuario;

        cout << "\nID del usuario: ";
        cin >> idUsuario;

        Usuario* usuario =
            buscarUsuario(idUsuario);

        if (usuario == nullptr) {

            cout << "Usuario no encontrado.\n";
            return;
        }

        cout << "\n========================================\n";
        cout << "           PERFIL DE USUARIO\n";
        cout << "========================================\n";

        usuario->mostrarInformacion();

        StackVector<int> historial =
            usuario->getPeliculasCalificadas();

        if (historial.empty()) {

            cout << "\nAun no ha calificado peliculas.\n";
            return;
        }

        // top(): consulta la ultima pelicula calificada
        Pelicula* ultima = buscarPorId(historial.top());

        if (ultima != nullptr) {
            cout << "\nUltima pelicula calificada: "
                 << ultima->getTitulo() << endl;
        }

        cout << "\nHistorial (de la mas reciente a la mas antigua):\n";

        int posicion = 1;

        while (!historial.empty()) {

            Pelicula* pelicula = buscarPorId(historial.top());

            if (pelicula != nullptr) {
                cout << posicion << ". "
                     << pelicula->getTitulo() << endl;
                posicion++;
            }

            historial.pop();
        }
    }


    //// Menu principal ////
    void ejecutar() {

        int opcion;

        do {

            cout << "\n\n";
            cout << "========================================\n";
            cout << "       SISTEMA DE RESENAS DE PELICULAS\n";
            cout << "========================================\n";

            cout << "1. Mostrar peliculas\n";
            cout << "2. Buscar pelicula\n";
            cout << "3. Escribir resena\n";
            cout << "4. Consultar resenas\n";
            cout << "5. Dar like a una resena\n";
            cout << "6. Ver ranking de peliculas\n";
            cout << "7. Ver perfil de usuario\n";
            cout << "0. Salir\n";

            cout << "\nSelecciona una opcion: ";
            cin >> opcion;


            switch (opcion) {

            case 1:
                mostrarPeliculas();
                break;

            case 2:
                buscarPelicula();
                break;

            case 3:
                crearResena();
                break;

            case 4:
                mostrarResenas();
                break;

            case 5:
                darLike();
                break;

            case 6:
                mostrarRanking();
                break;

            case 7:
                verPerfilUsuario();
                break;

            case 0:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
            }

        } while (opcion != 0);
    }

    // Cargar datos en los vectores desde archivos .csv

    // Lee los 4 archivos CSV de la carpeta indicada. Formato de cada uno:
    //   - Separador ';' (se abren en el Bloc de notas y en Excel).
    //   - La primera linea es el encabezado y se ignora.
    //   - Las lineas vacias se saltan; las lineas con errores se reportan
    //     (archivo y numero de linea) y se omiten sin detener la carga.


    bool cargarDatos(const string &carpeta) {

        cout << "Cargando datos desde la carpeta '" << carpeta << "'...\n";

        int totalCategorias = cargarCategorias(carpeta + "/categorias.csv");
        int totalUsuarios   = cargarUsuarios(carpeta + "/usuarios.csv");
        int totalPeliculas  = cargarPeliculas(carpeta + "/peliculas.csv");
        int totalResenas    = cargarResenas(carpeta + "/resenas.csv");

        cout << "Categorias: " << totalCategorias
             << " | Usuarios: " << totalUsuarios
             << " | Peliculas: " << totalPeliculas
             << " | Resenas: " << totalResenas << endl;

        return totalPeliculas > 0;
    }

private:

    // Quita espacios, tabuladores y '\r' al inicio y al final.
    // (Los archivos guardados en Windows terminan cada linea en "\r\n".)
    string limpiar(const string &texto) {

        size_t inicio = texto.find_first_not_of(" \t\r\n");

        if (inicio == string::npos) {
            return "";
        }

        size_t fin = texto.find_last_not_of(" \t\r\n");

        return texto.substr(inicio, fin - inicio + 1);
    }

    // Separa una linea en campos usando ';'.
    Vector<string> separar(const string &linea, unsigned int numCampos) {

        Vector<string> campos;
        size_t inicio = 0;

        while (campos.length() + 1 < numCampos) {

            size_t pos = linea.find(';', inicio);

            if (pos == string::npos) {
                break;
            }

            campos.push_back(limpiar(linea.substr(inicio, pos - inicio)));
            inicio = pos + 1;
        }

        campos.push_back(limpiar(linea.substr(inicio)));

        return campos;
    }

    // Convierte texto a entero. Lanza excepcion si no es un numero
    
    int aEntero(const string &texto) {

        size_t usados = 0;
        int valor = stoi(texto, &usados);

        if (usados != texto.length()) {
            throw invalid_argument(texto);
        }

        return valor;
    }

    // Convierte texto a decimal
    double aDecimal(string texto) {

        for (unsigned int i = 0; i < texto.length(); i++) {
            if (texto[i] == ',') {
                texto[i] = '.';
            }
        }

        size_t usados = 0;
        double valor = stod(texto, &usados);

        if (usados != texto.length()) {
            throw invalid_argument(texto);
        }

        return valor;
    }

    // Abre el archivo y salta la linea de encabezado.
    // Regresa false si el archivo no existe o no se puede abrir.
    bool abrirArchivo(ifstream &archivo, const string &ruta) {

        archivo.open(ruta);

        if (!archivo.is_open()) {
            cout << "  No se pudo abrir el archivo: " << ruta << endl;
            return false;
        }

        string encabezado;
        getline(archivo, encabezado);

        return true;
    }

    void reportarError(const string &ruta, int numLinea, const string &motivo) {
        cout << "  [" << ruta << ", linea " << numLinea << "] "
             << motivo << ". Se omite la linea.\n";
    }

    // Busqueda secuencial.
    Categoria* buscarCategoria(int id) {

        for (unsigned int i = 0; i < categorias.length(); i++) {

            if (categorias[i].getId() == id) {
                return &categorias[i];
            }
        }

        return nullptr;
    }

    // Busqueda secuencial por nombre.
    Usuario* buscarUsuarioPorNombre(const string &nombre) {

        for (unsigned int i = 0; i < usuarios.length(); i++) {

            if (usuarios[i].getNombre() == nombre) {
                return &usuarios[i];
            }
        }

        return nullptr;
    }

    // Formato: id;nombre
    int cargarCategorias(const string &ruta) {

        ifstream archivo;

        if (!abrirArchivo(archivo, ruta)) {
            return 0;
        }

        string linea;
        int numLinea = 1;
        int cargados = 0;

        while (getline(archivo, linea)) {

            numLinea++;

            if (limpiar(linea).empty()) {
                continue;
            }

            Vector<string> campos = separar(linea, 2);

            if (campos.length() != 2 || campos[1].empty()) {
                reportarError(ruta, numLinea, "se esperaba id;nombre");
                continue;
            }

            try {
                int id = aEntero(campos[0]);

                if (buscarCategoria(id) != nullptr) {
                    reportarError(ruta, numLinea, "id de categoria repetido");
                    continue;
                }

                categorias.push_back(Categoria(id, campos[1]));
                cargados++;

            } catch (const exception &) {
                reportarError(ruta, numLinea, "id no es un numero valido");
            }
        }

        archivo.close();

        return cargados;
    }

    // Formato: id;nombre
    int cargarUsuarios(const string &ruta) {

        ifstream archivo;

        if (!abrirArchivo(archivo, ruta)) {
            return 0;
        }

        string linea;
        int numLinea = 1;
        int cargados = 0;

        while (getline(archivo, linea)) {

            numLinea++;

            if (limpiar(linea).empty()) {
                continue;
            }

            Vector<string> campos = separar(linea, 2);

            if (campos.length() != 2 || campos[1].empty()) {
                reportarError(ruta, numLinea, "se esperaba id;nombre");
                continue;
            }

            try {
                int id = aEntero(campos[0]);

                if (buscarUsuario(id) != nullptr) {
                    reportarError(ruta, numLinea, "id de usuario repetido");
                    continue;
                }

                usuarios.push_back(Usuario(id, campos[1]));
                cargados++;

            } catch (const exception &) {
                reportarError(ruta, numLinea, "id no es un numero valido");
            }
        }

        archivo.close();

        return cargados;
    }

    // Formato:
    // id;titulo;idCategoria;anio;calificacion;numeroCalificaciones;numeroResenas
    int cargarPeliculas(const string &ruta) {

        ifstream archivo;

        if (!abrirArchivo(archivo, ruta)) {
            return 0;
        }

        string linea;
        int numLinea = 1;
        int cargados = 0;

        while (getline(archivo, linea)) {

            numLinea++;

            if (limpiar(linea).empty()) {
                continue;
            }

            Vector<string> campos = separar(linea, 7);

            if (campos.length() != 7 || campos[1].empty()) {
                reportarError(ruta, numLinea, "se esperaban 7 campos");
                continue;
            }

            try {
                int id = aEntero(campos[0]);
                int idCategoria = aEntero(campos[2]);
                int anio = aEntero(campos[3]);
                double calificacion = aDecimal(campos[4]);
                int numeroCalificaciones = aEntero(campos[5]);
                int numeroResenas = aEntero(campos[6]);

                if (buscarPorId(id) != nullptr) {
                    reportarError(ruta, numLinea, "id de pelicula repetido");
                    continue;
                }

                Categoria* categoria = buscarCategoria(idCategoria);

                if (categoria == nullptr) {
                    reportarError(ruta, numLinea, "la categoria no existe");
                    continue;
                }

                if (calificacion < 0 || calificacion > 5 ||
                    numeroCalificaciones < 0 || numeroResenas < 0) {
                    reportarError(ruta, numLinea, "valores fuera de rango");
                    continue;
                }

                peliculas.push_back(
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
                cargados++;

            } catch (const exception &) {
                reportarError(ruta, numLinea, "algun dato numerico no es valido");
            }
        }

        archivo.close();

        return cargados;
    }

    // Formato: usuario;idPelicula;calificacion;likes;contenido
    // El id de cada resena se asigna en orden (1, 2, 3, ...) 
    int cargarResenas(const string &ruta) {

        ifstream archivo;

        if (!abrirArchivo(archivo, ruta)) {
            return 0;
        }

        string linea;
        int numLinea = 1;
        int cargados = 0;

        while (getline(archivo, linea)) {

            numLinea++;

            if (limpiar(linea).empty()) {
                continue;
            }

            Vector<string> campos = separar(linea, 5);

            if (campos.length() != 5 || campos[4].empty()) {
                reportarError(ruta, numLinea, "se esperaban 5 campos");
                continue;
            }

            try {
                int idPelicula = aEntero(campos[1]);
                int calificacion = aEntero(campos[2]);
                int likes = aEntero(campos[3]);

                Usuario* usuario = buscarUsuarioPorNombre(campos[0]);

                if (usuario == nullptr) {
                    reportarError(ruta, numLinea, "el usuario no existe");
                    continue;
                }

                if (buscarPorId(idPelicula) == nullptr) {
                    reportarError(ruta, numLinea, "la pelicula no existe");
                    continue;
                }

                if (calificacion < 1 || calificacion > 5 || likes < 0) {
                    reportarError(ruta, numLinea, "valores fuera de rango");
                    continue;
                }

                // La pelicula tambien queda en el historial del usuario
                // (push a su StackVector).
                try {
                    usuario->registrarCalificacion(idPelicula);
                } catch (Overflow &) {
                    reportarError(ruta, numLinea,
                                  "el usuario alcanzo el limite de calificaciones");
                    continue;
                }

                resenas.push_back(
                    Resena(
                        siguienteIdResena++,
                        campos[4],
                        campos[0],
                        idPelicula,
                        calificacion,
                        likes
                    )
                );
                cargados++;

            } catch (const exception &) {
                reportarError(ruta, numLinea, "algun dato numerico no es valido");
            }
        }

        archivo.close();

        return cargados;
    }
};
#endif
