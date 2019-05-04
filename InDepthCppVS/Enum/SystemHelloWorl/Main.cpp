#include <iostream>

class Log
{
public:
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_Loglevel = LevelInfo;

public:
	void SetLevel(Level level)
	{
		m_Loglevel = level;
	}

	void Error(const char* message)
	{
		if (m_Loglevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_Loglevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_Loglevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}


};


int main()
{

	Log log;

	log.SetLevel(Log::LevelError);
	log.Error("Hello!");
	log.Warn("Hello!");
	log.Info("Hello!");

	std::cin.get();
}