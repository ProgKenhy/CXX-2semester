#pragma once
#include <SFML/Graphics.hpp>
#include <bullet.hpp>


namespace ac
{
	class Ship
	{
		const int m_bulletR = 10;
		float m_v_bullet = 400;
		const int number_of_max_bullets = 30;
		int current_bullet = 0;


		float m_x = 0, m_y = 0;
		float m_alpha = 0;
		float m_v = 0;
		float m_r = 0;
		float m_scaleFactor = 0.2f;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;
		Bullet *m_bullet;


	public:
		Ship() = default;
		Ship(float x, float y);
		bool Setup(float x, float y);
		void setVelocity(float dv, float dt);
		void Move(float dt);
		void Rotate(float dalpha, float dt);
		sf::Sprite Get(){ return m_spriteShip; }
		void Attack();
		sf::CircleShape GetBullet(int i) { return m_bullet[i].Get(); };
		bool IsBulletHit(Circle& c, int i) {return m_bullet[i].CheckCollision(c); }
		void HandleHit(int i) { m_bullet[i].HandleCollision(); }
		void TouchBorder(int width, int height);
		int GetNumberOfMaxBullets() {return number_of_max_bullets;}
		~Ship() { delete[] m_bullet; }
		int X() { return m_x; };
		int Y() { return m_y; };
		int R() { return m_r; };
	};
}