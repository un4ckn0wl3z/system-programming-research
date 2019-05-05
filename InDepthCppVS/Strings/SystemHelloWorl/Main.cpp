#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;





void PrintString(std::string s)
{
	s += " 662";
	std::cout << s << std::endl;
}



void PrintStringNoMod(const std::string& s)
{
	//s += "ASASX";
	std::cout << s << std::endl;
}

int main()
{

	const char* name = "Anuwat";
	const char* message;

	message = "I love C++";
	LOG(message);
	message = "I love C++ So much";


	LOG(message);

	LOG(name);

	char name_arr[7] = { 'A','n','u','w','a','t', NULL };
	LOG(name_arr);

	LOG(strlen(name));
	LOG(strlen(message));




	std::string hax = std::string("111111") + "2222222";
	hax += "33333";


	bool contains = hax.find("2") != std::string::npos;

	LOG(contains);
	LOG(hax);
	LOG(hax.size());





	std::string dummy = "L ox Sf";

	PrintString(dummy);

	PrintStringNoMod(dummy);

	LOG(dummy);





	std::cin.get();
}