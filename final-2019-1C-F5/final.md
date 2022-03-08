# Taller - 2019 - 1C - F5


## Ejercicio 1

Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un triángulo
amarillo del tamaño de la ventana.

<details>
<summary> Respuesta</summary>


</details>

## Ejercicio 2

Escriba las siguientes definiciones/declaraciones:

1. Declaración de un puntero a puntero a entero largo con signo.
2. Definición de una la función RESTA, que tome dos enteros largos con signo y devuelva
su resta. Esta función debe ser visible en todos los módulos del programa.
3. Definición de un caracter solamente visible en el módulo donde se define.

<details>
<summary> Respuesta</summary>

1. `long int** a;`
2. `long int RESTA(long int a, long int b) {return (a-b);}`
3. `static char a = 'a';`

</details>


## Ejercicio 3

Declare la clase TELEFONO para encapsular una cadena numérica correspondiente a un
teléfono. Incluya al menos: Constructor(area, numero), Constructor move y Constructor de
Copia; Operador <<, ==, =, long y >>. Implemente el operador >>.

<details>
<summary> Respuesta</summary>


</details>

## Ejercicio 4

Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.

<details>
<summary> Respuesta</summary>

La compilación condicional hacer referencia al hecho de poder compilar o no una sección de código de acuerdo a una evaluación realizada en la etapa de precompilación. Por ejemplo, para evitar inclusiones cíclicas se puede realizar lo siguiente:
  
```c
  
#ifndef __CLASE_H__
#define __CLASE_H__
  
class H {
...
};
  
#endif
  
```

De esta manera, si no está definida __CLASE_H__, la define. De lo contrario, no hace nada de lo que se encuentre previo al *endif*
  
</details>

## Ejercicio 5

¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de
mantener el programa ‘vivo’ ?

<details>
<summary> Respuesta</summary>

Una función es blocante si detiene el flujo del programa a la espera de un suceso o resultado. Para evitar que esto ocurra y que puedo continuar el flujo mientras se espera, se recurre a la programación multihilo. Mientras un hilo aguarde por un evento, el otro continúa con el flujo del programa.
  
</details>


## Ejercicio 6

Explique qué son los métodos virtuales puros y para qué sirven. De un breve ejemplo
donde su uso sea imprescindible.

<details>
<summary> Respuesta</summary>

Un método virtual puro es aquel que se declara para tal fin:

```c

Foo foo() = 0;

```
Este método es abstracto y las clases que deriven de la que lo posea **deben** definirlo. Esto permite aplicar polimorfismo. Su uso es imprescindible cuando se quiere definir una clase que actúe de interfaz. En este caso todos los métodos debes ser virtuales puros.

</details>


## Ejercicio 7

Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear
archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer nros
hexadecimales de 4 símbolos y reemplazarlos por su valor decimal (en texto).

<details>
<summary> Respuesta</summary>


</details>


## Ejercicio 8

¿Qué es el polimorfismo? Ejemplifique mediante código.

<details>
<summary> Respuesta</summary>


</details>


## Ejercicio 9

¿Qué función utiliza para esperar la terminación de un thread? Ejemplifique mediante
código.

<details>
<summary> Respuesta</summary>


</details>


## Ejercicio 10

Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B.
ej.: reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado

<details>
<summary> Respuesta</summary>


</details>
