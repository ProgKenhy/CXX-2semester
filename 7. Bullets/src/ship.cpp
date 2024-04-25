#pragma once
#include <ship.hpp>


namespace ac
{

	Ship::Ship(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	bool Ship::Setup(float x, float y)
	{
		m_x = x;
		m_y = y;
		m_alpha = 0;
		m_v = 0;
		current_bullet = 0;


		m_bullet = new Bullet[number_of_max_bullets];

		if (!m_textureShip.loadFromFile("assets\\falcon.png"))
		{
			std::cout << "Error while loading falcon.png" << std::endl;
			return false;
		}
		m_spriteShip.setTexture(m_textureShip);

		m_spriteShip.setScale(0.2f, 0.2f);
		m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
		m_spriteShip.setPosition(m_x, m_y);
		m_spriteShip.setRotation(m_alpha);

	}



	void Ship::setVelocity(float dv)
	{
		m_v += dv;
	}



	void Ship::Move(float dt)
	{
		for (int i = 0; i < number_of_max_bullets; i++)
			m_bullet[i].Move(dt);
		float alphaRad = acos(-1) * m_alpha / 180;
		m_x += m_v * cos(alphaRad) * dt;
		m_y += m_v * sin(alphaRad) * dt;
		m_spriteShip.setPosition(m_x, m_y);
		
	}

	void Ship::TouchBorder(int width, int height)
	{
		if (m_x > width)
			m_x = 0;
		if (m_x < 0)
			m_x = width;
		if (m_y > height)
			m_y = 0;
		if (m_y < 0)
			m_y = height;
	}




	void Ship::Rotate(float dalpha)
	{
		m_alpha += dalpha;
		m_spriteShip.setRotation(m_alpha);
	}


	void Ship::Attack()
	{

		float alphaRad = acos(-1) * m_alpha / 180;
		m_bullet[current_bullet].Setup(m_x + 70 * cos(alphaRad), m_y + 70 * sin(alphaRad), m_bulletR, (m_v + m_v_bullet) * cos(alphaRad), (m_v + m_v_bullet) * sin(alphaRad));


		if (current_bullet < number_of_max_bullets-1)
			current_bullet++;
		else
			current_bullet = 0;
	}



	};

