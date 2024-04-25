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
	bool Bullet::CheckCollision(Bullet& c2)
	{
		float distance = sqrt(pow((m_x - c2.m_x), 2) + pow((m_y - c2.m_y), 2));
		if (distance <= m_r + c2.m_r)
		{
			return true;
		}
		return false;
	}
	void Bullet::HandleCollision(Bullet& c2, int i, int j)
	{

		float distance = sqrt(pow((m_x - c2.m_x), 2) + pow((m_y - c2.m_y), 2));
		if (distance < m_r + c2.m_r)
		{
			float offset = m_r + c2.m_r - distance;
			float directionX = (c2.m_x - m_x) / distance;
			float directionY = (c2.m_y - m_y) / distance;
			c2.m_x += directionX * offset / 2;
			c2.m_y += directionY * offset / 2;
			m_x -= directionX * offset / 2;
			m_y -= directionY * offset / 2;
		}
	}


	sf::CircleShape Bullet::Get()
	{
		return m_shape;
	}
}