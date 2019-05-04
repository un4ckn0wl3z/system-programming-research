#include <iostream>


class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get()
	{
		return *s_Instance;
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


Singleton* Singleton::s_Instance = nullptr;


int main()
{

	Singleton::Get().Hello("Hi");


	Function();
	Function();
	Function();
	Function();
	Function();

	std::cin.get();
}