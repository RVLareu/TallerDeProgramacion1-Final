# Taller - 2019 1C

## Ejercicio 1

Declare una clase a elección considerando:
- Atributos que son necesarios
- Accesibilidad a la Clase
- Incluir los operadores +, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), long

<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 2

¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.


<details>
<summary> Respuesta </summary>

Un functor es un objeto que tiene sobrecargado el operador *()*. De esta manera, puede actuar como lo haría una función.
A diferencia de una función convencional, permite hacer en dos momentos distintos o desacoplar el momento en que se realiza el pasaje de parámetros y en que comienza la ejecución de la función.

```c

// functor
class incrementador {
    private:
        int num;
    public:
        incrementar(int n) : num(n) {}
    
        int operator () (int arr_num) const {
            return num + arr_num
        }
};
    
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    
  
    for (int i: numbers)
        incrementador(i);
}
    
```
</details>

## Ejercicio 3

Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden
ascendente. Se pide que los números sean contabilizados por una variable global única y que
los pares sean escritos por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.

<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 4

Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de
inicialización, su comportamiento y el area de memoria donde residen:
```C
static int a;
int b(){
    static int c; char d=65;
    return c+(int) d;
}
```

<details>
<summary> Respuesta </summary>

`static int a` es la declaración de un entero de alcance local (solo se la puede accerder desde donde fue declarada). No posee ningún valor ya que al ser una declaración no se reserva memoria para la misma. Por esta misma razón no reside en ningún segmento de memoria
</br>
`int b()` es la definición de una función que no recibe ningún parámetro y devuelvo un entero. El área de memoria donde reside es el datasegment
</br>
`static int c` es la **definición** de un entero de alcance local (la función en este caso). Su lifetime es global. No se encuentra inicializada. Declaración sería si fuera extern, ua que no sabes donde se aloja.
</br>
`char d=65` es la definicion de un char con el valor correspondiente al 65 en la tabla *ascii*. Al ser una variable local, esta reside en el stack y es liberada al salir de la ejecución  de la función `b()`
</br>

    
</details>

## Ejercicio 5

Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..

<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 6

¿Por qué las librerías que usan Templates se publican con todo el código fuente y no como
un .h y .o/.obj?.

<details>
<summary> Respuesta </summary>

Los templates permiten realizar generalizaciones, generando código de acuerdo al tipo de dato que se indique. Es por esto que debe ser conocido en tiempo de compilación, para que luego de acuerdo al tipo de dato se genere el código objeto (.O) correspondiente. De esta manera se generará el mismo código tantas veces como tipos de datos sean necesarios/especializados.

</details>

## Ejercicio 7

¿Qué características debe tener un compilador C para ser considerado “portable”?

<details>
<summary> Respuesta </summary>

Para que un compilador C sea portable debe:
* Respetar sintaxis
* Proveer conjunto de librerías estandar (stdlib, stdio, etc)
* Respetar un procesos de transformacion de código desde el fuente hasta el ejecutable final
    

</details>

## Ejercicio 8

Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba
paquetes de la forma [nnn+nn+….+nnnn] (numeros separados por +, encerrados entre
corchetes) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un
paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.

<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 9

Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1
por línea) sobre sí mismo, sin generar archivos intermedios ni cargar el archivo completo a
memoria. El procesamiento consiste en eliminar las palabras de más de 3 letras de cada línea.

 <details>
<summary> Respuesta </summary>


</details>

## Ejercicio 10

¿Qué diferencia existe entre un constructor por copia y uno por movimiento?
Ejemplifique.

<details>
<summary> Respuesta </summary>

En C++ todos los objetos son copiables por default, de esta manera al realizar un pasaje de objetos por copia se estarán duplicando bit a bit de manera naive. Un potencial problema es si el objeto original posee un puntero, el objeto destino copiará el puntero por lo que si el original libero el contenido, el puntero del objeto destino no será válido. En el caso de realizarlo por movimiento, el objeto fuente ya no es dueño del recurso: se cambia el ownership. Igualmente el objeto fuente debe seguir siendo válido. Volviendo al caso del puntero, para quitarle el ownership al objeto origen habria que por ejemplo hacer que apunte a null: `ptr = nullptr`

</details>
