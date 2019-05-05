#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;



class Printable
{
public:
	virtual std::string GetClassName() = 0;

};


class Entity : public Printable
{
public:
	virtual std::string GetName()
	{
		return "Entity";
	}

	std::string GetClassName() override
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
	std::string GetClassName() override
	{
		return "Player";
	}
};



class A : public Printable
{
public:
	std::string GetClassName() override { return "A"; }
};


void Print(Printable* obj)
{
	LOG(obj->GetClassName());
}

int main()
{

	Entity* e = new Entity();

	//std::cout << e->GetName() << std::endl;

	Player* p = new Player("Anuwat");

	//std::cout << p->GetName() << std::endl;

	Print(e);
	Print(p);
	Print(new A());


	std::cin.get();
}