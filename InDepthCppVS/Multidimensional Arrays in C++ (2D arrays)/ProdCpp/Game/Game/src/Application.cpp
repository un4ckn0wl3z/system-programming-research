#include <iostream>




int main()
{

	//int* array = new int[50];

	int** a2d = new int*[50];

	//a2d[0] = nullptr;


	for (int i = 0; i < 50; i++)
		a2d[i] = new int[50];


	int*** a3d = new int**[50];
	for (int i = 0; i < 50; i++) {
		a3d[i] = new int*[50];
		for (int j = 0; j < 50; j++) {
			int** ptr = a3d[i];
			ptr[j] = new int[50];
		}
	}


	//a2d[0][0] = 0;
	//a3d[0][0][0] = 0;



	

	for (int x = 0; x < 50; x++)
	{
		for (int y = 0; y < 50; y++)
		{
			a2d[x][y] = 20;
		}
	}

	int* array = new int[5 * 5];
	for (int i = 0; i < 5 * 5; i++)
	{
		array[i] = 20;
	}



	for (int i = 0; i < 50; i++)
		delete[] a2d[i];

	delete[] a2d;


	std::cin.get();
}