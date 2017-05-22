#pragma once

#include <cstdio>
#include <queue>
#include <fstream>
#include "NodoBB.hpp"

using namespace std;

template<class TYPE>
struct nodo_nivel { // Estructura para almacenar un nodo y el nivel en el que está.
	NodoBB<TYPE>* nodo;
	int nivel;
};

template <class TYPE>
class ArbolBB { // Clase para la implementación de un árbol binario de búsqueda.

private: 

	NodoBB<TYPE>* raiz; // Atributo del tipo NodoBB para declarar la raiz (inicio) del árbol.

public:

	ArbolBB(); // Constructor.
	ArbolBB(ArbolBB* copy); // Constructor de copia.
	~ArbolBB(); // Destructor.

	NodoBB<TYPE>* get_raiz(); // Función que retorna el valor del atributo raiz.
	void set_raiz(NodoBB<TYPE>* new_raiz); // Método que establece como raiz el valor pasado por parámetro.
	bool vacio(); // Función que devuelve si el arbol está vacío o no.

	NodoBB<TYPE>* buscar(TYPE clave_dada, int &contador_busquedas);
	NodoBB<TYPE>* buscar_rama(NodoBB<TYPE>* nodo, TYPE clave_dada, int &contador_busquedas);
	void insertar(TYPE clave_dada); // Método para insertar en el árbol una nueva clave.
	void insertar_rama(NodoBB<TYPE>* &nodo, TYPE clave_dada); // Método para insertar una nueva rama en el árbol. Se trata de un método recursivo.
	void insertar_fichero(char nombrefichero[]); // Método para insertar el árbol por fichero.
	void eliminar(TYPE clave_dada); // Método para eliminar un nodo del árbol.
	void eliminar_rama(NodoBB<TYPE>* &nodo, TYPE clave_dada);
	void sustituye(NodoBB<TYPE>* &eliminado, NodoBB<TYPE>* &sust);

	ostream& write(ostream& os); // Método para mostrar el árbol con el formato deseado.
	ostream& mostrar_arbol(ostream& os, NodoBB<TYPE>* nodo, int nivel); // Método para mostrar el árbol con el formato deseado.
	void imprimir(NodoBB<TYPE> *nodo, int nivel);
	void recorre(NodoBB<TYPE> *nodo);
};

template<class TYPE>
ArbolBB<TYPE>::ArbolBB(): // Constructor.
raiz(NULL) {}

template<class TYPE>
ArbolBB<TYPE>::ArbolBB(ArbolBB* copy): // Constructor de copia.
raiz(copy->raiz) {}

template<class TYPE>
ArbolBB<TYPE>::~ArbolBB() { // Destructor.

	raiz = NULL;
}

template <class TYPE>
NodoBB<TYPE>* ArbolBB<TYPE>::get_raiz() { // Función que retorna el valor del atributo raiz.

	return raiz;
}

template <class TYPE>
void ArbolBB<TYPE>::set_raiz(NodoBB<TYPE>* new_raiz) { // Método que establece como raiz el valor pasado por parámetro.

	raiz = new_raiz;
}

