#include <iostream>
#include <string>
#include <memory>

#define LOG(x) std::cout << x << std::endl;



class Entity
{
public:
	int x;
	void Print() const
	{
		LOG("Hello!");
	}
};

class ScopedPtr
{
private:
	Entity* m_Object;
public:
	ScopedPtr(Entity* entity) : m_Object(entity)
	{

	}

	~ScopedPtr()
	{
		delete m_Object;
	}

	Entity* GetObject()
	{
		return m_Object;
	}

	Entity* operator->()
	{
		return m_Object;
	}

	const Entity* operator->() const
	{
		return m_Object;
	}


};



struct Vector3
{
	float x, y, z;

};




int main()
{
	/*
	Entity e;
	e.Print();


	Entity* ptr = &e;
	Entity& entity = *ptr;

	entity.Print();

	(*ptr).Print();
	ptr->Print();
	ptr->x = 2;
	*/

	const ScopedPtr entity = new Entity();

	
	//entity.GetObject()->Print();

	entity->Print();



	int offset = (int)&((Vector3*)nullptr)->y;
	LOG(offset);
	std::cin.get();
}