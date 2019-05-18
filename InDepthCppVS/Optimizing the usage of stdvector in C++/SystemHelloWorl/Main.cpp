#include <iostream>
#include <string>
#include <memory>
#include <vector>


#define LOG(x) std::cout << x << std::endl;

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z) :x(x),y(y),z(z) {}

	Vertex(const Vertex& vertex) :x(vertex.x), y(vertex.y), z(vertex.z) 
	{
		LOG("Copied!");
	}
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
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
	

	std::cin.get();
}