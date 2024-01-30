#include <Parallelogram.hpp>
#include <iostream>
#include <cmath>
#define PI 3.14159265

namespace ac
{
	Parallelogram::Parallelogram(float a, float b, float angle)
	{
		Set(a, b, angle);
	}
	void Parallelogram::Set(float a, float b, float angle)
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
	float Parallelogram::Square()
	{
		return m_a * m_b * sin(m_angle * PI / 180.0f);
	}
	float Parallelogram::Perimeter()
	{
		return 2.0f * (m_a + m_b);
	}
}