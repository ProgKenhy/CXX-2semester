#pragma once
#include <SFML/Graphics.hpp>
#include <circle.hpp>

namespace ac
{
	class Bullet : public Circle
	{
		float m_r;
		float m_x, m_y;
		float m_vx;
		float m_vy;
		sf::CircleShape m_shape;
		bool is_available;


	public:
		Bullet() = default;
		Bullet(float x, float y, float r, float vx, float vy);
		void Setup(float x, float y, float r, float vx, float vy);
		void Move(float dt);
		bool CheckCollision(Circle& c2);
		void HandleCollision();
		sf::CircleShape Get();
		float X() { return m_x; }
		float Y() { return m_y; }
		void X(float x) { m_x = x; }
		void Y(float y) { m_y = y; }
		float VX() { return m_vx; }
		float VY() { return m_vy; }
		float R() { return m_r; }
		void VX(float vx) { m_vx = vx; }
		void VY(float vy) { m_vy = vy; }

	};
}