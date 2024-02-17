#include <triangle.hpp>
#include <SFML/Graphics.hpp>

namespace ac
{
	Triangle::Triangle(float x, float y, float r)
	{
		Triangle::Setup(x, y, r);
	}
	void Triangle::Setup(float x, float y, float r)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_triangle.setRadius(m_r);
		m_triangle.setPointCount(3);
		m_triangle.setPosition(m_x, m_y);
		int red = rand() % 255;
		int green = rand() % 255;
		int blue = rand() % 255;
		m_triangle.setFillColor(sf::Color::Color(red, green, blue, 155));
	}
	sf::CircleShape Triangle::Get()
	{
		return m_triangle;
	}
}