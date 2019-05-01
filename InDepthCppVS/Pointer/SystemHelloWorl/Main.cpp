#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	int var = 8;
	int* ptr = &var;
	*ptr = 10;
	LOG(var);


	const char* msg = "message";
	LOG(msg);

	char* buffer = new char[8];
	memset(buffer,0,8);

	char** char_ptr = &buffer;

	char*** char_ptr_th = &char_ptr;

	delete[] buffer;

	std::cin.get();
}