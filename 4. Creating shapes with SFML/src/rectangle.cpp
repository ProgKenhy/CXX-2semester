#include <rectangle.hpp>
#include <SFML/Graphics.hpp>

namespace ac
{
	Rectangle::Rectangle(float x, float y)
	{
		Rectangle::Setup(x, y);
	}
	void Rectangle::Setup(float x, float y)
	{
		m_x = x;
		m_y = y;
		m_rectangle.setPosition(m_x, m_y);
		int red = rand() % 255;
		int green = rand() % 255;
		int blue = rand() % 255;
		m_rectangle.setSize(sf::Vector2f(100.f, 100.f));
		m_rectangle.setFillColor(sf::Color::Color(red, green, blue, 155));
	}
	sf::RectangleShape Rectangle::Get()
	{
		return m_rectangle;
	}
}