#include "Log.h"

int main()
{
	InitLog();



	const char* ptr = "Hello"; // nullptr

	if(ptr == "A")
		Log(ptr);
	else if(ptr == "Hello")
		Log("ptr is Hello");
	else
		Log(ptr);

	
	int x = 6;

	bool comparisonResult = x == 5;

	if (comparisonResult)
	{
		Log("Hello, World!");
	}



	
	
	std::cin.get();
}