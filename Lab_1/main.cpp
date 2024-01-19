#include <func.hpp>

int main()
{
	std::ofstream out("file\\run.txt", std::ofstream::app);
	if (!out.is_open())
	{
		std::cout << ("File is not open!");
	}
	out << "ac::sum(2, 3)asdsada";
	std::cout << ac::sum(2, 3);
	out.close();
	return 0;
}