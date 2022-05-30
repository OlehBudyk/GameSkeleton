#include "Game.h"

int main()
{
	MapProps props(20, 20, 5, 10);
	Map map(props);
	Player player(Player::SKIN_PLAYER);

	Game game(props, &player, &map);

	game.play();
	game.showScore();

	return 0;
}