#include <iostream>
#include <string>
#include <memory>



#define LOG(x) std::cout << x << std::endl;



class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{

		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];

		/*
		for (int i=0;i< m_Size;i++)
		{
			m_Buffer[i] = string[i];
		}
		*/

		memcpy(m_Buffer, string, m_Size + 1);

	}


	String(const String& other) : m_Size(other.m_Size) 
	{
		LOG("String copied.");
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);

	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;

}

void PrintString(const String& string) 
{
	LOG(string);
}


int main()
{

	String string = "Anuwat";

	String second = string;
	second[2] = 'x';
	PrintString(string);
	PrintString(second);

	std::cin.get();
}