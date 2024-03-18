#include <circle.hpp>
#include <iostream>

namespace ac
{
	Circle::Circle(float x, float y, float r, float vx, float vy)
	{
		Circle::Setup(x, y, r, vx, vy);
	}
	void Circle::Setup(float x, float y, float r, float vx, float vy)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_vx = vx;
		m_vy = vy;
		m_shape.setOrigin(m_r, m_r);
		m_shape.setRadius(m_r);
		m_shape.setPosition(m_x, m_y);
		int red = rand() % 255;
		int green = rand() % 255;
		int blue = rand() % 255;
		m_shape.setFillColor(sf::Color::Color(red, green, blue, 155));
	}

	void Circle::Move(float dt)
	{
		m_x += m_vx * dt;
		m_y += m_vy * dt;
		m_shape.setPosition(m_x, m_y);
	}
	bool Circle::CheckCollision(Circle &c2)
	{
		float x2 = c2.m_x;
		float y2 = c2.m_y;
		float r2 = c2.m_r;

		float distance = sqrt((m_x - x2) * (m_x - x2) + (m_y - y2) * (m_y - y2));

		if (distance <= m_r + r2)
		{
			float offset = m_r + r2 - distance;
			float directionX = (x2 - m_x) / distance;
			float directionY = (y2 - m_y) / distance;
			c2.m_x += directionX * offset;
			c2.m_y += directionY * offset;
			return true;
		}
		return false;
	}
	void Circle::HandleCollision(Circle &c2)
	{

		float vx2 = c2.m_vx;
		c2.m_vx = m_vx;
		m_vx = vx2;
		float vy2 = c2.m_vy;
		c2.m_vy = m_vy;
		m_vy = vy2;
	}
	sf::CircleShape Circle::Get()
	{
		return m_shape;
	}
}