#include <iostream>


class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance;
		return instance;
	}

	void Hello(const char* message)
	{
		std::cout << message << std::endl;
	}
};


void Function()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;

}

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


void TestRef(int& num)
{
	num++;
}

int main()
{

	Singleton::Get().Hello("Hi");


	Function();
	Function();
	Function();
	Function();
	Function();
	std::cout << "------------------------------" << std::endl;
	int x = 20;
	TestRef(x);
	std::cout << x << std::endl;

	std::cin.get();
}