#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void Increment(int* num)
{
	(*num)++;
}

int main()
{
	/*
	int a = 5;
	int& ref = a;
	ref = 10;

	LOG(ref);
	*/


	int a = 10;
	Increment(&a);
	LOG(a);

	std::cin.get();
}