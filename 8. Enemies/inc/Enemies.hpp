#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ship.hpp>






namespace ac
{
	class Enemies
	{
	protected:
		float m_x = 0, m_y = 0;
		float m_vx = 0, m_vy = 0;
		float m_r = 0;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;
		virtual void Attack() = 0;
		virtual void SpecialAbility() = 0;
		

	public:
		Enemies() = default;
		
		bool Setup(float x, float y, float vx, float vy, const std::string& texturePath, float scaleFactor);
		sf::Sprite Get() { return m_spriteShip; }
		void Move(float dt);
		float X() { return m_x; };
		float Y() { return m_y; };
		bool CheckCollisionEnemies(Ship& c2);

		virtual ~Enemies() {};

		

	};
}