#include <iostream>



void MultiplyAndLog(int a, int b)
{
	std::cout << "The result is : " << a * b << std::endl;
}

int main()
{

	MultiplyAndLog(5, 3);
	MultiplyAndLog(2, 7);
	MultiplyAndLog(2, 9);

	std::cin.get();

}