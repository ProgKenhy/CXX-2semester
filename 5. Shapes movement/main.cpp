#include <circle.hpp>
#include <game.hpp>

int main()
{

	ac::Game game(1000, 600, "!GAME!");
	//int n = rand() % 6 + 4;
	int n = 10;
	game.Setup(n);
	game.LifeCycle();
	return 0;
}