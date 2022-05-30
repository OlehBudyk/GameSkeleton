#pragma once

#ifdef GAMESKELETON_EXPORTS
#define GAMESKELETON_API __declspec(dllexport)
#else
#define GAMESKELETON_API __declspec(dllimport)
#endif

#include "MapProps.h"
#include "Player.h"

class GAMESKELETON_API Map
{
private:

	friend class Game;

	char** m_map = nullptr;
	MapProps m_props;

	Player* m_player = nullptr;
public:

	Map(MapProps props);
	void redraw();
	~Map();

private:

	void updatePlayerPos(const Player& player, const Coords& oldPlayerPos);
	void loadPlayer(Player* const player);
	
	bool isStepPossible(const Coords& coords);
	bool isEnemy(const Coords& coords);
};

