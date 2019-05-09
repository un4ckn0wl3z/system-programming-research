#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;



void Logr(const char* message);
void PrintEntity(const Entity& e);


class Entity
{
public:
	int x, y;


	Entity() {}

	Entity(int x, int y) //: x(x), y(y)
	{
		this->x = x;
		this->y = y;

		Entity& e = *this;
		PrintEntity(*this);

	}

};

void Logr(const char* message)
{
	std::cout << message << std::endl;
}

void PrintEntity(const Entity& e)
{

}

int main()
{
	
	
	
	std::cin.get();
}