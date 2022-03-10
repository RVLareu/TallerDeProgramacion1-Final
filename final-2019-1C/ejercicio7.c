/*
Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe aceptar una única conexión e imprimir en stdout la sumatoria
de los enteros recibidos en cada paquete. Un paquete está definido como una
sucesión de números recibidos como texto, en decimal, separados por comas y terminado
con un signo igual (ej: “27,12,32=”). Al recibir el texto ‘FIN’ debe finalizar el programa
ordenadamente liberando los recursos.
*/
#include <stdio.h>

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        return -1;
    }
    char* port = argv[1];
    char* host = argv[2];

    struct addrinfo hints;
    struct addringo *result, *ptr;

    memset(&hints, 0, sizeof(struct addrinfo));


    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if (getaddrinfo(host, port, &hints, &result) < 0) { // host podria ser NULL para server
        return -1;
    }

    int skt = -1;
    for(ptr = result; ptr != NULL, ptr = ptr->ai_next) {
        skt = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if(skt != -1) {
            break;
        }
    }
    if (!ptr) {
        return -1;
    }

    bind(skt, ptr->ai_addr, ptr->ai_addrlen);
    listen(skt, 1); // 1 seria conexiones en cola

    int peer_skt = accept(skt, NULL, NULL);

    char value_read = '\0';
    char number[10]; // max 10 digits
    int partial_sum = 0;

    while(true) {
        if (recv(peer_skt, &value_read, sizeof(char), 0) < 0) {
            break;
        }

        if (value_read == 'F') {
            // hace falta recibir I y N
            break;
        } else if (value_read == '=' || value_read == ',') {
            partial_sum += atoi(number);
            memset(number, '\0', 10); // 10 digits, reinicio el bufer
            number_idx = 0; // reinicio el index del buffer
        } else {
            number[number_idx] = value_read;
            number_idx += 1;
        }
        
    }

    shutdown(peer_skt, SHUT_RDWR);
    shutdown(skt, SHUT_RDWR);
    close(skt);
    close(peer_skt);
    freeadrinfo(ptr);
    
    return 0;
}