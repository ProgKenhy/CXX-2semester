#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace ac
{
	class Ship
	{
		float m_x, m_y;
		float m_alpha;
		float m_v;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;

	public:
		Ship() = default;
		Ship(float x, float y);
		bool Setup(float x, float y);
		void setVelocity(float dv);
		void Move();
		void Rotate(float dalpha);
		sf::Sprite Get(){ return m_spriteShip; }
	};
}