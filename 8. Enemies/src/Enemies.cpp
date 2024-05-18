#include <Enemies.hpp>
#include <iostream>

namespace ac
{


	bool Enemies::Setup(float x, float y, float vx, float vy, const std::string& texturePath, float scaleFactor)
	{
		m_x = x;
		m_y = y;
		m_vx = vx;
		m_vy = vy;

		if (!m_textureShip.loadFromFile(texturePath))
		{
			std::cout << "Error while loading " << texturePath << std::endl;
			return false;
		}
		m_spriteShip.setTexture(m_textureShip);

		m_spriteShip.setScale(scaleFactor, scaleFactor);
		m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
		m_spriteShip.setPosition(m_x, m_y);

		if (m_textureShip.getSize().x > m_textureShip.getSize().y)
			m_r = scaleFactor * m_textureShip.getSize().x / 2;
		else
			m_r = scaleFactor * m_textureShip.getSize().y / 2;
	}


	void Enemies::Move(float dt)
	{
		m_x += m_vx * dt;
		m_y += m_vy * dt;
		m_spriteShip.setPosition(m_x, m_y);
	}

	bool Enemies::CheckCollisionEnemies(Ship& c2)
	{
		float distance = sqrt(pow((m_x - c2.X()), 2) + pow((m_y - c2.Y()), 2));
		if (distance < m_r + c2.R() - 15)
		{
			return true;
		}
		return false;
		std::cout << m_r << std::endl;
	}



}