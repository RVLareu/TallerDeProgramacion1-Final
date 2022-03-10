/*
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo procese sobre
sí mismo (sin crear archivos intermedios ni subiendo todo su contenido a memoria). El procesamiento 
consiste en eliminar las líneas de 1 sola palabra.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 3

int main (int argc, char* argv[]) {
    FILE *fp;
    int c;
    char line[MAX_LINE];
    memset(line, '\0',MAX_LINE);

    fp = fopen(argv[1],"r+");
    if(fp == NULL) {
        perror("Error in opening file");
        return(-1);  
    }
    long int read_seek = 0;
    long int write_seek = 0;


    while(1) {
        c = fgetc(fp);
        if(feof(fp)) {
            break;
        }

        if (c == '\n') {
            for (int i = 0; i < strlen(line); i++) {
                if(line[i] == ' ') {

                    fseek(fp, write_seek, SEEK_SET);
                    memset(line, '\0',MAX_LINE);
                    fputs(line, fp);
                    break;
                }
            }
            read_seek += 1;
            write_seek += read_seek;
            
        } else {
            line[read_seek] = c;
            read_seek += 1;
        }
    }
    fclose(fp);
    return(0);
}