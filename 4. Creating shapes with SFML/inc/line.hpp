#pragma once
#include <SFML/Graphics.hpp>

namespace ac
{
	class Line
	{
		float m_x, m_y;
		sf::RectangleShape m_line;

	public:
		Line() = default;
		Line(float x, float y);
		void Setup(float x, float y);
		sf::RectangleShape Get();
	};
}