#include <iostream>
#include <fstream>
#include <func.hpp>

int main()
{
	std::ofstream out("run_time.txt");

	std::cout << sum(2, 3);

	return 0;
}