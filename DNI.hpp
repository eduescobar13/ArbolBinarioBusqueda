#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class DNI { // Clase para la implementación de un número decimal DNI.
    
private: // Atributos privados de la clase.
    
    int valor;
    
public: // Métodos públicos de la clase.
    
    DNI(int valor); // Constructor.
    DNI(); // Constructor por defecto.
    DNI(DNI& copia); // Constructor de copia.
    ~DNI(); // Destructor.
    
    int get_valor() const; // Método getter del atributo valor.
    void set_valor(int nuevo_valor); // Método setter dl atributo valor.
    
    // SOBRECARGA DE OPERADORES.
	int operator %(int &operando2); // Sobrecarga del operador % para realizar operaciones de módulo.
	bool operator ==(const DNI &operando); // Sobrecarga del operador == para realizar comparaciones entre DNI.
	bool operator ==(const int &operando); // Sobrecarga del operador == para comparar DNI con enteros.
	DNI& operator =(DNI &operando); // Sobrecarga del operador = para establecer DNI.
	DNI& operator =(int operando); // Sobrecarga del operador =.
	bool operator <(const DNI &operando); // Sobrecarga del operador < para comparar DNI.
	bool operator >(const DNI &operando); // Sobrecarga del operador > para comparar DNI.
	bool operator <=(const DNI &operando); // Sobrecarga del operador < para comparar DNI.
	bool operator >=(const DNI &operando); // Sobrecarga del operador > para comparar DNI.
    
};

// MÉTODOS EXTERNOS A LA CLASE.

ostream& operator <<(ostream& cout_dni, const DNI &operando); // Función para la salida de dni. Sobrecarga del operador '<<'.

