/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include "exception.h"
#include <string>
#include <sstream>

//Estructura de datos seleccionada Vector
template <class T>
class Vector {
private:
	unsigned int size ; //Capacidad reservada del arreglo
	unsigned int count; //Numero de elementos guardados
	T	*data;

	void reserve(unsigned int);

public:
	//Constructores
	Vector();
	Vector(unsigned int) ;
	Vector(unsigned int, T&) ;
	Vector(const Vector<T>&);

	//Destructor
	~Vector();

	//Funciones
	unsigned int length() const;
	bool empty() const;
	void push_back(T);
	unsigned int resize(unsigned int) ;
	unsigned int resize(unsigned int, T&) ;
	std::string toString() const;

	//Sobrecargas de operadores
	T& operator[](unsigned int) const ;
	void operator=(const Vector<T>&);
};

// Vector vacio con capacidad inicial de 10.
// Mejor, promedio y peor caso: O(1) 
// Espacio: O(1)
template <class T>
Vector<T>::Vector() { // O(1)
	size = 10; // O(1)
	count = 0; // O(1)
	data = new T[size]; // O(1), reserva 10 localidades (constante)
	if(data == NULL) // O(1)
		throw OutOfMemory(); // O(1)
}

// Vector con numberOfElements elementos.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
Vector<T>::Vector(unsigned int numberOfElements)  { // O(n)
	if(numberOfElements == 0) { // O(1)
		throw RangeError(); // O(1)
	}
	size = numberOfElements; // O(1)
	count = numberOfElements; // O(1)
	data = new T[size]; // O(n)
	if(data == 0) // O(1)
		throw OutOfMemory(); // O(1)
}

// Vector con numberOfElements copias de initialValue.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
Vector<T>::Vector(unsigned int numberOfElements, T &initialValue)  { // O(n)
	if(numberOfElements == 0) { // O(1)
		throw RangeError(); // O(1)
	}

	size = numberOfElements; // O(1)
	count = numberOfElements; // O(1)
	data = new T[size]; // O(n)
	if(data == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}
	for(unsigned int i = 0; i < size; i++){ // O(n)
		data[i] = initialValue; // O(1)
	}
}

// Constructor de copia.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
Vector<T>::Vector(const Vector<T> &source) { // O(n)
	size = source.size; // O(1)
	count = source.count; // O(1)
	data = new T[size]; // O(n)
	if(data == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}
	for(unsigned int i = 0; i < count; i++){ // O(n)
		data[i] = source.data[i]; // O(1)
	}
}

// Destructor.
// Mejor, promedio y peor caso: O(n)  (destruye todas las localidades del arreglo)
// Espacio: O(1)
template <class T>
Vector<T>::~Vector() { // O(n)
	delete [] data; // O(n)
	data = NULL; // O(1)
	size = 0; // O(1)
	count = 0; // O(1)
}

// Numero de elementos guardados.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
unsigned int Vector<T>::length() const { // O(1)
	return count; // O(1)
}

// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
bool Vector<T>::empty() const { // O(1)
	return count == 0; // O(1)
}

// Cambia la capacidad conservando los elementos.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
void Vector<T>::reserve(unsigned int nuevaCapacidad) { // O(n)
	//Crear un nuevo arreglo en memoria dinámica
	T *temp = new T[nuevaCapacidad]; // O(n)

	//Validar que haya memoria disponible en el sistema operativo
	if (temp == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}

	//Copiar los elementos actuales en el nuevo arreglo
	for (unsigned int i = 0; i < count; i++) { // O(n)
		temp[i] = data[i]; // O(1)
	}

	//Liberar la memoria
	delete [] data; // O(n)
	data = temp; // O(1)
	size = nuevaCapacidad; // O(1)
}

// Agrega val al final. Si el arreglo esta lleno, duplica la capacidad.
// Mejor caso: O(1)  (hay espacio libre)
// Caso promedio: O(1) 
// Peor caso: O(n) 
// Espacio: O(1), u O(n) cuando crece
template <class T>
void Vector<T>::push_back(T val) { // O(1) 
	if (count == size) { // O(1)
		reserve(size * 2); // O(n)
	}
	data[count] = val; // O(1)
	count++; // O(1)
}

// Cambia el numero de elementos a newSize (conserva los primeros).
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
unsigned int Vector<T>::resize(unsigned int newSize)  { // O(n)
	if (newSize == 0) { // O(1)
		throw RangeError(); // O(1)
	}

	if (count > newSize) { // O(1)
		count = newSize; // O(1)
	}
	reserve(newSize); // O(n)
	count = newSize; // O(1)

	return newSize; // O(1)
}

// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
unsigned int Vector<T>::resize(unsigned int newSize, T &initValue)  { // O(n)
	if (newSize == 0) { // O(1)
		throw RangeError(); // O(1)
	}

	unsigned int anterior = count; // O(1)

	if (count > newSize) { // O(1)
		count = newSize; // O(1)
	}
	reserve(newSize); // O(n)

	//Llenar las localidades nuevas con initValue
	for (unsigned int i = anterior; i < newSize; i++) { // O(n)
		data[i] = initValue; // O(1)
	}
	count = newSize; // O(1)

	return newSize; // O(1)
}

// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
std::string Vector<T>::toString() const { // O(n)
	std::stringstream aux; // O(1)

	aux << "["; // O(1)
	if (count > 0) { // O(1)
		aux << data[0]; // O(1)
		for (unsigned int i = 1; i < count; i++) { // O(n)
			aux << ", " << data[i]; // O(1)
		}
	}
	aux << "]"; // O(1)
	return aux.str(); // O(n)
}

// Acceso por indice.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
T& Vector<T>::operator[] (unsigned int index) const  { // O(1)
	if (index >= count) { // O(1)
		throw IndexOutOfBounds(); // O(1)
	}
	return data[index]; // O(1)
}

// Asignacion.
// Mejor caso: O(1)  (se asigna a si mismo: a = a)
// Caso promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
void Vector<T>::operator=(const Vector<T> &right) { // O(n)
	if (this == &right) { // O(1)
		return; // O(1)
	}
	delete [] data; // O(n)
	size = right.size; // O(1)
	count = right.count; // O(1)
	data = new T[size]; // O(n)
	if (data == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}
	for (unsigned int i = 0; i < count; i++) { // O(n)
		data[i] = right.data[i]; // O(1)
	}
}

#endif /* VECTOR_H_ */
