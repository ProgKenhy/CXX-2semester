#include <func.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
namespace ac
{
	std::string currentDateTime()
	{
		std::time_t t = std::time(nullptr);
		std::tm *now = std::localtime(&t);

		char buffer[128];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", now);
		return buffer;
	}
	void appendTimeToFile(const std::string &filename)
	{
		std::ofstream out(filename, std::ios_base::app);
		if (out.is_open())
		{
			std::ofstream out(filename, std::ios_base::app);
			std::cout << currentDateTime();
			out.close();
		}
		else
			std::cout << ("File is not open!");
	}
}