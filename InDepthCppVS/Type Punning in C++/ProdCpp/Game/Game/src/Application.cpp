#include <iostream>


struct Entity
{
	int x, y;

	int* GetPosition()
	{
		return &x;
	}
};

int main()
{
	/*
	int a = 50;
	double& value = *(double*)&a;
	value = 0.0;
	std::cout << value << std::endl;
	*/

	Entity e = { 5, 8 };
	//int* position = (int*)&e;
	int* position = e.GetPosition();

	int y = *(int*)((char*)&e + 4);
	std::cout << y << std::endl;
	std::cout << position[0] << ", " << position[1] << std::endl;

	std::cin.get();
}