#include <SFML/Graphics.hpp>
#include <line.hpp>

namespace ac
{
	Line::Line(float x, float y)
	{
		Line::Setup(x, y);
	}
	void Line::Setup(float x, float y)
	{
		m_x = x;
		m_y = y;
		m_line.setPosition(m_x, m_y);
		int red = rand() % 255;
		int green = rand() % 255;
		int blue = rand() % 255;
		int rotate = rand() % 360;
		m_line.setSize(sf::Vector2f(250.f, 1.f));
		m_line.rotate(rotate);
		m_line.setFillColor(sf::Color::Color(red, green, blue, 155));
	}
	sf::RectangleShape Line::Get()
	{
		return m_line;
	}
}