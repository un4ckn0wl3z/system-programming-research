#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>





std::string GetName()
{
	return "Anuwat";
}


class Device
{};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};




int main()
{

	auto name = GetName();


	int a = 5;

	auto b = a;

	std::cout << b << std::endl;
	std::cout << name << std::endl;



	std::vector<std::string> strings;

	strings.push_back("Apple");
	strings.push_back("Orange");

	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	//using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;

	DeviceManager dm;
	
	//const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
	//const DeviceMap& devices = dm.GetDevices();


	const auto& devices = dm.GetDevices();

	std::cin.get();
}