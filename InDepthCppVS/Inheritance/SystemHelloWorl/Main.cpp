#include <iostream>

#define LOG(x) std::cout << x << std::endl;

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}


};

class Player : public Entity
{
public:
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}


};


int main()
{

	Player player;
	player.Name = "Anuwat";
	player.PrintName();
	player.Move(5,5);

	LOG("========================");

	LOG(player.Name);
	LOG(player.X);
	LOG(player.Y);
	std::cin.get();
}