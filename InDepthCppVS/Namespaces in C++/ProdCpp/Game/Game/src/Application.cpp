#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>


namespace apple { namespace func
{
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}
}
namespace orange
{
	void print(const char* text)
	{
		std::cout << text << std::endl;
	}
	void print_again(const char* text)
	{
		std::cout << text << std::endl;
	}
}

class Entity
{
public:
	static void PrintHello()
	{
		std::cout << "Hello!" << std::endl;
	}
};

int main()
{

	using orange::print_again;

	//using namespace apple;

	namespace alias_apple = apple;


	alias_apple::func::print("Hello");
	orange::print("Hello");

	Entity::PrintHello();
	print_again("Anuwat");
	std::cin.get();
}