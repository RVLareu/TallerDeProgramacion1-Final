/*
Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A
después de haber duplicado todas las ocurrencias de B.
Por ej.: reemp.exe “Este es el final” final -----> Este es el final final
*/

// char *strtok_r(char *str, const char *delim, char **saveptr);

#define CANT_PARAMETROS 3

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != CANT_PARAMETROS) {
        return 1;
    }
    char* cadena = argv[1];
    char* ocurrencia = argv[2];
    char* save_ptr;
    char* token = __strtok_r(cadena, " ", &save_ptr);
    while (token != NULL) {
        printf("%s ", token);
        if (strcmp(token, ocurrencia) == 0) {
            printf("%s ", token);
        }
        token = __strtok_r(NULL, " ", &save_ptr);
    }
    return 0;
}   