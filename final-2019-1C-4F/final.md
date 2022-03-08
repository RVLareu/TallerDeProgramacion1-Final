# Taller - 2019 - 1C - 4F


## Ejercicio 1

¿Qué es una macro de C? Enumere buenas prácticas para su definición.

<details>
<summary> Respuesta </summary>

Una macro en C permite ponerle nombre a una porción de código. Durante el preprocesamiento (primera etapa en la trasnformación del código fuente al ejecutable final), se expandiran estas secciones donde sea que se invoquen (se realiza un find and replace). Como buena práctica fundamental hay que indicar que los parámetros deben estar entre paréntesis para evitar resultados inesperados. 
Por ejemplo:
  
```c

#define CUADRADO(x) (x)*(x)
  
#define CUADRADONT(x) x*x
  

CUADRADO(2+1); // (2+1)*(2+1) = 9
  
CUADRADONT(2+1); // 2+1*2+1 = 5
  
```

</details>

## Ejercicio 2

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y
las tareas desarrolladas en cada una de ellas.


<details>
<summary> Respuesta </summary>
Este proceso consiste de 3 etapas:
  
1. Precompilación: en esta primera etapa se resuelven todas aquellas lineas que comiencen con #. En esta etapa van a ingresar .h y .c, saliendo archivos .c puros. De esta manera se resolverán los define, quitarán los comentarios, incluirán las librerias, etc. En esta etapa puede haber errores por includes incorrectos, malas definiciones de macros, etc.
  
2. Compilacion: entran .c (uno o varios) y salen .o y/o .lib. En esta etapa se transforma el codigo fuente en objeto. Se verifica que la sintaxis sea correcta, que los llamados a funciones también los sean, las asignaciones estén bien realizadas. El resultado como dijimos anteriormente pueden ser varios modulos objeto. Los errores pueden ser de sintaxis o en los llamados a funciones.
  
3. Link edición: esta etapa recibe .o y .lib, saliendo .exe. Los modulos objeto pueden traer llamados a funciones dentro del mismo o por fuera. En esta etapa se resuelven los llamados cruzados de funciones hasta generar el código ejecutable. Los errores van a estar asociados a esto, como funciones con el mismo nombre, funciones que no existen, inclusiones cíclicas, etc.

</details>

## Ejercicio 3
Explique breve y concretamente qué es f:
`char (*f) (int *, char[3]);`


<details>
<summary> Respuesta </summary>

f es un puntero a función que recibe un puntero a entero y un arreglo de 3 char, devolviendo un char.

</details>

## Ejercicio 4

Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí
mismo, eliminando los número múltiplos de 7.


<details>
<summary> Respuesta </summary>


</details>


## Ejercicio 5

Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos
y devuelva una nueva lista duplicando los elementos de la primera si están en la segunda:
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);


<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 6

Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe
aceptar una unica conexión e imprimir en stdout todo lo recibido. Al recibir el texto ‘FIN’ debe
finalizar el programa sin imprimir dicho texto.


<details>
<summary> Respuesta </summary>


</details>

## Ejercicio 7

Escriba el .H de una biblioteca de funciones ISO C para números complejos. Incluya, al
menos, 4 funciones.


<details>
<summary> Respuesta </summary>
  
```c
  
#ifndef __COMPLEJOS_H__
#define __COMPLEJOS_H__
  

typedef struct complejo complejos_t;
  
  
float en_grados(complejo_t complejo);
  
int get_parte_real(const complejo_t complejo);

int get_parte_imaginaria(const complejo_t complejo);

complejo_t sumar_complejos(complejo_t c1, complejo_t c2);

complejo_t restar_complejos(complejo_t c1, complejo_t c2);
  
float modulo(complejo_t complejo);
  
#endif

```
</details>

## Ejercicio 8

Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su
comportamiento y el area de memoria donde residen:

1. Una variable global static

2. Una variable local static

3. Un atributo de clase static.

<details>
<summary> Respuesta </summary>

1. Al ser static sólo podrá ser accedida desde el módulo donde fue declarada. Su vida es la del archivo. Reside en el datasegment. En caso de no ser definida, su valor es *NULL*
2. Al ser local static solo podrá ser accedida desde la función donde fue declarada. Su vida es la de la función
3. Si es privado, solo es visible desde la clase. En caso de ser público, su valor será visible desde fuera de la misma (`clase.atributo`). Reside en el datasegment. En caso de no ser inicializada, será *NULL*.
</details>

## Ejercicio 9

¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin
que se generen problemas de consistencia? Ejemplifique.


<details>
<summary> Respuesta </summary>
Para evitar esto se utiliza un mutex. Cuando un hilo lo toma, el otro debe esperar a que lo libere para poder al recurso protegido por este. De esta manera, una acción que tal vez conlleve un par de instrucciones se vuelve atómica por así decirlo. En caso de que sean 2 lectores no haría falta lockear nada.

Un ejemplo podría ser el de un contador compartido. Al lanzar los hilos, cada uno hará lock, incrementará en 1 y unlockeará. Al hacer el join siempre el contador estara en 2. Esto será consistente en todas las ejecuciones.
Si no se protegiera el recurso, los resultados podrían ser inesperados. El hilo 1 lee el contador en 0 y antes de incrementarlo, el hilo 2 lo interrumpe y lee también en 0 el contador. Luego retoma el hilo 1 y como estaba en 0, lo dejará en 1. Finalmente el hilo 2 retoma su ejecución, el contador estaba en 0 por lo que le suma 1 y ahora el contador está en 1. Al joinear el contador estará en 1.
También podría ocurrir que la ejecución sea correcta y el contador finalice en 2. De esta manera no habria consistencia entre corridas.
Misma situación podria haberse dado si en vez de no estar protegido, cada hilo usara un mutex distinto.
  
  
```

int main() {
  
  int contador = 0;
  // lanzo hilos
  mutex.lock();
  contador += 1;
  mutex.unlock();
  // joineo hilos
  printf("%d", contador);
  return 0;
}
```
</details>

## Ejercicio 10

Indique la salida del siguiente programa:
```
class A { A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }
int main () { B b; return 0;}
```


<details>
<summary> Respuesta </summary>

  A()B()~B()~A()

</details>
