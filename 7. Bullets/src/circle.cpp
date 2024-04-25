#include <circle.hpp>
#include <iostream>

namespace ac
{
	Circle::Circle(float x, float y, float r, float vx, float vy, int n)
	{
		Circle::Setup(x, y, r, vx, vy, n);
	}
	void Circle::Setup(float x, float y, float r, float vx, float vy, int n)
	{
		m_n = n;
		m_col_is_handling = new bool[m_n];
		std::fill(m_col_is_handling, m_col_is_handling + m_n, true);
		m_x = x;
		m_y = y;
		m_r = r;
		m_vx = vx;
		m_vy = vy;
		bool is_avaible = true;
		m_shape.setOrigin(m_r, m_r);
		m_shape.setRadius(m_r);
		m_shape.setPosition(m_x, m_y);
		int red = rand() % 200 + 40;
		int green = rand() % 200 + 40;
		int blue = rand() % 200 + 40;
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
		if(is_avaible && c2.is_avaible)
		{
			float distance = sqrt(pow((m_x - c2.m_x), 2) + pow((m_y - c2.m_y), 2));
			if (distance <= m_r + c2.m_r)
			{
				return true;
			}
		}
		return false;
	}
	void Circle::HandleCollision(Circle& c2, int i, int j)
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
		if (m_col_is_handling[i] && m_col_is_handling[j])
		{

			m_col_is_handling[i] = false;
			m_col_is_handling[j] = false;

			float vx2 = c2.m_vx;
			float vy2 = c2.m_vy;
			float px = c2.X() - m_x;
			float py = c2.Y() - m_y;

			float len = sqrt(pow(px, 2) + pow(py, 2));
			float beta = acos((px) / len);

			if ((px > 0 && py > 0) || (px < 0 && py > 0))
				beta = -beta;

			float v1x = m_vx * cos(beta) - m_vy * sin(beta);
			float v1y = m_vx * sin(beta) + m_vy * cos(beta);
			float v2x = vx2 * cos(beta) - vy2 * sin(beta);
			float v2y = vx2 * sin(beta) + vy2 * cos(beta);

			float v1y_s = v1y;
			float v2y_s = v2y;
			float v1x_s = v2x;
			float v2x_s = v1x;

			m_vx = v1x_s * cos(beta) + v1y_s * sin(beta);
			m_vy = -v1x_s * sin(beta) + v1y_s * cos(beta);
			c2.m_vx = v2x_s * cos(beta) + v2y_s * sin(beta);
			c2.m_vy = -v2x_s * sin(beta) + v2y_s * cos(beta);
		}

		else
		{
			m_col_is_handling[i] = true;
			m_col_is_handling[j] = true;
		}
	}

	bool Circle::TouchBorder(int width, int height, float dt)
	{
		float x = m_x;
		float y = m_y;

		x += m_vx * dt;
		y += m_vy * dt;

		if (x + m_r >= width)
		{
			m_vx = -m_vx;
			m_x =  width - m_r;
			return true;
		}
		if (x - m_r <= 0)
		{
			m_vx = -m_vx;
			m_x = m_r;
			return true;
		}
		if (y + m_r >= height)
		{
			m_vy = -m_vy;
			m_y = height - m_r;
			return true;
		}
		if (y - m_r <= 0)
		{
			m_vy = -m_vy;
			m_y = m_r;
			return true;
		}

		return false;
	}


	void Circle::Deleting()
	{
		m_r = 0;
		is_avaible = false;
		m_shape.setRadius(0);
	}


}