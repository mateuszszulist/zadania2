#include <iostream>
#include <string>

struct Time 
{
	void print_this()
	{
		std::cout << this << std::endl;
	}
};

int main()
{
	Time t;
	t.print_this();
	return 0;
}
