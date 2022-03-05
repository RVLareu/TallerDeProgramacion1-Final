/*
Escriba una función ISO C llamada Replicar que reciba 1 cadena (S), dos índices (I1 e I2) y una cantidad (Q).
La función debe retornar una copia de S salvo los caracteres que se encuentran entre los índices I1 e I2 que
serán duplicados Q veces. Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replicar(char* S, int I1, int I2, int Q) {
    // Faltaria chequear los largos tengan sentido

    int len_rep = I2 - I1 + 1;
    int len_total_rep = len_rep * Q;
    int len_total = strlen(S) - len_rep + len_total_rep;
    char* s_rep = (char*) malloc(sizeof(char) * len_total + 1);

    memcpy(&s_rep[0], &S[0], I1);

    for (int q = 0; q < Q; q++) {
        for(int i = I1; i < I2+1; i++) {
            s_rep[i + (q * len_rep)] =S[i];
        }
    }
    if (strlen(S) > I2) {
        memcpy(&s_rep[I1 + Q * len_rep], &S[I2 + 1], strlen(S) - I2);
    }

    return s_rep;    
}


int main(int argc, char* argv[]) {
    char* s = replicar("Hola", 2, 3, 4);
    printf("Fin: %s", s);
    return 0;
}