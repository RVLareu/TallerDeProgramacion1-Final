/*
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente.
Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos 
por un hilo mientras que los impares sean escritos por otro. Contemple la correcta sincronización 
entre hilos y la liberación de los recursos utilizados.
*/

#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

int contador = 1;
std::condition_variable c;
std::mutex m;

void contar(std::string cuenta) {
    while(contador < 100) {
        std::unique_lock<std::mutex> lk(m);
        c.wait(lk, [&](){return contador%2 == 0;});
        std::cout << contador++ << std::endl;
        lk.unlock();
        c.notify_all();
    }
}


int main(int argc, char* argv[]) {
    std::thread par(contar, "pares");
    std::thread impar(contar, "impares");
    impar.join();
    par.join();
    return 0;
} 