#include <iostream>

#include "Map.h"

Map::Map(MapProps props)
	: m_props{ props }
{
	m_map = new char* [m_props.m_rows];
	for (int i = 0; i < m_props.m_rows; i++)
		m_map[i] = new char[m_props.m_columns];

	//first row
	for (int k = 0; k < m_props.m_columns - 1; k++)
		m_map[0][k] = MapProps::WALL_SYMBOL;

	m_map[0][m_props.m_columns - 1] = '\0';

	//last row
	for (int k = 0; k < m_props.m_columns - 1; k++)
		m_map[m_props.m_rows - 1][k] = MapProps::WALL_SYMBOL;

	m_map[m_props.m_rows - 1][m_props.m_columns - 1] = '\0';

	//middle rows
	for (int i = 1; i < m_props.m_rows - 1; i++)
	{
		for (int k = 0; k < m_props.m_columns - 1; k++)
			if (k == 0 || k == m_props.m_columns - 2)
				m_map[i][k] = MapProps::WALL_SYMBOL;
			else
				m_map[i][k] = ' ';
		m_map[i][m_props.m_columns - 1] = '\0';
	}
}

void Map::redraw()
{
	for (int i = 0; i < m_props.m_vertical_space_count; i++)
		std::cout << std::endl;

	for (int i = 0; i < m_props.m_rows; i++)
	{
		for (int i = 0; i < m_props.m_horizontal_space_count; i++)
			std::cout << ' ';

		for (int k = 0; k < m_props.m_columns - 1; k++)
			std::cout << m_map[i][k];
		std::cout << std::endl;
	}
}

Map::~Map()
{
	for (int i = 0; i < m_props.m_rows; i++)
		delete[] m_map[i];

	delete[] m_map;
}


void Map::updatePlayerPos(const Player& player, const Coords& oldPlayerPos)
{
	m_map[oldPlayerPos.x][oldPlayerPos.y] = MapProps::SPACE_SYMBOL;

	Coords coords = player.getPosition();
	m_map[coords.x][coords.y] = player.getSkin();
}
void Map::loadPlayer(Player* const player)
{
	updatePlayerPos(*player, player->getPosition());
};

bool Map::isStepPossible(const Coords& coords)
{
	return m_map[coords.x][coords.y] == MapProps::SPACE_SYMBOL;
}

bool Map::isEnemy(const Coords& coords)
{
	return m_map[coords.x][coords.y] == MapProps::ENEMY_SYMBOL;
}
