#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;



class Entity
{
protected:
	int X, Y;
	void Print()
	{

	}
public:
	Entity()
	{
		X = 0;
		Y = 0;
		Print();
	}

};


class Player : public Entity
{
public:
	Player()
	{
		X = 1;
		Y = 1;
		Print();
	}

};

int main()
{



	std::cin.get();
}