template <class TYPE>
bool ArbolBB<TYPE>::vacio() { // Función que devuelve si el arbol está vacío o no.

	if(raiz == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class TYPE>
NodoBB<TYPE>* ArbolBB<TYPE>::buscar(TYPE clave_dada, int &contador_busquedas) { // Función para buscar un valor dentro del árbol.

	return buscar_rama(raiz, clave_dada, contador_busquedas); 
}

template <class TYPE>
NodoBB<TYPE>* ArbolBB<TYPE>::buscar_rama(NodoBB<TYPE>* nodo, TYPE clave_dada, int &contador_busquedas) { // Función para buscar un valor dentro del árbol.

	if (nodo == NULL) { // Si el nodo pasado es igual a NULL, retornamos NULL.
		return NULL;
	}
	if (clave_dada == nodo->get_clave()) { // Si se encuentra el valor en el árbol, se retorna el nodo que lo contiene.
		contador_busquedas++; // Incrementamos el valor del contador.
		return nodo;
	}
	if (clave_dada < nodo->get_clave()) { // Si el valor pasado es menor que el nodo actual, nos desplazamos al nodo izquierdo.
		contador_busquedas++; // Incrementamos el valor del contador.
		return buscar_rama(nodo->nodo_izquierdo, clave_dada, contador_busquedas);
	}
	contador_busquedas++; // Incrementamos el valor del contador.
	return buscar_rama(nodo->nodo_derecho, clave_dada, contador_busquedas); // Si el valor pasado es menor que el nodo actual, nos desplazamos al nodo derecho.
}

template <class TYPE>
void ArbolBB<TYPE>::insertar(TYPE clave_dada) { // Método para insertar en el árbol una nueva clave.

	insertar_rama(raiz, clave_dada); // La inserción en el árbol comenzará por el nodo raiz e irá decendiendo recursivamente.
}

template <class TYPE>
void ArbolBB<TYPE>::insertar_rama(NodoBB<TYPE>* &nodo, TYPE clave_dada) { // Método para insertar una nueva rama en el árbol. Se trata de un método recursivo.

	if (nodo == NULL) { // En el momento que encuentre un nodo vacío, insertará la nueva clave_dada.
		nodo = new NodoBB<TYPE>(clave_dada);
	}
	else { // CONSERVAMOS LA SIMETRÍA DEL ÁRBOL.
		if (clave_dada < nodo->get_clave()) { // Si la clave_dada es menor que la del nodo actual.
			insertar_rama(nodo->get_nodo_izquierdo(), clave_dada); // Realizamos una llamada recursiva con el nodo izquierdo.
		}
		else { // Si la clave_dada es mayor que la del nodo actual.
			insertar_rama(nodo->get_nodo_derecho(), clave_dada); // Realizamos una llamada recursiva con el nodo derecho.
		}
	}
}

template <class TYPE>
void ArbolBB<TYPE>::insertar_fichero(char nombrefichero[]) { // Método para insertar un árbol por fichero.

	ifstream fichero; // Variable del tipo ifstream para trabajar con el fichero.
	int numero_nodos; // Variable para leer el número de nodos.
	TYPE nodo; // Variable para leer los nodos del árbol.
	fichero.open(nombrefichero); // Apertura del fichero.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		fichero >> numero_nodos; // PRIMERA LINEA: Leemos el número de nodos del árbol.

		for (int i = 0; i < numero_nodos; i++) { // BUCLE for: Extendemos el vector c a tamaño n + nh.
        	fichero >> nodo;
        	this->insertar(nodo);
     	}
     	fichero.close(); // Cierre del fichero.
    }

}

template <class TYPE>
void ArbolBB<TYPE>::eliminar(TYPE clave_dada) { // Método para eliminar un valor del árbol.

	eliminar_rama(raiz, clave_dada);
}

template <class TYPE>
void ArbolBB<TYPE>::eliminar_rama(NodoBB<TYPE>* &nodo, TYPE clave_dada) { // Método para eliminar un valor del árbol.

	// Primero debemos localizar el nodo a eliminar.
	if(nodo == NULL) { // Si el nodo pasado es igual, no realizamos nada.
		return;
	}
	if(clave_dada < nodo->get_clave()) { // Si el valor del nodo actual es mayor que el valor a eliminar, avanzamos por la izquierda.
		eliminar_rama(nodo->get_nodo_izquierdo(), clave_dada);
	}
	else if(clave_dada > nodo->get_clave()) { // Si el valor del nodo actual es menor que el valor a eliminar, avanzamos por la derecha.
		eliminar_rama(nodo->get_nodo_derecho(), clave_dada);
	}
	else { // Si no se cumple lo anterior, significa que hemos encontrado el nodo a eliminar.
		NodoBB<TYPE>* eliminado = nodo; // Almacenamos dicho nodo.
		if(nodo->get_nodo_derecho() == NULL) { // Si el nodo a eliminar solo tiene un hijo, sustituimos por este hijo, arrastrando todo el subarbol.
			nodo = nodo->get_nodo_izquierdo(); 
		}
		else if(nodo->get_nodo_izquierdo() == NULL) {
			nodo = nodo->get_nodo_derecho();
		}
		else { // Si el nodo a eliminar tiene dos hijos.
			sustituye(eliminado, nodo->get_nodo_izquierdo()); // Sustituimos el nodo a eliminar porque el que esta a su izquierda.
		}
		if(eliminado != NULL) { // Si no se cumple nada de lo anterior, significa que es un nodo hoja, por lo que eliminamos sin más.
			delete(eliminado);
			eliminado = NULL;
		}
	}
}

template <class TYPE>
void ArbolBB<TYPE>::sustituye(NodoBB<TYPE>* &eliminado, NodoBB<TYPE>* &sustituir) { // Método para realizar las sustituciones en la eliminación.

	if(sustituir->get_nodo_derecho() != NULL) { // Vamos descendiendo por los hijos y sustituyendo los nodos, es decir, subiendo un nivel el subarbol.
		sustituye(eliminado, sustituir->get_nodo_derecho());
	}
	else { // Cuando el nodo a eliminar se convierta en un nodo hoja.
		eliminado->set_clave(sustituir->get_clave()); 
		eliminado = sustituir;
		sustituir = sustituir->get_nodo_izquierdo();
	}
}

template <class TYPE>
void ArbolBB<TYPE>::recorre(NodoBB<TYPE> *nodo) { // Método para recorrer el árbol.

	nodo_nivel<TYPE> raiz_S; // Variable que almacenará el nodo raiz.
	nodo_nivel<TYPE> nodo_S; // Variable que almacenará el nodo a recorrer en ese momento.
	nodo_nivel<TYPE> nodo_auxiliar;

	raiz_S.nodo = nodo; // Inicializamos el nodo raiz.
	raiz_S.nivel = 0;
	queue<nodo_nivel<TYPE> > queue_nodo; // Cola para ir almacenando los nodos a ser mostrados.
	int nivel_actual = 0; // Variable contador para llevar la cuenta del nodo actual.
	queue_nodo.push(raiz_S); // Metemos en la cola el nodo raiz.

	while(queue_nodo.empty() == false) { // Mientras la cola con los nodos no esté vacía (los nodos siguientes eran iguales a NULL).
		nodo_S = queue_nodo.front(); // Almacenamos el primer nodo de la cola.
		queue_nodo.pop(); // Y los extraemos para quitarlo de la cola.
		if(nodo_S.nivel > nivel_actual) { // Si el nuevo nodo nos aparece en un nivel superior al que teniamos, aumentamos el valor de nodo_actual.
			nivel_actual = nodo_S.nivel;
		}
		if(nodo_S.nodo != NULL) { // Si el nodo extraido de la cola no está vacío.
			mostrar(nodo_S.nodo, nivel_actual); // Lo mostramos por pantalla.
			nodo_auxiliar.nivel = nodo_S.nivel; // Creamos un nodo auxiliares con los datos de los hijos del nodo actual.
			nodo_auxiliar.nodo = nodo_S.nodo->get_nodo_izquierdo();
			nodo_auxiliar.nivel = nodo_auxiliar.nivel + 1;			
			queue_nodo.push(nodo_auxiliar); // Metemos dichos nodos en la cola para repetir el proceso anterior.
			nodo_auxiliar.nodo = nodo_S.nodo->get_nodo_derecho();
			queue_nodo.push(nodo_auxiliar);
		}
		else {
			imprimir(nodo_S.nodo, nivel_actual); // Si el nodo está vacío, también lo mostramos, para ver por ejemplo aquellos nodos que solo tienen un hijo.
		}
	}
}

template<class TYPE>
void ArbolBB<TYPE>::mostrar(NodoBB<TYPE> *nodo, int nivel) { // Métoodo para imprimir los nodos bajo formato.
	
	if(this->vacio() == NULL) { // Si nuestro árbol está vacío, mostramos únicamente el nivel 0.
		cout << "NIVEL 0: [.]" << endl;
	}
	else { // Si no está vacío, lo mostramos bajo formato.
		if(contador_nivel > nivel) {}
			cout << endl << "NIVEL " << nivel << ": ";
			if(nodo == NULL) {
				cout << "[.]";
			}
			else {
				cout << "[" << nodo->get_clave() << "]";
			}			
		}
		else {
			if(nodo == NULL) {
				cout << "[.]";
			}
			else {
				cout << "[" << nodo->get_clave() << "]";
			}
		}
	}
}

