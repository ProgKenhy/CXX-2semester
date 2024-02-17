#include <game.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace ac
{
	ac::Game::Game(int width, int height, const std::string &capture)
	{
		m_width = width;
		m_height = height;
		m_capture = capture;
		m_window.create(sf::VideoMode(m_width, m_height), m_capture);
	}

	void ac::Game::Setup(int n)
	{
		m_n = n;
		srand(time(0));
		m_c = new ac::Circle[m_n];
		m_t = new ac::Triangle[m_n];
		m_r = new ac::Rectangle[m_n];
		m_l = new ac::Line[m_n];
		for (int i = 0; i < n; i++)
		{
			int x = rand() % 800;
			int y = rand() % 400;
			int r = rand() % 100 + 1;
			m_c[i].Setup(x, y, r);
			m_t[i].Setup(x, y, r);
			m_r[i].Setup(x, y);
			m_l[i].Setup(x, y);
		}
	}

	void ac::Game::LifeCycle()
	{
		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();
				if (event.type == sf::Event::TextEntered)
				{
					if ((event.text.unicode == 'c') || (event.text.unicode == 't') || (event.text.unicode == 'r') || (event.text.unicode == 'l'))
					{
						m_window.clear();
						for (int i = 0; i < m_n; i++)
						{
							if (event.text.unicode == 'c')
								m_window.draw(m_c[i].Get());
							if (event.text.unicode == 't')
								m_window.draw(m_t[i].Get());
							if (event.text.unicode == 'r')
								m_window.draw(m_r[i].Get());
							if (event.text.unicode == 'l')
								m_window.draw(m_l[i].Get());
						}
						m_window.display();
					}
				}
			}
		}
	}
}