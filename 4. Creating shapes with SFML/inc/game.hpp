#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <circle.hpp>
#include <triangle.hpp>
#include <rectangle.hpp>
#include <line.hpp>

namespace ac
{

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		Circle *m_c;
		Triangle *m_t;
		Rectangle *m_r;
		Line *m_l;
		int m_n;

		sf::RenderWindow m_window;

	public:
		Game(int width, int height, const std::string &capture);
		void Setup(int n);
		void LifeCycle();
	};
}