#include <iostream>
#include <string>

struct Time 
{
	std::string message;
	
	Time (std::string msg)
	{
		message = msg;
	}
	
	~Time()
	{
		std::cout << message << std::endl;
	}
};

int main()
{
	Time t("Hello World");
	return 0;
}
