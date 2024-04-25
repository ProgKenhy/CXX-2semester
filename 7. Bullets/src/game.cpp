#include <game.hpp>
#include <iostream>

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

	bool Game::Setup(int n)
	{

		m_n = n;
		srand(time(0));
		m_c = new Circle[m_n];

		if (!m_textureBackground.loadFromFile("assets\\background.jpg"))
		{
			std::cout << "Error while loading background.jpg" << std::endl;
			return false;
		}

		if (!m_font.loadFromFile("assets\\arial.ttf"))
			{
				std::cout << "Error while loading arial.ttf" << std::endl;
				return false;
			}
			m_fpsText.setFont(m_font);
			
		m_spriteBackground.setTexture(m_textureBackground);

		if (!m_ship.Setup(100, 100))
			return false;

		

		for (int i = 0; i < n; i++)
		{
			int r = rand() % 100 + 1;
			int x = rand() % (m_width - 2 * r) + r;
			int y = rand() % (m_height - 2 * r) + r;
			int vx = rand() % 10 + 50;
			int vy = rand() % 10 + 50;

			m_c[i].Setup(x, y, r, vx, vy, n);
			

			for (int j = 0; j < i; j++)
			{
				if ((m_c[i].CheckCollision(m_c[j])))
				{
					r = rand() % 100 + 1;
					x = rand() % (m_width - 2 * r) + r;
					y = rand() % (m_height - 2 * r) + r;
					m_c[i].Setup(x, y, r, vx, vy, n);
					j = -1;
				}
			}
		}
	}

	bool Game::TouchBorder(Circle &obj, float dt)
	{
		float x = obj.X();
		float y = obj.Y();
		float r = obj.R();
		float vx = obj.VX();
		float vy = obj.VY();
		x += vx * dt;
		y += vy * dt;

		if (x + r >= m_width)
		{
			obj.VX(-vx);
			obj.X(m_width - r);
			return true;
		}
		if (x - r <= 0)
		{
			obj.VX(-vx);
			obj.X(r);
			return true;
		}
		if (y + r >= m_height)
		{
			obj.VY(-vy);
			obj.Y(m_height - r);
			return true;
		}
		if (y - r <= 0)
		{
			obj.VY(-vy);
			obj.Y(r);
			return true;
		}

		return false;
	}

	void Game::LifeCycle()
	{
		sf::Clock clock;
		sf::Clock bullet_timeout_clock;

		
		

		m_window.setFramerateLimit(60);
		while (m_window.isOpen())
		{

			bullet_timeout += bullet_timeout_clock.getElapsedTime().asSeconds();

			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_ship.setVelocity(0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_ship.setVelocity(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_ship.Rotate(-2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_ship.Rotate(2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (bullet_timeout>1))
			{
				m_ship.Attack();
				bullet_timeout = 0;
				bullet_timeout_clock.restart();
			}

			
			 

			float dt = clock.getElapsedTime().asSeconds();
			clock.restart();

			m_fpsText.setString(std::to_string(1 / dt));

			m_ship.Move(dt);


			for (int i = 0; i < m_n; i++)
			{
				if(!TouchBorder(m_c[i], dt))
					m_c[i].Move(dt);


			}
				

			for (int i = 0; i < m_n; i++)
				for (int j = i + 1; j < m_n; j++)
					if (m_c[i].CheckCollision(m_c[j]))
						m_c[i].HandleCollision(m_c[j], i, j);

			m_window.clear();
			m_window.draw(m_spriteBackground);

			for (int i = 0; i < m_ship.GetNumberOfMaxBullets(); i++)
				m_window.draw(m_ship.GetBullet(i));
				
			m_window.draw(m_ship.Get());
			m_window.draw(m_fpsText);
			for (int i = 0; i < m_n; i++)
				m_window.draw(m_c[i].Get());
			
			
			m_window.display();
		}
	}
}
