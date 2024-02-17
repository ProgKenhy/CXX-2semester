#include <SFML/Graphics.hpp>
#include <circle.hpp>
#include <game.hpp>
#include <triangle.hpp>
#include <rectangle.hpp>
#include <line.hpp>

int main()
{

	ac::Game game(1000, 600, "!GAME!");
	int n = rand() % 9 + 1;
	game.Setup(n);
	game.LifeCycle();

	return 0;
}