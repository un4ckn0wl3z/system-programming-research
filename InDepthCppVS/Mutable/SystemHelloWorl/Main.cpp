#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;



class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};


int main()
{

	const Entity e;
	e.GetName();

	int x = 8;

	auto f = [=]() mutable
	{	
		x++;
		LOG(x);
	};

	f();
	LOG(x);

	std::cin.get();
}