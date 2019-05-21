#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};

	/*
	Vector2& GetA()
	{
		return *(Vector2*)&x;
	}
	*/
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;

}

int main()
{




	Vector4 vetor = { 1.0f,2.0f,3.0f,4.0f };
	PrintVector2(vetor.a);
	PrintVector2(vetor.b);
	vetor.z = 500.0f;
	PrintVector2(vetor.b);
	//struct Union
	//{
	//	union
	//	{
	//		float a;
	//		int b;

	//	};
	//};

	//Union u;
	//u.a = 2.0f;
	//std::cout << u.a << ", " << u.b << std::endl;




	std::cin.get();
}