#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{

	std::vector<int> values = { 3,1,6,9,4,7 };
	//std::sort(values.begin(), values.end(), std::greater<int>());
	std::sort(values.begin(), values.end(), [](int a, int b) 
	{
		return a < b;
	});


	for (int v : values)
		std::cout << v << std::endl;

	std::cin.get();
}