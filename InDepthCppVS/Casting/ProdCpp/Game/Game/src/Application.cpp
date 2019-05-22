#include <iostream>



int main()
{

//	int a = 5;
//	double value = a;

	double value = 5.25;
	double a = (int)value + 5.3; // c style cast

	std::cout << a << std::endl;


	double s = static_cast<int>(value) + 5.3; // c++ style cast


	std::cout << s << std::endl;

	std::cin.get();
}