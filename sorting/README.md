Algoritmos **O(n log n)**  
Es posible ordenar un arreglo de manera eficiente en **O(n log n)** utilizando algoritmos que no están limitados a intercambiar elementos consecutivos. Uno de esos algoritmos es **merge sort**, que se basa en recursión.

**Merge sort** ordena un subarreglo `array[a ... b]` de la siguiente manera:

1. Si **a = b**, no se hace nada, porque el subarreglo ya está ordenado.
2. Calcula la posición del elemento medio: **k = ⌊(a + b) / 2⌋**.
3. Ordena recursivamente el subarreglo `array[a ... k]`.
4. Ordena recursivamente el subarreglo `array[k + 1 ... b]`.
5. Fusiona los subarreglos ordenados `array[a ... k]` y `array[k + 1 ... b]` en un subarreglo ordenado `array[a ... b]`.

Merge sort es un algoritmo eficiente porque reduce a la mitad el tamaño del subarreglo en cada paso. La recursión consta de O(log n) niveles, y procesar cada nivel toma O(n) tiempo. Fusionar los subarreglos array[a ... k] y array[k + 1 ... b] es posible en tiempo lineal, porque ya están ordenados.

**Límite inferior de la ordenación**  
¿Es posible ordenar un arreglo más rápido que en **O(n log n)**? Resulta que no es posible cuando nos restringimos a algoritmos de ordenación basados en la comparación de elementos del arreglo.  

El límite inferior para la complejidad temporal se puede probar considerando la ordenación como un proceso en el que cada comparación de dos elementos proporciona más información sobre el contenido del arreglo. Este proceso crea el siguiente árbol...

**Operadores de comparación**  
La función `sort` requiere que se defina un operador de comparación para el tipo de datos de los elementos que se van a ordenar. Durante la ordenación, este operador será utilizado siempre que sea necesario determinar el orden entre dos elementos.  

La mayoría de los tipos de datos en C++ tienen un operador de comparación integrado, y los elementos de esos tipos pueden ordenarse automáticamente. Por ejemplo:  
- Los números se ordenan según sus valores.  
- Las cadenas (strings) se ordenan en orden alfabético.  

Las parejas (tipo `pair`) se ordenan principalmente según sus primeros elementos (`first`). Sin embargo, si los primeros elementos de dos parejas son iguales, se ordenan según sus segundos elementos (`second`):


Después de esto, el orden de las parejas es **(1, 2)**, **(1, 5)** y **(2, 3)**.  

De manera similar, las tuplas (`tuple`) se ordenan principalmente por el primer elemento, secundariamente por el segundo elemento, y así sucesivamente.

**Estructuras definidas por el usuario**  
Las estructuras definidas por el usuario no tienen un operador de comparación definido automáticamente. Este operador debe ser definido dentro de la estructura como una función `operator<`, cuyo parámetro es otro elemento del mismo tipo. La función debe devolver `true` si el elemento es menor que el parámetro, y `false` en caso contrario.  

Por ejemplo, la siguiente estructura `P` contiene las coordenadas `x` e `y` de un punto. El operador de comparación está definido para que los puntos se ordenen principalmente según el:

**coordenada x** y, secundariamente, según la **coordenada y**.
 struct P {
        int x, y;
        bool operator<(const P &p) {
            if (x != p.x) return x < p.x;
            else return y < p.y;
        }
    };

**Funciones de comparación**  
También es posible proporcionar una función de comparación externa a la función `sort` como una función de callback. Por ejemplo, la siguiente función de comparación `comp` ordena cadenas principalmente por longitud y, secundariamente, por orden alfabético:

bool comp(string a, string b) {
if (a.size() != b.size()) return a.size() < b.size();
return a < b;
}

Ahora, un vector de cadenas se puede ordenar de la siguiente manera:
sort(v.begin(), v.end(), comp);

