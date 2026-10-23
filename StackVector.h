/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <sstream>
#include "exception.h"

//Estructura de datos seleccionada StackVector

template <class T>
class Stack {
public:
	virtual void push(T) = 0;
	virtual T top() const  = 0;
	virtual void pop()  = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;

};

template <class T>
class StackVector : public Stack<T> {
private:
	unsigned int next;
	unsigned int size;
	T 			 *data;

public:
	StackVector(unsigned int) ;
	StackVector(const StackVector<T>&);
	StackVector<T>& operator=(const StackVector<T>&);
	~StackVector();
	void push(T) ;
	T top() const ;
	void pop() ;
	bool empty() const;
	void clear();
	std::string toString() const;
};

// Constructor.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
StackVector<T>::StackVector(unsigned int sze)  { // O(n)
	next = 0; // O(1)
	size = sze; // O(1)
	data = new T[size]; // O(n), construye n objetos
	if (data == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}
}

// Constructor de copia.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
StackVector<T>::StackVector(const StackVector<T> &source) { // O(n)
	next = source.next; // O(1)
	size = source.size; // O(1)
	data = new T[size]; // O(n)
	if (data == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}
	for (unsigned int i = 0; i < next; i++) { // O(n)
		data[i] = source.data[i]; // O(1)
	}
}

// Asignacion.
// Mejor caso: O(1)  (se asigna a si misma: a = a)
// Caso promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
StackVector<T>& StackVector<T>::operator=(const StackVector<T> &source) { // O(n)
	if (this != &source) { // O(1)
		delete [] data; // O(n)
		next = source.next; // O(1)
		size = source.size; // O(1)
		data = new T[size]; // O(n)
		if (data == NULL) { // O(1)
			throw OutOfMemory(); // O(1)
		}
		for (unsigned int i = 0; i < next; i++) { // O(n)
			data[i] = source.data[i]; // O(1)
		}
	}
	return *this; // O(1)
}

// Destructor.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(1)
template <class T>
StackVector<T>::~StackVector() { // O(n)
	next = 0; // O(1)
	size = 0; // O(1)
	delete [] data; // O(n)
	data = NULL; // O(1)
}

// Funcion que inserta en el top.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
void StackVector<T>::push(T val)  { // O(1)
	if (next == size) { // O(1)
		throw Overflow(); // O(1)
	}

	data[next] = val; // O(1)
	next++; // O(1)
}

// Funcion que regresa copia del elemento hasta arriba sin quitarlo.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
T StackVector<T>::top() const  { // O(1)
	if (next < 1) { // O(1)
		throw NoSuchElement(); // O(1)
	}
	return data[next-1]; // O(1)
}

// Funcion que quita el top.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
void StackVector<T>::pop()  { // O(1)
	if (empty()) { // O(1)
		throw NoSuchElement(); // O(1)
	}
	next--; // O(1)
}

// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
bool StackVector<T>::empty() const { // O(1)
	return next == 0; // O(1)
}

// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
void StackVector<T>::clear() { // O(1)
	next = 0; // O(1)
}

// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)  
template <class T>
std::string StackVector<T>::toString() const { // O(n)
	std::stringstream aux; // O(1)

	aux << "["; // O(1)
	if (next > 0) { // O(1)
		aux << data[0]; // O(1)
		for (unsigned int i = 1; i < next; i++) { // O(n)
			aux << ", " << data[i]; // O(1)
		}
	}
	aux << "]"; // O(1)
	return aux.str(); // O(n)
}

#endif /* STACK_H_ */
