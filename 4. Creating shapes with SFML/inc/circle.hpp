#pragma once
#include <SFML/Graphics.hpp>

namespace ac
{
	class Circle
	{
		float m_r;
		float m_x, m_y;
		sf::CircleShape m_shape;

	public:
		Circle() = default;
		Circle(float x, float y, float r);
		void Setup(float x, float y, float r);
		sf::CircleShape Get();
	};
}