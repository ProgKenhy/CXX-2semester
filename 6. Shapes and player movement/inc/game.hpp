#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <circle.hpp>

namespace ac
{

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		Circle *m_c;
		int m_n;
		sf::RenderWindow m_window;
		sf::ContextSettings m_settings;

	public:
		Game(int width, int height, const std::string &capture);
		void Setup(int n);
		bool Game::CheckCollision(const Circle &other);
		void TouchBorder(Circle &obj);
		void LifeCycle();
	};
}