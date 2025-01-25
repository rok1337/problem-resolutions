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