#include <iostream>
#include <array>



#define LOG(x) std::cout << x << std::endl;



class Entity
{
public:
	static const int exampleSize = 5;
	int example[exampleSize];
	
	std::array<int, 5> aa;

	Entity()
	{
		for (int i = 0; i < exampleSize; i++)
		{
			example[i] = 2;
		}


		for (int i = 0; i < aa.size() ; i++)
		{
			aa[i] = 2;
		}


	}

};



int main()
{


	Entity e;

	//int* ptr = example;

	//example[2] = 5;

	//*(int*)((char*)ptr + 8) = 6;


	int example[5];

	int* another = new int[5];

	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}

	for (int i = 0; i < 5; i++)
	{
		another[i] = 2;
	}

	delete[] another;


	/*
	example[0] = 1;
	example[1] = 2;
	example[2] = 3;
	example[3] = 4;
	example[4] = 5;
	*/
	/*
	for (int i=0;i<5;i++)
	{
		example[i] = 2;
	}
	*/




	std::cin.get();
}