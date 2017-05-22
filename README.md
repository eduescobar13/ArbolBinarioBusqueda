# ESIT ULL Grado de Informática
## ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS. Desarrollo e implementación un árbol binario de búsqueda en C++.
#### Realizada por Eduardo Escobar Alberto.

Plantillas en C++ de clases para el nodo binario de búsqueda (nodoBB<Clase>) y para el tipo abstracto de dato árbol binario de búsqueda (ABB<Clave>), implementando las operaciones de búsqueda, inserción y eliminación de una clave X. Se utilizan como valores de clave el tipo DNI.

##### MODO DEMOSTRACIÓN
El programa crea un árbol binario de búsqueda vacío, y presenta un menú con las siguientes opciones:
* **[0] Salir**
* **[1] Insertar clave**
* **[2] Eliminar clave**

Tras cada operación se mostrará el árbol resultante mediante un recorrido por niveles. En cada nivel se muestran los nodos de izquierda a derecha. El subárbol vacío se visualiza con [.]. En este modo se trabajará con árboles de tamaño limitado para permitir una correcta visualización.

##### MODO ESTADÍSTICO
El programa cuenta el número de comparaciones necesarias para buscar e insertar claves en el árbol. Inicialmente solicita los parámetros del experimento:
* **N (int):** Tamaño del árbol (número de nodos del árbol).
* **P (int): Número de pruebas.**

Se crea un banco de pruebas con valores de clave tipo DNI generados aleatoriamente. Se genera un árbol binario de búsqueda, ABB, y se insertan N claves extraídas del banco de pruebas sin repetir los valores de clave insertados.
Se inicializan los contadores para medir los valores mínimo, medio y máximo de comparaciones de claves al realizar las P búsquedas de valores de claves ya introducidas. A continuación, se repite la medición anterior al realizar P búsquedas de claves que no fueron previamente introducidas en el árbol.
Al analizar el experimento se presentarán por pantalla los datos de entrada y los resultados de ambos experimentos.