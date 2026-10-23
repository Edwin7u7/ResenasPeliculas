# Proyecto: Sistema de reseñas de películas
**A00842140 Edwin Arturo Salgado Santana**

Programa en C++ que simula una plataforma sencilla de opiniones cinematográficas. Permite consultar un catálogo de películas, buscarlas por distintos criterios, escribir reseñas con calificación, dar "me gusta" a las reseñas, ver un ranking de películas ordenado por calificación y consultar el historial de películas calificadas por cada usuario.

La información (categorías, usuarios, películas y reseñas) se carga desde archivos de texto externos .csv y se guarda en las estructuras de datos, se seleccionó un **Vector** (arreglo dinámico) para los catálogos y una **StackVector** para el historial de calificaciones de cada usuario. El ranking se genera con el algoritmo de ordenamiento **Quick Sort**.

## Descripción del avance 1
En este avance solo se plantearon las funcionalidades del programa en el archivo README.md, y se implementó el "cascarón" de las clases Categoria, Pelicula, Reseña, Usuario, y Sistema junto con sus getters y setters, al igual que se planteó la selección del algoritmo de ordenamiento a implementar **QuickSort** con complejidad O(n log n) en el mejor caso y en el caso promedio, y O(n²) en el peor caso, pero no se alcanzó a mostrar el funcionamiento ni la ejecución del programa debido a la falta de un archivo main.cpp. Aspecto que en el segundo avance se ha corregido por completo.

Funcionalidades planteadas: registrar películas, consultar su información, buscarlas por nombre, género o año, calificar peliculas, escribir reseñas, dar "me gusta", mostrar la calificación promedio, ordenar películas según diferentes criterios, mostrar estadísticas y generar recomendaciones.


## Descripción del avance 2
En este avance el programa ya es funcional comparado con el avance 1 donde solo estaba el README.md e incluye:

- **Lectura de archivos:** al iniciar, el programa carga los datos desde cuatro archivos CSV de la carpeta `datos/` (`categorias.csv`, `usuarios.csv`, `peliculas.csv` y `resenas.csv`), validando cada registro.
- **Estructuras de datos seleccionadas:**
  - `Vector<T>` (`Vector.h`): arreglo dinámico que guarda películas, usuarios, reseñas y categorías al inciar el programa.
  - `StackVector<T>` (`StackVector.h`): Guarda el historial de películas calificadas de cada usuario.
- **Quick Sort** (`Sistema.h`): ordena el `Vector` de películas de mayor a menor calificación para el ranking.

- **Menú principal del avance 2:**
  1. Mostrar películas
  2. Buscar película (por nombre, categoría o año)
  3. Escribir reseña
  4. Consultar reseñas de una película
  5. Dar "me gusta" a una reseña
  6. Ver ranking de películas (Quick Sort)
  7. Ver perfil de usuario (historial en el StackVector)
  0. Salir

### Cambios sobre el primer avance
1. **Los datos se cargan desde archivos externos y no están escritos en el código.** En el planteamiento original las películas se "registraban" dentro del programa. Ahora se leen de archivos CSV editables con Excel o el Bloc de notas, lo que permite cambiar o ampliar el catálogo y cumplir la competencia de lectura de archivos.
2. **Se implementaron estructuras de datos en lugar de usar la biblioteca `std::vector`.** Se creó la clase `Vector` (basada en la vista en clase) para películas, usuarios, reseñas y categorías. Se eligió porque el programa solo agrega elementos al final, necesita acceso por índice en O(1) (indispensable para Quick Sort).
3. **Se agregó `StackVector` para el historial de calificaciones de cada usuario.** El historial se consulta de lo más reciente a lo más antiguo, que es justamente el comportamiento LIFO de una pila: la última película calificada siempre está en el top y se obtiene en O(1).
4. **Se agregó la opción "Ver perfil de usuario".** No estaba en el planteamiento original, pero sin ella no había forma de consultar la información guardada en la pila.
5. **Quick Sort ordena por un solo criterio (calificación promedio).** En el avance 1 se planteó ordenar también por número de reseñas, año y número de "me gusta". En este avance se priorizó el criterio principal, que es el que usa el ranking de películas.
6. **La calificación de una película se registra al escribir una reseña.** En lugar de tener una opción separada para calificar una película como se mencionaba en el primer avance, "Escribir reseña" registra la calificación en la película (actualizando su promedio) y en el historial del usuario, junto con el texto de la reseña.



## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal, desde la carpeta del proyecto:

`g++ main.cpp -std=c++11 -o segundo_avance`

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal, **desde la carpeta del proyecto** (el programa busca la carpeta `datos/` en el directorio actual):

`./segundo_avance`

## Descripción de las entradas del avance de proyecto
El programa tiene dos tipos de entrada: los **archivos de datos** que se leen al iniciar y las **opciones que el usuario escribe en el menú**.

### Archivos de datos
Están en la carpeta `datos/`. Todos son archivos CSV separados por punto y coma (`;`), se pueden abrir en Excel o en el Bloc de notas, y su primera línea es un encabezado que el programa ignora. Se usó `;` porque los textos de las reseñas contienen comas y porque es el separador que usa Excel en español.

**`categorias.csv`**
```
id;nombre
1;Ciencia Ficcion
```

**`usuarios.csv`** 
```
id;nombre
1;Edwin
```

**`peliculas.csv`** 
- `idCategoria` debe existir en `categorias.csv`.
- `calificacion` es un decimal entre 0 y 5 (acepta `4.9` o `4,9`).
```
id;titulo;idCategoria;anio;calificacion;numeroCalificaciones;numeroResenas
1;El origen;1;2010;4.9;120;80
```

**`resenas.csv`** 
- `usuario` debe existir en `usuarios.csv` e `idPelicula` en `peliculas.csv`.
- `calificacion` es un entero de 1 a 5 y `likes` debe ser 0 o mayor.
- `contenido` va al final y puede contener comas o `;`.
```
usuario;idPelicula;calificacion;likes;contenido
Edwin;1;5;15;Una pelicula excelente, la historia te mantiene pensando hasta el final.
```

El orden de carga es categorías → usuarios → películas → reseñas, porque cada archivo depende de los anteriores.

### Entradas del menú
Desde el teclado se captura la opción del menú y, según la opción, el id del usuario, el id de la película, la calificación (1 a 5), el texto de la reseña, el id de la reseña o el criterio de búsqueda.

## Descripción de las salidas del avance de proyecto
- **Al iniciar:** un resumen de la carga, por ejemplo `Categorias: 6 | Usuarios: 4 | Peliculas: 12 | Resenas: 9`. Si no se carga ninguna película, el programa muestra un mensaje y termina.
- **Mostrar películas / Buscar película:** La salida muestra la ficha de cada película (id, título, categoría, año, calificación promedio, número de calificaciones y de reseñas), o el mensaje "No se encontraron peliculas".
- **Escribir reseña:** La salida es una confirmación "Resena agregada correctamente"; l
- **Consultar reseñas:** La salida muestra cada reseña de la película con su usuario, calificación, texto y número de "me gusta".
- **Dar "me gusta":** La salida es una confirmación o "Resena no encontrada".
- **Ver ranking:** La salida es una la lista numerada de películas de mayor a menor calificación, por ejemplo:
  ```
  1. El origen - 4.9/5
  2. Interestelar - 4.8/5
  3. La isla siniestra - 4.8/5
  ```
- **Ver perfil de usuario:**La salida muestra el nombre, el número de películas calificadas, la última película calificada y el historial de la más reciente a la más antigua:
  ```
  Usuario: Ana
  Peliculas calificadas: 3
  Ultima pelicula calificada: La isla siniestra
  Historial (de la mas reciente a la mas antigua):
  1. La isla siniestra
  2. Interestelar
  3. El origen
  ```

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En el primer avance solo escribí la complejidad de Quick Sort, sin explicar de dónde salía y sin hablar del espacio. Ahora el análisis está completo y comentado en `Sistema.h`, junto a las funciones `particion` y `quickSort`.

Quick Sort elige un **pivote**, acomoda a un lado las películas con mayor calificación y al otro las de menor (esto es la **partición**, que recorre los datos una vez: O(n)), y repite lo mismo con cada lado.

