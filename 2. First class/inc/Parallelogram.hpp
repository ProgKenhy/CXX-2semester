#pragma once

namespace ac
{
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
		Parallelogram(float a, float b, float angle);

		void Set(float a, float b, float angle);

		float Square();
		float Perimeter();

		// Destructor
		~Parallelogram()
		{
		}
	};

}