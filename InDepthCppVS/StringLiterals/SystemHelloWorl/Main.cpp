#include <iostream>
#include <string>
#include <stdlib.h>


#define LOG(x) std::cout << x << std::endl;

int main()
{

	using namespace std::string_literals;


	// std::u32string name0 = U"Alex"s + U" Hakme";
	// LOG(name0);

	const char* examp = R"(
======================================
			BANNERHERE
======================================
)";
	LOG(examp);

	const char* name = u8"Anuwat"; // 1 byte
	const wchar_t* name2 = L"Anuwat"; // 2 bytes  or utf-8
	const char16_t* name3 = u"Anuwat"; // 2 bytes or utf-16
	const char32_t* name4 = U"Anuwat"; // 4 bytes or utf-32


	LOG(sizeof(char));
	LOG(sizeof(wchar_t));
	LOG(sizeof(char16_t));
	LOG(sizeof(char32_t));

	const wchar_t* ch = L"漢語"; // 2 bytes  or utf-8


	LOG(ch);
	std::cin.get();
}