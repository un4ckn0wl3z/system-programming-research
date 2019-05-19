#include <iostream>



template<typename T> void Print(T value)
{
	std::cout << value << std::endl;
}

template<typename T,int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const
	{
		return N;
	}
};


int main()
{

	Print<const char*>("Hello");
	Print<int>(99);
	Print<float>(103.2);
	Print<char>('A');

	Array<float,5> arrays;
	std::cout << arrays.GetSize() << std::endl;
	
	std::cin.get();
}