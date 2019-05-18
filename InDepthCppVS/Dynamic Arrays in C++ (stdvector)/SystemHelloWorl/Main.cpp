#include <iostream>
#include <string>
#include <memory>
#include <vector>


#define LOG(x) std::cout << x << std::endl;

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;

}

int main()
{

	//Vertex* vertices = new Vertex[5];

	std::vector<Vertex> vertices;

	vertices.push_back({1,2,3});
	vertices.push_back({4,5,6});

	for (int i=0;i< vertices.size();i++)
	{
		LOG(vertices[i]);
	}


	vertices.erase(vertices.begin() + 1);

	for (Vertex& v : vertices)
	{
		LOG(v);
	}

	vertices.clear();

	std::cin.get();
}