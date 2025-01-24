Un grafo es conexo si existe un camino entre cualquier par de nodos.

Las partes conectadas de un grafo se llaman componentes.

Un árbol es un grafo conexo que consta de n nodos y n − 1 aristas. En un árbol, existe un único camino entre cualquier par de nodos.

Dirección de las aristas
Un grafo es dirigido si las aristas solo pueden recorrerse en una dirección.

Pesos de las aristas
En un grafo ponderado, a cada arista se le asigna un peso. Los pesos suelen interpretarse como las longitudes de las aristas.

Vecinos y grados
Dos nodos son vecinos o adyacentes si existe una arista entre ellos. El grado de un nodo es el número de sus vecinos.

Coloreado de grafos
En un coloreado de un grafo, a cada nodo se le asigna un color de manera que no haya nodos adyacentes con el mismo color.
Un grafo es bipartito si es posible colorearlo utilizando dos colores. Resulta que un grafo es bipartito exactamente cuando no contiene un ciclo con un número impar de aristas.

Simplicidad
Un grafo es simple si ninguna arista comienza y termina en el mismo nodo, y no hay aristas múltiples entre dos nodos. A menudo, asumimos que los grafos son simples.

Representación de grafos
Existen varias formas de representar los grafos en los algoritmos. La elección de la estructura de datos depende del tamaño del grafo y de la forma en que el algoritmo lo procesa. A continuación, repasaremos tres representaciones comunes.

Representación por lista de adyacencia
En la representación por lista de adyacencia, a cada nodo x del grafo se le asigna una lista de adyacencia que consiste en los nodos a los cuales hay una arista desde x. Las listas de adyacencia son la forma más popular de representar grafos, y la mayoría de los algoritmos se pueden implementar de manera eficiente utilizando este enfoque.

Una forma conveniente de almacenar las listas de adyacencia es declarar un arreglo de vectores como sigue:
lo vamos a ver en el archivo: adjacency.cpp


Si el grafo es no dirigido, se puede almacenar de manera similar, pero cada arista se agrega en ambas direcciones.

Para un grafo ponderado, la estructura se puede extender de la siguiente manera:

En este caso, la lista de adyacencia del nodo a contiene el par (b, w) siempre que haya una arista desde el nodo a hacia el nodo b con peso w.

El beneficio de utilizar listas de adyacencia es que podemos encontrar de manera eficiente los nodos a los cuales podemos movernos desde un nodo dado a través de una arista.

Por ejemplo, el siguiente bucle recorre todos los nodos a los cuales podemos movernos desde el nodo s:

for (auto u: adj[s]){
    process node u
}

