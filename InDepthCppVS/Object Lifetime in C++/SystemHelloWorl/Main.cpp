#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;

class Entity
{
public:

	Entity() 
	{
		LOG("Created Object!");
	}

	~Entity()
	{
		LOG("Destroyed Object!");
	}
};

int* CreateArray()
{
	int* array = new int[50];
	return array;
}

void CreateArray2(int* array)
{
	// file array

}


class ScopePtr
{
private:
	Entity * m_Ptr;
public:
	ScopePtr(Entity * ptr) : m_Ptr(ptr) {}
	~ScopePtr() { delete m_Ptr; }
};


int main()
{

	{
		Entity e;
	
	}

	{
		Entity* e = new Entity();

	}

	{
	
		ScopePtr e = new Entity();

	}

	int * a = CreateArray();
	
	int a2[50];
	CreateArray2(a2);
	
	
	std::cin.get();
}