#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <circle.hpp>
#include <Ship.hpp>

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

		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;
		sf::Font m_font;
		sf::Text m_fpsText;
		Ship m_ship;

	public:
		Game(int width, int height, const std::string &capture);
		bool Setup(int n);
		bool Game::CheckCollision(const Circle &other);
		void TouchBorder(Circle &obj);
		void LifeCycle();
		int N() { return m_n; }
	};
}