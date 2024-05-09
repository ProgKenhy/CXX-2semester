#include <bullet.hpp>
#include <iostream>

namespace ac
{
	Bullet::Bullet(float x, float y, float r, float vx, float vy)
	{
		Bullet::Setup(x, y, r, vx, vy);
	}
	void Bullet::Setup(float x, float y, float r, float vx, float vy)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_vx = vx;
		m_vy = vy;
		is_available = true;
		m_shape.setOrigin(m_r, m_r);
		m_shape.setRadius(m_r);
		m_shape.setPosition(m_x, m_y);
		int red = rand() % 200 + 40;
		int green = rand() % 200 + 40;
		int blue = rand() % 200 + 40;
		m_shape.setFillColor(sf::Color::Color(255, 0, 0, 255));
	}

	void Bullet::Move(float dt)
	{
		m_x += m_vx * dt;
		m_y += m_vy * dt;
		m_shape.setPosition(m_x, m_y);

	}
	bool Bullet::CheckCollision(Circle& c2)
	{
		if (is_available && c2.IS_available())
		{
			float distance = sqrt(pow((m_x - c2.X()), 2) + pow((m_y - c2.Y()), 2));
			if (distance <= m_r + c2.R())
			{
				return true;
			}
		}
		return false;
	}
	void Bullet::HandleCollision()
	{
		m_r = 0;
		m_shape.setRadius(0);
		is_available = false;

	}


	sf::CircleShape Bullet::Get()
	{
		return m_shape;
	}


}