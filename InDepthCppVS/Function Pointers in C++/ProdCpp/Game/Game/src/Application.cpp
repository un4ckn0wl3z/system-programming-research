#include <iostream>
#include <vector>


void HelloWorld(int a)
{
	std::cout << "Hello World!: value is " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "value is " << value << std::endl;
}


void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}



int main()
{

	typedef void(*HelloWorldFunc)(int);



	HelloWorldFunc func = HelloWorld;

	//void(*anuwat)() = HelloWorld;

	//anuwat = HelloWorld;
	//auto func = HelloWorld;
	//func();
	//func();
	//nuwat();
	//anuwat();
	func(1337);

	std::vector<int> value = {1,3,2,4,5,6};

	ForEach(value, PrintValue);
	
	std::cin.get();
}