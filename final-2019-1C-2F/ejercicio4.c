/*
Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria).
El procesamiento consiste en leer grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos decimales 
(que representen el mismo número leído pero en decimal).
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    fp = fopen("numeros.txt", "r+");
}