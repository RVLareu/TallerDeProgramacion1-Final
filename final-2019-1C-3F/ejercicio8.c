/*
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de
la forma [nnn+nn+….+nnnn] (numeros separados por +, encerrados entre corchetes) e imprima el resultado
de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“[]”) debe cerrarse ordenadamente.
No considere errores.
*/

// hice un cliente

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>

#define MAX_DIGIT_NUMBER 10

int main(int argc, char* argv[]){
    char* port = "8080";
    char* host = "localhost";
    struct addrinfo hints;
    struct addrinfo *ptr, *result;

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(host, port, &hints, &result);

    int skt = -1;

    for(ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        skt = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (skt != -1) {
            connect(skt, ptr->ai_addr, ptr->ai_addrlen);
            break;
        }
    }
    freeaddrinfo(result);
    if(!ptr) {
        return -1;
    }

    char c;
    int partial_sum = 0;
    char number[MAX_DIGIT_NUMBER];
    memset(number, '\0',MAX_DIGIT_NUMBER);
    int number_idx = 0;
    int numbers_rec = 0;
    while(1) {
        if (recv(skt, &c, sizeof(c), 0) <= 0) {
            break;
        }
        if (c == '[') {
            continue;
        } else if (c == ']') {
            if (numbers_rec == 0) {
                break;
            }
            partial_sum += atoi(number);
            number_idx = 0;
            numbers_rec = 0;
            printf("%d", partial_sum);
        } else if (c == '+') {
            partial_sum += atoi(number);
            memset(number, '\0',MAX_DIGIT_NUMBER);
            number_idx = 0;
        } else {
            number[number_idx] = c;
            numbers_rec += 1;
            number_idx += 1;
        }
    }
    shutdown(skt, SHUT_RDWR);
    close(skt);

    return 0;

}