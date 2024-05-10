#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>



namespace ac
{
	class SpaceObject
	{
	protected:
		float m_x, m_y;
		float m_vx, m_vy;
		float m_r;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;

	public:
		SpaceObject() = default;
		virtual ~SpaceObject() {};
		bool Setup(float x, float y, float vx, float vy, const std::string& texturePath, float scaleFactor);
		sf::Sprite Get() { return m_spriteShip; }
		void Move(float dt);
		virtual void Attack() = 0;
		virtual void SpecialAbility() = 0;
		
	};
}