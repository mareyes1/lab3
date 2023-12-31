# Laboratorio 3
Introducción a programación en C

## Parte 1. Arreglos y recursividad

### A. Función de búsqueda lineal
Se define una función llamada `busqueda lineal` la cual retorna un entero correspondiente al índice del arreglo de la posición donde se encuentra el valor ingresado por el usuario, en caso de encontrarlo. Esta función recibe el arreglo ordenado de enteros dado, la cantidad de elementos del arreglo y el valor ingresado por el usuario.

Dentro de la función se hace un `for` *loop* desde 0 hasta la cantidad de elementos menos 1, para hacer un barrido secuencial de cada uno de los elementos del arreglo hasta encontrar el valor buscado. Para esto, dentro del `for` se hace un `if` que evalúa la condición de si el elemento del arreglo correspondiente al número de iteración del `for` es igual al valor definido por el usuario y pasado a la función; en caso de que se cumpla la condición, la función retorna directamente el índice de iteración en el que se encuentra el `for` *loop*, correspondiente a la posición del arreglo que contiene el valor buscado.

Si el valor no es encontrado en ninguna de las iteraciones del `for` mediante la evaluación de la condición de igualdad, al terminar el bucle la función efectúa un `return -1` como código de error, el cual será interpretado por la función `main` para imprimir el mensaje de error correspondiente.

### B. Función de búsqueda binaria
El algoritmo de búsqueda binaria encuentra inicialmente el elemento medio del arreglo por medio de un sencillo cálculo aritmético a partir de las posiciones extremas, y compara ese valor con el valor buscado; si coincide, se retorna con el índice correspondiente, y si no, lo que se hace es determinar en cuál de las dos mitades a la derecha y a la izquierda del elemento medio se encuentra el valor buscado, tomando en cuenta que el arreglo está ordenado. Para esto, se compara el valor buscado con el elemento medio, si es mayor significa que debería estar en la mitad derecha del arreglo y si es menor en la mitad izquierda. Una vez determinado en cuál mitad estaría el valor, se redefinen los límites de búsqueda para que delimiten esa mitad.

Para implementar el algoritmo descrito anteriormente en la función `busqueda_binaria`, ésta debe recibir como parámetros el arreglo, el tamaño del arreglo y el valor ingresado por el usuario. A partir del tamaño del array, define los límites de búsqueda iniciales, los cuales estarían dados por `0` a la izquierda en el primer elemento y `size - 1` a la derecha en el último elemento. Una vez definidos los límites de búsqueda iniciales, se utiliza un *loop* `while` que se repite en tanto el límite derecho no sea menor que el izquierdo. Dentro del `while`, se determina el elemento medio de la forma `int medio = limite_izquierdo + (limite_derecho - limite_izquierdo) / 2`. Por medio de un `if` se compara el contenido de `arreglo[medio]` con el valor ingresado por el usuario y si coinciden se retorna el índice `medio`. Si no coincide, se determina si el valor buscado es mayor o menor usando `else if` y `else`, y redefiniendo el límite izquierdo como el siguiente a la derecha de `medio` o el límite derecho como el anterior a la izquierda de `medio`, respectivamente según sea el caso. El bucle `while` continúa iterando con los nuevos límites que se van redefiniendo hasta encontrar coincidencia o que su condición se deje de cumplir, en cuyo caso finaliza y retorna el código de error.

### C. Función de búsqueda binaria recursiva
En este caso se utiliza el mismo algoritmo de búsqueda binaria descrito en el punto anterior, pero en lugar de usar un *loop* `while` para repetir la comparación, lo que se hace es efectuar llamadas recursivas de la función `busqueda_recursiva` a sí misma. Así, la función recibe como parámetros el arreglo, los límites iniciales y el valor ingresado por el usuario, y en lugar de repetir un bucle en tanto el límite izquierdo sea menor o igual que el derecho como en el caso anterior, evalúa esta misma condición en un `if` y si se cumple entonces determina el elemento medio y en otro `if` anidado lo compara con el valor ingresado por el usuario, retornando el índice correspondiente en caso de coincidir.

La principal diferencia con el caso de búsqueda binaria no recursiva se encuentra al manejar los casos cuando el valor no se encuentra y se debe modificar los límites para buscar en una de las mitades; en este caso en lugar de modificar varibles locales que contienen los límites para que el bucle `while` continúe repitiéndose con los nuevos límites que derminan un nuevo elemento medio, lo que se hace es llamar nuevamente a `busqueda_recursiva` con los límites modificados de acuerdo con la mitad siguiente en la que se debe buscar, sea la inferior o la superior. El resultado de esta llamada recursiva es lo que se retorna, por lo que la llamada se repetirá hasta que se encuentre coincidencia en los valores, o hasta que la condición del `if` de entrada deje de cumplirse, en cuyo caso el valor no ha sido encontrado y se retorna el código de error.

