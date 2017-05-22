#include "DNI.hpp"

DNI::DNI(int valor): // Constructor.
valor(valor) {}

DNI::DNI(): // Constructor por defecto.
valor(0) {}

DNI::DNI(DNI& copia) { // Constructor de copia.
    
    copia.valor = valor;
}

DNI::~DNI() { // Destructor.
    
    valor = 0;
}

int DNI::get_valor() const { // Método getter del atributo valor.
    
    return valor;
}

void DNI::set_valor(int new_valor) { // Método setter del atributo valor.
    
    valor = new_valor;
}

// SOBRECARGA DE OPERADORES.

DNI& DNI::operator =(DNI &operando) { // Sobrecarga del operador =.

    valor = operando.valor;
    return *this;
}

DNI& DNI::operator =(int operando) { // Sobrecarga del operador =.

    valor = operando;
    return *this;
}

int DNI::operator %(int &operando) { // Sobrecarga del operador % para realizar operaciones de módulo.
    
    return (valor % operando);
}

bool DNI::operator ==(const DNI &operando) { // Sobrecarga del operador == para realizar comparaciones entre DNI.
    
    return (valor == operando.valor);
}

bool DNI::operator ==(const int &operando) { // Sobrecarga del operador == para comparar DNI con enteros.
    
    return (valor == operando);
}

bool DNI::operator <(const DNI &operando) { // Sobrecarga del operador < para comparar DNI.
    
    return (valor < operando.valor);
}

bool DNI::operator >(const DNI &operando) { // Sobrecarga del operador > para comparar DNI.
    
    return (valor > operando.valor);
}

bool DNI::operator <=(const DNI &operando) { // Sobrecarga del operador < para comparar DNI.
    
    return (valor <= operando.valor);
}

bool DNI::operator >=(const DNI &operando) { // Sobrecarga del operador > para comparar DNI.
    
    return (valor >= operando.valor);
}

// MÉTODOS EXTERNOS A LA CLASE.

ostream& operator <<(ostream& cout_dni, const DNI &operando) { // Función para la impresión de complejos. Sobrecarga del '<<'.
    
    cout_dni << operando.get_valor();
    
    return cout_dni;
}
