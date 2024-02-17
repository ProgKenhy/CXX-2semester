#pragma once
#include <SFML/Graphics.hpp>

namespace ac
{
	class Triangle
	{
		float m_r;
		float m_x, m_y;
		sf::CircleShape m_triangle;

	public:
		Triangle() = default;
		Triangle(float x, float y, float r);
		void Setup(float x, float y, float r);
		sf::CircleShape Get();
	};
}