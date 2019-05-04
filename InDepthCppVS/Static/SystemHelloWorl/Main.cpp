#include <iostream>


struct Entity
{
	static int x, y;

	static void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}

};

int Entity::x;
int Entity::y;

int main()
{
	Entity::x = 5;
	Entity::y = 8;
	Entity::Print();

	std::cin.get();
}