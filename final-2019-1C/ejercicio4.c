/*
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo procese sobre
sí mismo (sin crear archivos intermedios ni subiendo todo su contenido a memoria). El procesamiento 
consiste en eliminar las líneas de 1 sola palabra.
RTA de leobellaera
*/

#include <stdio.h> // para file

#define MAX_LINE 1024

int main(int argc, char* argv[]) {
    FILE *file = fopen(argv[1], "r+");
    if (!file) {
        return 1;
    }


    long int read_seek = 0;
    long int write_seek = 0;

    // line será una linea llena de \0
    char line[MAX_LINE];
    memset(line, '\0', MAX_LINE)
    size_t line_idx = 0;

    char c = '\0';
    size_t bytes_written = 0;

    while((c = read_char(file, &read_seek)))



    fclose(fptr);
    return 0;
}