- **Mejor caso y caso promedio: O(n log n).** El pivote parte los datos más o menos a la mitad, así que hay unos log n niveles de división y en cada nivel se recorren n elementos.
- **Peor caso: O(n²).** Pasa cuando el pivote siempre queda en un extremo (por ejemplo, si las películas ya estaban ordenadas). Cada paso solo separa un elemento, lo que da n + (n−1) + ... + 1 operaciones.
- **Espacio:** no crea otro arreglo, solo intercambia elementos dentro del mismo. Lo único extra es la memoria de las llamadas recursivas: O(log n) en promedio y O(n) en el peor caso.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Cada estructura tiene su análisis al inicio de su archivo y cada función que la usa tiene su complejidad comentada.

- **`Vector`:** acceder a cualquier posición es O(1), porque los datos están juntos en memoria. Agregar al final (`push_back`) es **O(1)**: cuando se llena, duplica su tamaño y copia todo (O(n)), pero eso pasa muy pocas veces, así que en promedio cada inserción cuesta O(1). Ocupa O(n) de espacio.
- **`StackVector` (pila):** `push`, `pop` y `top` son O(1) siempre, porque solo trabajan con el elemento de arriba. Ocupa espacio fijo O(n), con n = 100 por usuario.


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Elegí Quick Sort, aunque ese no vimos en clase, se hizo la investigación correspondiente y lo elegí porque:
- En promedio es O(n log n), mucho más rápido que métodos como bubbleSort o selectionSort (O(n²)). Esto importa porque el ranking se vuelve a ordenar cada vez que se consulta.
- No necesita memoria extra para otro arreglo, a diferencia de Merge Sort.
- Funciona bien con el `Vector`, porque necesita entrar a cualquier posición rápido.

Se usa en la opción **6. Ver ranking**, que ordena las películas de mayor a menor calificación. Si se escribe una reseña que cambia una calificación, el ranking se actualiza.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Elegí cada estructura de datos vista en clase según lo que el programa hace con los datos:

- **`Vector` para películas, usuarios, reseñas y categorías.** El programa solo agrega al final, recorre, busca y modifica; nunca borra ni inserta en medio. El vector hace todo eso rápido y permite entrar a cualquier posición en O(1), algo que es indispensable para implementar Quick Sort.

- **`StackVector` para el historial de cada usuario.** El historial se consulta de lo más reciente a lo más antiguo, que es justo como funciona una pila (**LIFO**, el último en entrar es el primero en salir). Con `top()` se obtiene la última película calificada en O(1).

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El programa permite consultar la información de varias formas:
- **Recorrer todo el vector** para mostrar las películas (opción del menú 1).

- **Búsqueda secuencial** por nombre, categoría o año (opción del menú 2). 

- **Ver las películas ordenadas** en el ranking (opción del menú 6).

- **Consultar la pila** con `top()` para ver la última película calificada, y recorrer una copia de la pila para ver todo el historial sin perder los datos originales (opción del menú 7).

Cuando no hay resultados, el programa lo indica con un mensaje (por ejemplo, "No se encontraron peliculas" o "Usuario no encontrado").

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Los datos ya no están escritos en el código: se cargan desde cuatro archivos CSV de la carpeta `datos/` con la función `cargarDatos()` de `Sistema.h`. Cada archivo se lee línea por línea, se separan los datos por `;`, se crea el objeto y se agrega a su vector.

La carga es correcta porque:
1. **Sigue un orden:** primero categorías y usuarios, luego películas y al final reseñas, porque cada una depende de las anteriores.
2. **Valida los datos:** número de campos, números válidos, ids repetidos y rangos correctos (calificación de 1 a 5, etc.).
3. **No se detiene por un error:** si una línea está mal, avisa en qué archivo y en qué línea está el problema, la salta y sigue con las demás.
4. **Acepta archivos editados en Excel o en el Bloc de notas**, incluyendo decimales escritos con coma (`4,9`).

La carga recorre cada archivo una vez, y por cada línea busca en los vectores que no haya repetidos y que existan las referencias. Por eso su tiempo es O(n²) en el peor caso, con n registros. Al iniciar, el programa muestra cuántos datos se cargaron de cada archivo.


### Referencias ###
#### QuickSort implementacion ####
GeeksforGeeks. (2026, August 11). C++ program for quick sort. GeeksforGeeks. https://www.geeksforgeeks.org/cpp/cpp-program-for-quicksort/

#### Lectura y carga de archivos .csv/bloc de notas ####
https://medium.com/@ryan_forrester_/reading-csv-files-in-c-how-to-guide-35030eb378ad