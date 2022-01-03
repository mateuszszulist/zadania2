#include <iostream>
#include <string>

auto liczba(std::string prompt) -> int
{
    std::cout << prompt << "char: ";
    auto n = std::string {};
    std::getline(std::cin, n);
    return std::stoi(n);
}

auto main() -> int
{
    int x;
    std::cout << "Podaj liczbe: ";
    std::cin >> x;
    do
    {
	if(x > 0) 
	{
	    std::cout << x;
	    std::cout << "\n";
	    x--;
	}
	else
	{
	    std::cout << x;
	    std::cout << "\n";
	    x++;
	}
    }
    while (x != 0);
    std::cout << "0";
    std::cout << "\n";
    return 0;
}
