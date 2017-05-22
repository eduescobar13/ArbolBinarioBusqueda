#pragma once

#include <cstdio>
#include "DNI.hpp"

using namespace std;

template <class TYPE>
class NodoBB { // Clase para la implementación de nodos de un árbol binario de búsqueda.

public:

	TYPE clave; // Valor que almacena el nodo.
	NodoBB<TYPE> *nodo_izquierdo; // Puntero al nodo hijo izquierdo.
	NodoBB<TYPE> *nodo_derecho; // Puntero al nodo hijo derecho.

public:

	NodoBB(TYPE value); // Constructor.
	NodoBB(); // Constructor por defecto.
	NodoBB(NodoBB &copy); // Constructor de copia.
	~NodoBB(); // Destructor.

	TYPE get_clave(); // Función que retorna el valor del atributo clave.
	void set_clave(TYPE new_clave); // Método que establece el valor de clave.
	NodoBB<TYPE>*& get_nodo_izquierdo(); // Función que retorna el valor del atributo nodo_izquierdo.
	void set_nodo_izquierdo(NodoBB* new_nodo_izquierdo); // Método que establece el valor de nodo_izquierdo.
	NodoBB<TYPE>*& get_nodo_derecho(); // Función que retorna el valor del atributo nodo_derecho.
	void set_nodo_derecho(NodoBB* new_nodo_derecho); // Método que establece el valor de nodo_derecho.

	bool tiene_hijos(); // Función que retorna si un nodo tiene hijos.

};

template <class TYPE>
NodoBB<TYPE>::NodoBB(TYPE value): // Constructor.
clave(value),
nodo_izquierdo(NULL),
nodo_derecho(NULL) {}

template <class TYPE>
NodoBB<TYPE>::NodoBB(): // Constructor por defecto.
clave(0),
nodo_izquierdo(NULL),
nodo_derecho(NULL) {}

template <class TYPE>
NodoBB<TYPE>::NodoBB(NodoBB &copy): // Constructor de copia.
clave(copy.clave),
nodo_izquierdo(copy.nodo_izquierdo),
nodo_derecho(copy.nodo_derecho) {}

template <class TYPE>
NodoBB<TYPE>::~NodoBB() { // Destructor.

	clave = 0;
	nodo_izquierdo = NULL;
	nodo_derecho = NULL;
}

template <class TYPE>
TYPE NodoBB<TYPE>::get_clave() { // Función que retorna el valor del atributo clave.

	return clave;
}

template <class TYPE>
void NodoBB<TYPE>::set_clave(TYPE new_clave) { // Método que establece el valor de clave.

	clave = new_clave;
}

template <class TYPE>
NodoBB<TYPE>*& NodoBB<TYPE>::get_nodo_izquierdo() { // Función que retorna el valor del atributo nodo_izquierdo.

	return nodo_izquierdo;
}

template <class TYPE>
void NodoBB<TYPE>::set_nodo_izquierdo(NodoBB* new_nodo_izquierdo) { // Método que establece el valor de nodo_izquierdo.

	nodo_izquierdo = new_nodo_izquierdo;
}

template <class TYPE>
NodoBB<TYPE>*& NodoBB<TYPE>::get_nodo_derecho() { // Función que retorna el valor del atributo nodo_derecho.

	return nodo_derecho;
}

template <class TYPE>
void NodoBB<TYPE>::set_nodo_derecho(NodoBB* new_nodo_derecho) { // Método que establece el valor de nodo_derecho.

	nodo_derecho = new_nodo_derecho;
}

template <class TYPE>
bool NodoBB<TYPE>::tiene_hijos() { // Función que retorna si un nodo tiene hijos.

	if((nodo_izquierdo == NULL) && (nodo_derecho == NULL)) {
		return false;
	}
	else {
		return true;
	}
}
