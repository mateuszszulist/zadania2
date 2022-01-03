#include <iostream>
#include <string>

auto haslo(std::string prompt) -> char
{
    std::cout << prompt << " char:";
    auto n = std::string {};
    std::getline(std::cin, n);
    return std::stoi(n);
}

auto main() -> int
{
    std::string x;
    do 
    {
       std::cout << "password: ";
       std::cin >> x;
    }
    while (x != "student");
    return 0;
}
