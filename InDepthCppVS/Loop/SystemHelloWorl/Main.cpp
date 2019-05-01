#include "Log.h"

int main()
{
	InitLog();

	
	int i = 0;
	bool condition = true;

	//for (; condition ;)
	//{
	//	Log("Hello, World..");
	//	i++;
	//	if (!(i<5))
	//	{
	//		condition = false;
	//	}
	//}
	
	while (i < 5)
	{
		Log("Hello, World..while");
		i++;
	}
	Log("===========================================");

	do
	{
		Log("Hello, World..do");
	} while (false);


	std::cin.get();
}