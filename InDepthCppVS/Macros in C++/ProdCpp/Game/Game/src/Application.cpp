#include <iostream>


#ifdef PR_DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif // PR_DEBUG





int main()
{

	LOG("Hello");
	std::cin.get();
}