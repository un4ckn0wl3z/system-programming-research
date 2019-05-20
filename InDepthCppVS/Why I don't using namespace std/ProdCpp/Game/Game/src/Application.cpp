#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>


void ForEach(const std::vector<int>& values, const std::function<void(int)>&func)
{
	for (int value : values)
	{
		func(value);
	}
}

namespace apple
{
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}


namespace orange
{
	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}

int main()
{


	apple::print("Hello");
	orange::print("Hello");

	std::vector<int> values = { 1,3,2,4,5,6 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
	std::cout << "find_if value is " << *it << std::endl;
	auto lambda = [](int value) { std::cout << "value is " << value << std::endl;  };
	ForEach(values, lambda);

	std::cin.get();
}