BINARY SEARCH: 
La complejidad temporal de este enfoque es O(n), porque, en el peor de los casos, es necesario verificar todos los elementos del arreglo. Si el orden de los elementos es arbitrario, este también es el mejor enfoque posible, ya que no hay información adicional disponible sobre dónde en el arreglo deberíamos buscar el elemento `x`.  

Sin embargo, si el arreglo está ordenado, la situación es diferente. En este caso, es posible realizar la búsqueda mucho más rápido, ya que el orden de los elementos en el arreglo guía la búsqueda. El siguiente algoritmo de búsqueda binaria busca de manera eficiente un elemento en un arreglo ordenado en un tiempo de O(log n).

**Método 1**  
La forma habitual de implementar la búsqueda binaria se asemeja a buscar una palabra en un diccionario. La búsqueda mantiene una región activa en el arreglo, que inicialmente contiene todos los elementos del arreglo. Luego, se realizan varios pasos, cada uno de los cuales reduce a la mitad el tamaño de la región.  

En cada paso, la búsqueda verifica el elemento del medio de la región activa. Si el elemento del medio es el elemento objetivo, la búsqueda termina. De lo contrario, la búsqueda continúa recursivamente en la mitad izquierda o derecha de la región, dependiendo del valor del elemento del medio.  

La idea anterior se puede implementar de la siguiente manera:  

En esta implementación, la región activa es de `a . . . b`, y, al principio, la región es `0 . . . n − 1`. El algoritmo reduce a la mitad el tamaño de la región en cada paso, por lo que la complejidad temporal es O(log n).

**Método 2**  
Un método alternativo para implementar la búsqueda binaria se basa en una forma eficiente de iterar a través de los elementos del arreglo. La idea es realizar saltos y reducir la velocidad a medida que nos acercamos al elemento objetivo.  

La búsqueda recorre el arreglo de izquierda a derecha, y la longitud inicial del salto es `n/2`. En cada paso, la longitud del salto se reduce a la mitad: primero `n/4`, luego `n/8`, `n/16`, etc., hasta que finalmente la longitud sea 1. Después de los saltos, o bien se encuentra el elemento objetivo, o sabemos que no aparece en el arreglo.  

El siguiente código implementa la idea anterior: 

Durante la búsqueda, la variable `b` contiene la longitud actual del salto. La complejidad temporal del algoritmo es O(log n), porque el código dentro del bucle `while` se ejecuta, como máximo, dos veces para cada longitud de salto.

**Funciones en C++**  
La biblioteca estándar de C++ contiene las siguientes funciones basadas en la búsqueda binaria, las cuales operan en tiempo logarítmico:  

- `lower_bound` devuelve un puntero al primer elemento del arreglo cuyo valor es al menos `x`.  
- `upper_bound` devuelve un puntero al primer elemento del arreglo cuyo valor es mayor que `x`.  
- `equal_range` devuelve ambos punteros mencionados anteriormente.  

Las funciones asumen que el arreglo está ordenado. Si no existe tal elemento, el puntero apunta al elemento que se encuentra después del último elemento del arreglo. Por ejemplo, el siguiente código determina si un arreglo contiene un elemento con el valor `x`: 

auto k = lower_bound(array,array+n,x)-array;
if (k < n && array[k] == x) {
// x found at index k
}
Luego, el siguiente código cuenta el número de elementos cuyo valor es `x`:
auto a = lower_bound(array, array+n, x);
auto b = upper_bound(array, array+n, x);
cout << b-a << "\n";

Usando `equal_range`, el código se vuelve más corto:

auto r = equal_range(array, array+n, x);
cout << r.second-r.first << "\n";

**Encontrar la solución más pequeña**  
Un uso importante de la búsqueda binaria es encontrar la posición donde el valor de una función cambia. Supongamos que deseamos encontrar el valor más pequeño `k` que sea una solución válida para un problema. Se nos da una función `ok(x)` que devuelve `true` si `x` es una solución válida y `false` en caso contrario. Además, sabemos que `ok(x)` es `false` cuando `x < k` y `true` cuando `x ≥ k`. La situación es la siguiente: