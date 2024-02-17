#include <func.hpp>
#include <ctime>
namespace ac
{
	int getLastNumber(std::fstream &file_read)
	{
		std::string line;
		int lastNumber = 0;
		while (std::getline(file_read, line))
		{
			int number = 0;
			std::cout << line << std::endl;
			int delimiterPos = line.find("-");
			lastNumber = std::stoi(line.substr(0, delimiterPos));
			if (number > lastNumber)
			{
				lastNumber = number;
			}
		}
		return lastNumber;
	}

	std::string currentDateTime()
	{
		std::time_t t = std::time(nullptr);
		std::tm *now = std::localtime(&t);
		char buffer[128];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", now);
		return buffer;
	}

}