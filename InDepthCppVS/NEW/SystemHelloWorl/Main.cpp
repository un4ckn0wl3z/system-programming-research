#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};



int main()
{

	// ------------------- stack

	Entity entity;
	LOG(entity.GetName());

	Entity anuwat("Anuwat");
	LOG(anuwat.GetName());


	//-------------------- heap

	Entity* e;

	{
		Entity* ee = new Entity("UN4"); // call construct also
		e = ee;
		LOG(ee->GetName());

	}

	void * ptrm = malloc(50);

	Entity* e_ptr_m = (Entity*)malloc(sizeof(Entity)); // notcall construt
	free(e_ptr_m);
	delete e; // also call de-construct

	int* z = new int[100];

	Entity* eee = new(z) Entity(); // 

	LOG(sizeof(*eee));

	std::cin.get();
}