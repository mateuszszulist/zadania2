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
    int y;
    y = 1;
    std::cout << "Podaj liczbe: ";
    std::cin >> x;
    do
    {

	std::cout << y;
	std::cout << " ";
	if (y % 3 == 0)
	{
	    std::cout << "Fizz";
	}
	if (y % 5 == 0)
	{
	    std::cout << "Buzz";
	}	
	std::cout << "\n";
	y++;
    }
    while (y != x + 1);
    return 0;
}
