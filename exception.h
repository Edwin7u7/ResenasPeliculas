/*
* A00842140 Edwin Arturo Salgado Santana
*/

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
//Excepciones usadas por la estructura Vector

// Tamano invalido (por ejemplo, un Vector de 0 elementos).
class RangeError : public std::exception {
public:
	virtual const char* what() const throw() {
		return "RangeError";
	}
};

// Indice fuera de [0, length()).
class IndexOutOfBounds : public std::exception {
public:
	virtual const char* what() const throw() {
		return "IndexOutOfBounds";
	}
};


//Excepciones usadas por la estructura de StackVector

// No se pudo reservar memoria dinamica.
class OutOfMemory : public std::exception {
public:
	virtual const char* what() const throw() {
		return "OutOfMemory";
	}
};

// push() sobre una pila llena.
class Overflow : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Overflow";
	}
};

// top() o pop() sobre una pila vacia.
class NoSuchElement : public std::exception {
public:
	virtual const char* what() const throw() {
		return "NoSuchElement";
	}
};



#endif 
