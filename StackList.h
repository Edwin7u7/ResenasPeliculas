/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef STACKLIST_H_
#define STACKLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

//Estructura de datos seleccionada StackList

template <class T>
class Stack {
public:

	virtual void push(T) = 0;
	virtual T top() const  = 0;
	virtual void pop()  = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual ~Stack() {}
};

template <class T> class StackList;

// Nodo de la lista: guarda un valor y el apuntador al siguiente nodo.
template <class T>
class Link {
private:
	T value;
	Link<T> *next;

	Link(T val) : value(val), next(NULL) {}
	Link(T val, Link<T> *nxt) : value(val), next(nxt) {}

	friend class StackList<T>;
};

template <class T>
class StackList : public Stack<T> {
private:
	Link<T> *head;
	unsigned int size;

	void copiar(const StackList<T>&);

public:
	StackList();
	StackList(const StackList<T>&);
	StackList<T>& operator=(const StackList<T>&);
	~StackList();
	void push(T);
	T top() const;
	void pop();
	bool empty() const;
	void clear();
	std::string toString() const;
};

// Constructor. La pila empieza vacia.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
StackList<T>::StackList() { // O(1)
	head = NULL; // O(1)
	size = 0; // O(1)
}


// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)  (un nodo nuevo por cada elemento)
template <class T>
void StackList<T>::copiar(const StackList<T> &source) { // O(n)
	head = NULL; // O(1)
	size = 0; // O(1)
	Link<T> *ultimo = NULL; // O(1)
	Link<T> *actual = source.head; // O(1)

	while (actual != NULL) { // O(n)
		Link<T> *nuevo = new Link<T>(actual->value); // O(1)
		if (nuevo == NULL) { // O(1)
			throw OutOfMemory(); // O(1)
		}
		if (ultimo == NULL) { // O(1)
			head = nuevo; // O(1)
		} else {
			ultimo->next = nuevo; // O(1)
		}
		ultimo = nuevo; // O(1)
		size++; // O(1)
		actual = actual->next; // O(1)
	}
}

// Constructor de copia.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
StackList<T>::StackList(const StackList<T> &source) { // O(n)
	copiar(source); // O(n)
}

// Asignacion
// Mejor caso: O(1) 
// Caso promedio y peor caso: O(n)
// Espacio: O(n)
template <class T>
StackList<T>& StackList<T>::operator=(const StackList<T> &source) { // O(n)
	if (this != &source) { // O(1)
		clear(); // O(n)
		copiar(source); // O(n)
	}
	return *this; // O(1)
}

// Destructor.
// Mejor, promedio y peor caso: O(n)
// Espacio: O(1)
template <class T>
StackList<T>::~StackList() { // O(n)
	clear(); // O(n)
}

// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)  (un nodo)
template <class T>
void StackList<T>::push(T val) { // O(1)
	Link<T> *nuevo = new Link<T>(val, head); // O(1)
	if (nuevo == NULL) { // O(1)
		throw OutOfMemory(); // O(1)
	}
	head = nuevo; // O(1)
	size++; // O(1)
}

// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
T StackList<T>::top() const { // O(1)
	if (empty()) { // O(1)
		throw NoSuchElement(); // O(1)
	}
	return head->value; // O(1)
}

// Quita el top y libera su nodo.
// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
void StackList<T>::pop() { // O(1)
	if (empty()) { // O(1)
		throw NoSuchElement(); // O(1)
	}
	Link<T> *borrar = head; // O(1)
	head = head->next; // O(1)
	delete borrar; // O(1)
	size--; // O(1)
}

// Mejor, promedio y peor caso: O(1)
// Espacio: O(1)
template <class T>
bool StackList<T>::empty() const { // O(1)
	return head == NULL; // O(1)
}

// Libera todos los nodos.
// Mejor caso: O(1)  (la pila ya esta vacia)
// Caso promedio y peor caso: O(n)
// Espacio: O(1)
template <class T>
void StackList<T>::clear() { // O(n)
	while (!empty()) { // O(n)
		pop(); // O(1)
	}
}

// Mejor, promedio y peor caso: O(n)
// Espacio: O(n) 
template <class T>
std::string StackList<T>::toString() const { // O(n)
	std::stringstream aux; // O(1)
	Link<T> *actual = head; // O(1)

	aux << "["; // O(1)
	if (actual != NULL) { // O(1)
		aux << actual->value; // O(1)
		actual = actual->next; // O(1)
		while (actual != NULL) { // O(n)
			aux << ", " << actual->value; // O(1)
			actual = actual->next; // O(1)
		}
	}
	aux << "]"; // O(1)
	return aux.str(); // O(n)
}

#endif /* STACKLIST_H_ */
