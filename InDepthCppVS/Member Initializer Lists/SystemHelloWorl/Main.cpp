#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;



class Example
{
public:
	Example()
	{
		LOG("Created Entity!");
	}

		Example(int x)
	{
			std::cout << "Created Entity!" << " with " << x << std::endl;
	}

};



class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
	int m_Score;
	Example e;
public:
	Entity()
		: m_Name("Unk"), m_Score(0), e(Example(95))
	{
		//m_Name = "Unk";
		//e = Example(95);
	}

	Entity(const std::string& name)
	{
		m_Name = name;
	}


	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};


int main()
{

	const Entity e0;
	LOG(e0.GetName());

	const Entity e1("Anuwat");
	LOG(e1.GetName());

	std::cin.get();
}