/*template <class TYPE>
ostream& ArbolBB<TYPE>::mostrar_arbol(ostream& os, NodoBB<TYPE>* nodo, int nivel) {

	queue<NodoBB<TYPE>*> queue_nodo;
	int contador_hijos = 2; // Variable para redimensionar el vector_nodo.
	NodoBB<TYPE>* nodo_auxiliar = raiz;
	NodoBB<char>* nodo_vacío = new NodoBB<char>('.');

	//while(queue_nodo.empty() == false) {
	for(int j = 0; j < 2; j++) {
		os << "NIVEL " << j + 1 << ": ";
		for(int i = 0; i < (contador_hijos / 2); i++) {
			if((nodo_auxiliar->nodo_izquierdo == NULL) && (nodo_auxiliar->nodo_derecho != NULL)) {
				queue_nodo.push(nodo_auxiliar->nodo_derecho);
			}
			if((nodo_auxiliar->nodo_izquierdo != NULL) && (nodo_auxiliar->nodo_derecho == NULL)) {
				queue_nodo.push(nodo_auxiliar->nodo_izquierdo);
			}
			if((nodo_auxiliar->nodo_izquierdo != NULL) && (nodo_auxiliar->nodo_derecho != NULL)) {
				queue_nodo.push(nodo_auxiliar->nodo_izquierdo);
				queue_nodo.push(nodo_auxiliar->nodo_derecho);
			}
		}
		nodo_auxiliar = queue_nodo.front();
		queue_nodo.pop();
		for(int i = 0; i < contador_hijos; i++) {
			os << "[" << queue_nodo.back()->get_clave() << "]";
			queue_nodo.pop();
		}
		contador_hijos = contador_hijos * 2;
		os << endl;
		os << "NODO_AUXILIAR: " << nodo_auxiliar->get_clave() << endl;
	}

	return os;
}*/

