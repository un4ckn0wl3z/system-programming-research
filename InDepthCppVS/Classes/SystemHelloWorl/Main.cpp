#include <iostream>

#define LOG(x) std::cout << x << std::endl;

class Player
{
public:
	int x, y;
	int speed;
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};


int main()
{
	
	Player player;
	player.x = 10;
	player.y = 6;
	player.speed = 6;

	player.Move(20,15);

	//LOG(player);

	std::cin.get();
}