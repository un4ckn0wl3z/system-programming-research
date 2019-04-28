#include <iostream>
#include "Log.h"


static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

int main() 
{
	char a = 'A';
	char b = 66;
	short a_int = 'A';
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a_int << std::endl;

	std::cout << Multiply(5,8) << std::endl;

	int variable = 8;
	std::cout << variable << std::endl;

	variable = 20;
	std::cout << variable << std::endl;


	//------------------------------------

	float any_float = 5.5f;
	double any_double = 5.2;


	std::cout << any_float << std::endl;
	std::cout << any_double << std::endl;

	//------------------------------------


	bool isBool = true;
	std::cout << isBool << std::endl;
	std::cout << !isBool << std::endl;


	std::cout << sizeof(bool) << std::endl;


	std::cin.get();

}