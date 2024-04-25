#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <bullet.hpp>
#include <vector>

namespace ac
{
	class Ship
	{
		const int m_bulletR = 10;
		float m_v_bullet = 400;
		const int number_of_max_bullets = 30;
		int current_bullet;


		float m_x, m_y;
		float m_alpha;
		float m_v;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;
		Bullet *m_bullet;

	public:
		Ship() = default;
		Ship(float x, float y);
		bool Setup(float x, float y);
		void setVelocity(float dv);
		void Move(float dt);
		void Rotate(float dalpha);
		sf::Sprite Get(){ return m_spriteShip; }
		void Attack();
		sf::CircleShape GetBullet(int i) { return m_bullet[i].Get(); };
		bool IsBulletHit(Circle& c, int i) {return m_bullet[i].CheckCollision(c); }
		void HandleHit(int i) { m_bullet[i].HandleCollision(); }
		void TouchBorder(int width, int height);
		int GetNumberOfMaxBullets() {return number_of_max_bullets;}
		~Ship() { delete[] m_bullet; }
	};
}