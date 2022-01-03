#include <iostream>
#include <string>

auto number(std::string prompt) -> int
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
	std::cout << x;
	std::cout << " bottles of beer on the wall, ";
	std::cout << x;
	std::cout << " bottles of beer.";
	std::cout << "\n";
	std::cout << "Take one down, pass it around, ";
	x--;
	std::cout << x;
	std::cout << " bottles of beer on the wall...";
	std::cout << "\n";
	std::cout << "\n";
	if (x == 2)
	{
	    std::cout << x;
	    std::cout << " bottles of beer on the wall, ";
	    std::cout << x;
	    std::cout << " bottles of beer.";
	    std::cout << "\n";
	    std::cout << "Take one down, pass it around, ";
	    x--;
	    std::cout << x;
	    std::cout << " bottle of beer on the wall...";
	    std::cout << "\n";
	    std::cout << "\n";
	}
	if (x == 1)
	{
	    std::cout << x;
	    std::cout << " bottle of beer on the wall, ";
	    std::cout << x;
	    std::cout << " bottle of beer.";
	    std::cout << "\n";
	    std::cout << "Take one down, pass it around, ";
	    x--;
	    std::cout << "No more bottles of beer on the wall...";
	    std::cout << "\n";
	    std::cout << "\n";
	}
    }
    while (x != 0);
    std::cout << "No more bottles of beer on the wall, no more bottles of beer.";
    std::cout << "\n";
    std::cout << "Go to the store and buy some more, 99 bottles of beer on the wall...";
    std::cout << "\n";
    return 0;
}
