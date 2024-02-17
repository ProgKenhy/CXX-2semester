#include <Parallelogram.hpp>
#include <iostream>

int main()
{
	float a, b, angle;
	ac::Parallelogram p;
	std::cout << "Input the length: ";
	std::cin >> a;
	std::cout << "Input the width: ";
	std::cin >> b;
	std::cout << "Input the inclination angle: ";
	std::cin >> angle;
	p.Set(a, b, angle);

	std::cout << "Perimeter = " << p.Perimeter() << std::endl;
	std::cout << "Square = " << p.Square() << std::endl;
	return 0;
}