#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;

static int s_Level = 1;
static int s_Speed = 2;


int main()
{
	s_Speed = s_Level > 5 ? 10 : 5;

	LOG(s_Speed);

	std::cin.get();
}