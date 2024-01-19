#include <func.hpp>
#include <iostream>
#include <fstream>

int main()
{
	std::fstream out("file\\run.txt");
	if (out.is_open())
	{
		int last_number = ac::getLastNumber(out);
		std::string time = ac::currentDateTime();
		std::fstream out("file\\run.txt", std::ios::app);
		std::cout << last_number + 1 << " - " << time;
		out << "\n";
		out << last_number + 1 << " - " << time;
		out.close();
	}
	else
		std::cout << ("File is not open!");
	return 0;
}