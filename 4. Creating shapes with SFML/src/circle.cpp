#include <circle.hpp>
#include <SFML/Graphics.hpp>

namespace ac
{
	Circle::Circle(float x, float y, float r)
	{
		Circle::Setup(x, y, r);
	}
	void Circle::Setup(float x, float y, float r)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_shape.setRadius(m_r);
		m_shape.setPosition(m_x, m_y);
		int red = rand() % 255;
		int green = rand() % 255;
		int blue = rand() % 255;
		m_shape.setFillColor(sf::Color::Color(red, green, blue, 155));
	}
	sf::CircleShape Circle::Get()
	{
		return m_shape;
	}

}