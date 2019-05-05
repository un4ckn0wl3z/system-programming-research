#include <iostream>
#include <string>


#define LOG(x) std::cout << x << std::endl;



class Entity
{
private:
	int m_X, m_Y;
	mutable int var;
public:
	int GetX() const
	{
		var = 2;
		return m_X;
	}

	void SetX(int x)
	{
		m_X = x;
	}
};


void PrintEntity(const Entity& e)
{
	LOG(e.GetX());
}

int main()
{


	Entity e;

	e.SetX(999);
	PrintEntity(e);

	const int MAX_AGE = 90;

	//--------------------------------------
	const int* a = new int; 
	// cannot modify value in pointer
	// but can re-assign
	//--------------------------------------


	//--------------------------------------
	 int* const b = new int;
	// cannot re-assign pointer
	// but can modify value in pointer
	//--------------------------------------



	//--------------------------------------
	 const int* const c = new int;
	 // lock em all
	 //--------------------------------------




	//*a = 2;

	//LOG(*a);

	a = (int*)&MAX_AGE;

	/*a = 100;
	LOG(*a);
	LOG(MAX_AGE);
	*/
	std::cin.get();
}