/*
Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos
y devuelva una nueva lista duplicando los elementos de la primera si están
en la segunda: std::list DobleSegunda(std::list a,std::list b);
*/
/*
Asumo que si la lista 1 tiene por ejemplo {2,2,3,4} y lista 2 es {2,4,5}; el resultado esperado sería {2,2,2,2,3,4,4} -->
--> dupliqué ambos 2, el 3 no pero igual lo incluyo por consigna y 4 duplicado
*/

#include <list>
#include <iostream>
#include <string>

template <class T>

std::list<T> DobleSegunda(std::list<T> l1, std::list<T> l2) {
    std::list<T> res_list;
    for(T& elem1:l1) {
        res_list.push_back(elem1);
        for(T& elem2:l2) {
            if (elem1 == elem2) {
                res_list.push_back(elem1);
                break;
            }
        }
    }
    return std::move(res_list); // de goloso nomás
}


int main(int argc, char* argv[]) {
    std::list<std::string> l1 = {"dale", "dale", "boca", "ponga", "huevo"};
    std::list<std::string> l2 = {"dale","huevo"};
    std::list<std::string> l3 = DobleSegunda(l1, l2);

    for(std::string& e:l3) {
        std::cout << e << std::endl;
    }
    return 0;
}

