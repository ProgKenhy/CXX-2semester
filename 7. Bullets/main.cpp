#include <circle.hpp>
#include <game.hpp>

int main()
{

	ac::Game game(1920, 1080, "!GAME!");
	// int n = rand() % 6 + 4;
	int n = 50;
	game.Setup(n);
	game.LifeCycle();
	return 0;
}