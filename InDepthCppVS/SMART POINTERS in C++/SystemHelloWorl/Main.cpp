#include <iostream>
#include <string>
#include <memory>



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

	void Print() {}
};



int main()
{
	{
		std::weak_ptr<Entity> ew;

		std::shared_ptr<Entity> e0;
		{
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();
			entity->Print();

			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

			e0 = sharedEntity;

			ew = sharedEntity;

		}
	}

	std::cin.get();
}