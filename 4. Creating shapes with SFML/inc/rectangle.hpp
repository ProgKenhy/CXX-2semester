#pragma once
#include <SFML/Graphics.hpp>

namespace ac
{
	class Rectangle
	{
		float m_x, m_y;
		sf::RectangleShape m_rectangle;

	public:
		Rectangle() = default;
		Rectangle(float x, float y);
		void Setup(float x, float y);
		sf::RectangleShape Get();
	};
}