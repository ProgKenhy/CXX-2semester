#include <game.hpp>

namespace ac
{
	const float pi = acos(-1);

	Game::Game(int width, int height, const std::string &capture)
	{
		m_settings.antialiasingLevel = 8;
		m_width = width;
		m_height = height;
		m_capture = capture;
		m_window.create(sf::VideoMode(m_width, m_height), m_capture);
	}

	void Game::Setup(int n)
	{
		m_n = n;
		srand(time(0));
		m_c = new Circle[m_n];
		for (int i = 0; i < n; i++)
		{
			int r = rand() % 100 + 1;
			int x = rand() % (m_width - 2 * r) + r;
			int y = rand() % (m_height - 2 * r) + r;
			int vx = rand() % 150+50;
			int vy = rand() % 150+50;
			m_c[i].Setup(x, y, r, vx, vy);
			for (int j = 0; j < i; j++)
			{
				if (m_c[i].CheckCollision(m_c[j]))
				{
					r = rand() % 100 + 1;
					x = rand() % (m_width - 2 * r) + r;
					y = rand() % (m_height - 2 * r) + r;
					m_c[i].Setup(x, y, r, vx, vy);
					j = -1;
				}
			}
		}
	}

	void Game::TouchBorder(Circle &obj)
	{
		float x = obj.X();
		float y = obj.Y();
		float r = obj.R();
		float vx = obj.VX();
		float vy = obj.VY();

		if (x + r >= m_width)
		{
			obj.X(m_width - r);
			obj.VX(-vx);
		}
		if (x - r <= 0)
		{
			obj.X(r);
			obj.VX(-vx);
		}
		if ((y + r >= m_height) || (y - r <= 0))
		{
			obj.Y(m_height - r);
			obj.VY(-vy);
		}
		if (y - r <= 0)
		{
			obj.Y(r);
			obj.VY(-vy);
		}
	}

	void Game::LifeCycle()
	{
		sf::Clock clock;
		m_window.setFramerateLimit(60);
		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();
			}
			float dt = clock.getElapsedTime().asSeconds();
			clock.restart();

			for (int i = 0; i < m_n; i++)
				m_c[i].Move(dt);

			for (int i = 0; i < m_n; i++)
				TouchBorder(m_c[i]);
			for (int i = 0; i < m_n; i++)
			{
				for (int j = i + 1; j < m_n; j++)
				{
					if (m_c[i].CheckCollision(m_c[j]))
					{
						m_c[i].HandleCollision(m_c[j]);
					}
				}
			}
			m_window.clear();
			for (int i = 0; i < m_n; i++)
				m_window.draw(m_c[i].Get());
			m_window.display();
		}
	}
}
