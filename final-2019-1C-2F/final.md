# Taller - 2019 1C


## Ejercicio 1

Declare la clase Número para encapsular una cadena numérica larga. Incluya al menos:
Constructor(unsigned long), Constructor default y Constructor move; Operador <<, (), =, long y
++(int). Implemente el operador >>.

<details>
<summary> Respuesta </summary>


</details>


## Ejercicio 2

¿Qué significa que una función es bloqueante? ¿Cómo subsanaría esa limitación en término de
mantener el programa ‘vivo’ ?

<details>
<summary> Respuesta </summary>

Que una función sea bloqueante quiere decir que frena el flujo de ejecución hasta que suceda un cierto evento. Para evitar que esto ocurra se puede recurrir a la utilización de múltiples hilos: mientras uno aguarda un suceso en la función bloqueante, otro continúa con la ejecución del programa principal u otra tarea.
  
</details>

## Ejercicio 3

Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su
uso sea imprescindible.

<details>
<summary> Respuesta </summary>

Por defecto, C++ resuelve a qué metodo llamar en tiempo de compilacion (static linkage). Para que lo haga en tiempo de ejecución (dynamic linkage) hay que utilizar el modificador *virtual*: esto crea VTables (tabla de métodos virtuales) que sirven para tal fin pero empeoran la performance. Esto permite hacer uso del polimorfismo basado en herencia, donde los metodos de las clases hijas reemplazan a los de las clases padre.
Un escenario en el que su uso sería imprescindible sería si se tiene por ejemplo una clase abstracta figura (tiene un método virtual puro), y varias clases hijas del estilo cuadrado, círculo, triángulo, etc. En este caso, vamos a querer que los métodos definan dependiendo de la clase hija instanciada.

</details>

## Ejercicio 4

Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear
archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer
grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos
decimales (que representen el mismo número leído pero en decimal).

<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 5

Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.

<details>
<summary> Respuesta </summary>

Compilación condicional hace referencia a la compilación o no de una porcion de código en base al valor de constantes conocidas en tiempo de compilación. Al tener un '#' antepuesto, sabemos que se van a resolver en la etapa previa a la compilación, por lo que el compilador ni siquiera sabrá que allí había una porción de codigo. Por ejemplo, para evitar una inclusión cíclica puede plantearse lo siguiente:
  
  ```c
  
  #ifndef __CLASE_H__
  #define __CLASE_H__
  
  class H {
  ...
  
  }
  
  #endif
  
  ```
En este caso, si ya fue incluida la clase H, ya va a estar definido __CLASE_H__ por lo que no se compilará lo que se encuentre dentro del *ifndef* - *endif*
  
</details>

## Ejercicio 6

Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “Este es el final” final -----> Este es el final final

<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 7

Escriba las siguientes definiciones/declaraciones:
1. Definición de una la función SUMA, que tome dos enteros largos con signo y devuelva
su suma. Esta función sólo debe ser visible en el módulo donde se la define.
2. Declaración de un puntero a puntero a entero sin signo.
3. Definición de un caracter solamente visible en el módulo donde se define.

<details>
<summary> Respuesta </summary>

1.
  
  ```c
  static long int SUMA(long int a, long int b) {
     return (a + b);
  }
  ```
  
2.
  
  ```c
  
  unsigned int **a;
  
  ```
  
  3.
  
  ```c
  
  static char a = 'a';
  
  ```

</details>

## Ejercicio 8
¿Qué valor arroja sizeof(int)? Justifique .

<details>
<summary> Respuesta </summary>

`sizeof` arroja la cantidad de bytes del parámetro. Generalmente `sizeof(int) = 4` pero depende de la arquitectura y del compilador. Si nos quisieramos asegurar de esto, se podría usar `int32_t`
  
</details>

## Ejercicio 9
Describa el concepto de loop de eventos (events loop) utilizado en programación orientada
a eventos y, en particular, en entornos de interfaz gráfica (GUIs).

<details>
<summary> Respuesta </summary>

 El event loop es el encargado de leer los eventos de la cola y distribuir las tareas a los *handlers* correspondientes. Estos últimos son secciones de código que saben cómo responder a la aparicion de un evento. En entornos de interfaz gráfica, estos *handlers* deben ser compactos y rápidos. En general en este tipo de aplicaciones, el event loop corre en el hilo principal del programa

</details>

## Ejercicio 10
¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock?

<details>
<summary> Respuesta </summary>
La principal ventaja es que al salir de scope libera siempre al mutex, esto porque al ser RAII invocará a su destructor en ese momento liberando los recursos adquiridos sin hacerlo de manera explicita. Además al instanciarse en el stack, sus constructores adquieren los recursos automáticamente. De esta manera disminuimos riesgos (como olvidarse de liberarlo), se hace un programa mas robusto a errores y queda un código más simple.

</details>