### Resultados
Las funciones descritas deben ser declaradas antes de su llamado en la `main` por medio de los prototipos de función, para que el compilador sepa que estas funciones están definidas más adelante y no se de un error de *"implicit declaration of function"*.

En la función `main` se define el arreglo, se calcula el tamaño de este por medio de `size of` y se captura el valor ingresado por el usuario por medio de un `scanf`. Luego de esto se va llamando a cada una de las funciones y se imprime en pantalla un mensaje según si el valor fue encontrado o no, especificando de cuál función proviene el resultado en cada caso.

#### Ejemplo de valor encontrado:

![valor_encontrado](https://raw.githubusercontent.com/mareyes1/lab3/main/valor_encontrado_parte1.png)

#### Ejemplo de valor no encontrado:

![valor_no_encontrado](https://raw.githubusercontent.com/mareyes1/lab3/main/valor_no_encontrado_parte1.png)

## Parte 2. Arreglos y punteros

### A. Función para encontrar mínimo
Se define la función `encontrarMin` que recibe el arreglo y el tamño. Dentro de ésta, se inicia una variable `min` con el valor del primer elemento del array, asumiendo como caso de partida que ese elemento es el mínimo. Seguidamente se efectúa un `for` *loop* que inicia en `1`, dado que el elemento `0` ya esta considerado en la condición inicial, y se repite hasta `size - 1`, incrementando `1` en cada iteración. Dentro del `for`, por medio de un `if` se compara si el elemento `arreglo[i]` de la iteración correspondiente es menor que el valor de la varible `min` inicialmente asignada con el primer elemento del arreglo; si ese es el caso, el valor del mínimo se actualiza de la forma `min = arreglo[i]`. Una vez que finaliza el `for` *loop*, se retorna el valor final de la variable `min`.

### B. Función para encontrar máximo
Esta función `encontrarMax` se implementa de la misma forma que la anterior para el caso de encontrar el valor mínimo, con la única diferencia de que en el el `if` lo que se evalúa es si el elemento del arreglo de la iteración correspondiente del bucle `for` es mayor que una variable `max` previmente inicializada con el primer elemento del arreglo, la cual se actualiza según sea el caso en cada iteración.

### C. Función para encontrar mínimo y máximo usando punteros
Se define una función de tipo `void` pues ésta no debe retornar nada sino únicamente almacenar los valores mínimo y máximo en las variables correspondientes. Para esto, se declaran dos variables para mínimo y máximo en la función `main` desde la cual se llama `encontrarMinMax`, pasándole a esta última el arreglo, las direcciones de las variables de mínimo y máximo para que las pueda modificar, y el tamaño del arreglo. La función, entonces, recibe tres punteros, a saber: el puntero al arreglo y los dos punteros que apuntan a las direcciones de las variables del `main` en las que se almacenarán el mínimo y el máximo. Se desrreferencian los punteros a mínimo y máximo para inicializar el contenido de memoria al que apuntan con el valor del primer elemento del array en ambos casos, tal y como se hizo en las dos funciones anteriores.

La lógica de funcionamiento es igual que en el caso de las funciones anterior en cuanto a que se itera en un bucle `for` que barre el arreglo, dentro del cual por medio de un `if` y un `else if` se evalúa la condición de que el elemento correspondiente del arreglo sea menor o mayor, respectivamente, en comparación con los valores a los que apuntan los punteros de mínimo y máximo, obtenidos desrreferenciándolos. Si en alguno de los casos hay coincidencia, se actualizan los valores a los que apuntan esos punteros.

### Resultados
En este caso las funciones fueron definidas al inicio del código para mayor claridad, esto hace que no sea necesario declarar los function prototypes sin que el compilador de error de declaración implícita. Luego al final se define la función `main`, en la cual se define el arreglo, se calcula su tamaño con `sizeof` y se llama a cada una de las funciones. En el caso de las dos primeras funciones, se asigna directamente a una variable `minimo` o `maximo` el valor retornado por `encontrarMin` y `encontrarMax`, respectivamente. Para el caso de la función que utiliza punteros, en la `main` se declaran dos variables para que contengan el resultado y su dirección es la que se pasa `encontarMinMax`, la cual recibe esos punteros y modifica el contenido de las variables en memoria directamente sin retornar los valores como tal.

#### Ejemplo de captura:

![resultado_parte2](https://raw.githubusercontent.com/mareyes1/lab3/main/resultado_parte2.png)
