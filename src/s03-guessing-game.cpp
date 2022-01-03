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
    do
    {
	std::cout << "guess: ";
	std::cin >> x;
	if (x > 50)
	{
	    std::cout << "number too big!";
	    std::cout << "\n";
	}
	if (x < 50)
	{
	    std::cout << "number too small!";
	    std::cout << "\n";
	}
    }
    while (x != 50);
    std::cout << "just right!";
    std::cout << "\n";
    return 0;
}
