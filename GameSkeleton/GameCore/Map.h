#pragma once

#ifdef GAMECORE_EXPORTS
#define GAMECORE_API __declspec(dllexport)
#else
#define GAMECORE_API __declspec(dllimport)
#endif

#include "MapProps.h"
#include "Player.h"

class GAMECORE_API Map
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

