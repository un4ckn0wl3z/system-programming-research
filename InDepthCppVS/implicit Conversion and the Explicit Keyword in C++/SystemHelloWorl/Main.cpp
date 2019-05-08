#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;


class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name)
		: m_Name(name), m_Age(-1)
	{}

	explicit Entity(int age)
		: m_Name("Unk"), m_Age(age)
	{}
};



int main()
{

	Entity a(10);
	Entity b((std::string)"Anuwat");
	
	
	std::cin.get();
}