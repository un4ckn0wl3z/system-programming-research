#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

class Entity
{
public:
	virtual std::string GetName()
	{
		return "Entity";
	}
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name){}

	std::string GetName() override
	{
		return m_Name;
	}
};


int main()
{

	Entity* e = new Entity();

	std::cout << e->GetName() << std::endl;

	Player* p = new Player("Anuwat");

	std::cout << p->GetName() << std::endl;


	std::cin.get();
}