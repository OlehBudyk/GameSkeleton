#pragma once

#ifdef GAMESKELETON_EXPORTS
#define GAMESKELETON_API __declspec(dllexport)
#else
#define GAMESKELETON_API __declspec(dllimport)
#endif

#include <vector>

//#include "Vector.h"
#include "MapProps.h"
#include "Player.h"
#include "Map.h"

class GAMESKELETON_API Game
{
private:
	Map* m_map;
	Player* m_player;

	MapProps m_props;
	bool m_isGameActive = true;
	//custom::Vector<Player> m_bots;
	std::vector<Player> m_bots;
	int m_score = 0;

	const static char MOVE_UP = 'w';
	const static char MOVE_DOWN = 's';
	const static char MOVE_LEFT = 'a';
	const static char MOVE_RIGHT = 'd';

public:
	Game(MapProps props, Player* const player, Map* const map);

	void play();
	void showScore();

private:
	void loadBot();

	void doStep(Player& player, char moved);
	void updateBotsPos();
	void doPlayerStep();

	bool isPlayerCatched();
};
