#include "Person.h"
#include <iostream>

int main()
{
    Queen osoba("Mateusz Szulist");
    std::cout << osoba.to_string() << std::endl;
    std::cout << who_is_it(osoba) << std::endl;
    Hello h;
    Good_evening g;
    Farewell f;
    std::cout << h.greet(osoba) << std::endl;
    std::cout << g.greet(osoba) << std::endl;
    std::cout << f.greet(osoba) << std::endl;
    return 0;
}