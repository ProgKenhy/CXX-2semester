#include <func.hpp>
#include <cmath>
#include <iostream>
#define PI 3.14159265

class Parallelogram
{
private:
	// Fields of classes
	float m_a;
	float m_b;
	float m_angle;

public:
	// default constructor
	Parallelogram() {}
	// Constructor
	Parallelogram(float a, float b, float angle)
	{
		Set(a, b, angle);
	}

	void Set(float a, float b, float angle)
	{
		if (a < 0 || b < 0 || angle < 0)
		{
			std::cout << "Error a<0 or b<0 or angle<0" << std::endl;
			return;
		}
		m_a = a;
		m_b = b;
		m_angle = angle;
	}

	float Square()
	{
		return m_a * m_b * sin(m_angle * PI / 180.0f);
	}
	float Perimeter()
	{
		return 2.0f * (m_a + m_b);
	}

	// Destructor
	~Parallelogram()
	{
	}
};

int main()
{
	float a, b, angle;
	Parallelogram p;
	std::cout << "Input the length: ";
	std::cin >> a;
	std::cout << "Input the width: ";
	std::cin >> b;
	std::cout << "Input the inclination angle: ";
	std::cin >> angle;
	p.Set(a, b, angle);

	std::cout <<"Perimeter = "<< p.Perimeter() << std::endl;
	std::cout <<"Square = "<< p.Square() << std::endl;
	return 0;
}