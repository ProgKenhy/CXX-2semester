#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>



namespace ac
{
	class SpaceObject
	{
	protected:
		float m_x = 0, m_y = 0;
		float m_vx = 0, m_vy = 0;
		float m_r = 0;
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