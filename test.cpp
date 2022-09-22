#include <cstdio>
#include <iostream>
#include "MyArray.h"
#include "hooks.h"

//Instrument malloc et al hooks (works if using glibc)

int main() {
    init_hook();

    MyArray a{10};   
    //Let's add 3 numbers
    a.append(2);
    a.print();
    a.append(3);
    a.print();
    auto ind = a.append(3);
    std::cout << "Next index:" << ind << std::endl;
    a.print();
    std::cout << "Curr size: " << a.size() << std::endl;
    ind = a.append(3);
    ind = a.append(3);
    ind = a.append(7);
    ind = a.append(7);
    ind = a.append(7);
    ind = a.append(7);
    std::cout << "Next index:" << ind << std::endl;
    a.print();
    std::cout << "Curr size: " << a.size() << std::endl;
    return 0;
}
