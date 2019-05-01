#include "Log.h"

int main()
{
	InitLog();

	for (int i = 0; i < 5; i++)
	{
		if( i % 2 == 0)
			continue;

		Log("Hello, World...");
		
	}


	std::cin.get();
}