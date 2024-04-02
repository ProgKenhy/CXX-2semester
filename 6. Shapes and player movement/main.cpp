#include <circle.hpp>
#include <game.hpp>

int main()
{

	ac::Game game(1000, 600, "!GAME!");
	//int n = rand() % 6 + 4;
	int n = 20;
	game.Setup(n);
	game.LifeCycle();
	return 0;
}