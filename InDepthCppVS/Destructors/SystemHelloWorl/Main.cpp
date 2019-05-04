#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity()
	{
		// X = 0.0f;
		// Y = 0.0f;
	}


	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	~Entity()
	{
		std::cout << "Cleaned!" << std::endl;
	}
	

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};


void Function()
{
	Entity entity(10.0f, 5.0f);
	//std::cout << entity.X << ", " << entity.Y << std::endl;
	entity.Print();
}


int main()
{
	Function();
	std::cin.get();
}