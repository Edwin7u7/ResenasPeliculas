# Sistema de reseñas de películas 
# A00842140 Edwin Arturo Salgado Santana

# Descripción del proyecto

El proyecto consiste en desarrollar una aplicación en C++ que permita a los usuarios consultar películas, calificarlas y compartir reseñas sobre ellas. Los usuarios también podrán interactuar con las reseñas mediante "me gusta".

El sistema busca simular una plataforma sencilla de opiniones cinematográficas, donde la información pueda ser consultada, buscada y organizada mediante diferentes criterios.

Además de las funciones básicas de una plataforma de reseñas, se implementará un sistema sencillo de recomendaciones basado en las preferencias del usuario. A partir de las películas que haya calificado positivamente, el programa podrá identificar los géneros que más le interesan y mostrar películas relacionadas.

# Principales funcionalidades
-Registrar películas.
-Consultar información de las películas.
-Buscar películas por nombre, género o año.
-Calificar películas.
-Escribir reseñas.
-Dar "me gusta" a las reseñas.
-Mostrar la calificación promedio de una película.
-Ordenar películas según diferentes criterios.
-Mostrar estadísticas de las películas.
-Generar recomendaciones basadas en las preferencias del usuario.

# Cómo utilizar el programa 

Al iniciar el programa se mostrará un menú principal con las diferentes opciones disponibles.

El usuario podrá consultar películas y posteriormente seleccionar una película para calificarla o escribir una reseña.

También podrá consultar las reseñas realizadas por otros usuarios y darles "me gusta".

La opción de ordenamiento permitirá organizar las películas utilizando diferentes criterios, como:

Calificación promedio.
Número de reseñas.
Año de estreno.
Número de "me gusta".

Finalmente, el sistema podrá utilizar las calificaciones del usuario para identificar sus géneros preferidos y generar recomendaciones.

# Algoritmo de ordenamiento 

Para el proyecto se utilizará el algoritmo Quick Sort.

Quick Sort será utilizado para ordenar las películas de acuerdo con diferentes criterios, principalmente por calificación promedio, aunque también podrá utilizarse para ordenar por número de reseñas, año de estreno o cantidad de "me gusta".

# Complejidad

Mejor caso: La complejidad temporal del Quick Sort en su mejor caso es de O(n log n).
Caso promedio: En el caso promedio, Quick Sort tiene una complejidad temporal de O(n log n)
Peor caso: En el peor caso, cuando las particiones son muy desiguales, su complejidad es O(n²)

# Cumplimiento de las sub-competencias

# SICT0301: Evalúa los componentes
Se analizó la complejidad temporal y espacial del algoritmo Quick Sort utilizado en el programa, considerando sus diferentes escenarios de ejecución: caso promedio y peor caso, identificando cómo cambia su comportamiento dependiendo de la distribución de los datos.

# SICT0302: Toma decisiones

Se seleccionó el algoritmo de ordenamiento Quick Sort debido que el sistema requiere el ordenamiento de las peliculas de acuerdo a diferentes criterios.
La elección permite utilizar un algoritmo de ordenamiento eficiente y, al mismo tiempo, trabajar con conceptos fundamentales de la materia.
