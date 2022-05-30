#include <conio.h>
#include <random>
#include <iostream>

//#include "Vector.h"
#include "Game.h"

namespace
{
	Coords generateCoords(MapProps props)
	{
		int x = 1 + std::rand() % (props.m_rows - 2);
		int y = 1 + std::rand() % (props.m_columns - 2);

		return Coords{ x,y };
	}
}

Game::Game(MapProps props, Player* const player, Map* const map)
	: m_props{ props }, m_player{ player }, m_map{ map }
{
	m_bots.reserve(200);
	m_map->loadPlayer(player);
}


void Game::loadBot()
{
	Coords botCoords = ::generateCoords(m_props);

	while (!m_map->isStepPossible(botCoords))
		botCoords = ::generateCoords(m_props);

	auto botSize = m_bots.size();

	/*if (m_bots.size() < m_bots.reserved())
		m_bots.pushBack(Player{ Player::SKIN_ENEMY, botCoords });
	else
		int a = 0;*/

	m_bots.push_back(Player{ Player::SKIN_ENEMY, botCoords });

	m_map->updatePlayerPos(m_bots.back(), botCoords);
}

void Game::play()
{
	try
	{
		int botCounter = 1;
		do
		{
			system("cls");

			m_map->redraw();
			doPlayerStep();

			if (botCounter % 4 == 0)
				loadBot();
			updateBotsPos();

			botCounter++;
			m_score++;
			m_isGameActive = !isPlayerCatched();
		} while (m_isGameActive);
	}
	catch (const std::string& msg)
	{
		system("cls");
		std::cout << msg;
	}
	catch (...)
	{
		system("cls");
		std::cout << "the excaption has been catched";
	}
}

void Game::showScore()
{
	system("cls");

	for (int i = 0; i < m_props.m_vertical_space_count; i++)
		std::cout << std::endl;

	for (int i = 0; i < m_props.m_horizontal_space_count; i++)
		std::cout << " ";

	std::cout << "SCORE = " << m_score;

	_getch();
}

bool Game::isPlayerCatched()
{
	const Coords currPlayerPos = m_player->getPosition();

	if (m_map->isEnemy(Coords{ currPlayerPos.x + 1, currPlayerPos.y })
		||
		m_map->isEnemy(Coords{ currPlayerPos.x - 1, currPlayerPos.y })
		||
		m_map->isEnemy(Coords{ currPlayerPos.x, currPlayerPos.y + 1 })
		||
		m_map->isEnemy(Coords{ currPlayerPos.x, currPlayerPos.y - 1 }))
		return true;

	return false;
}

void Game::doStep(Player& player, char moved)
{
	const Coords currPlayerPos = player.getPosition();
	Coords newPlayerPos = currPlayerPos;

	switch (moved)
	{
	case Game::MOVE_UP: {newPlayerPos.x--; }break;
	case Game::MOVE_DOWN: {newPlayerPos.x++; }break;
	case Game::MOVE_LEFT: {newPlayerPos.y--; }break;
	case Game::MOVE_RIGHT: {newPlayerPos.y++; }break;
	default:break;
	}

	if (m_map->isStepPossible(newPlayerPos))
	{
		player.setPosition(newPlayerPos);
		m_map->updatePlayerPos(player, currPlayerPos);
	}
}

void Game::updateBotsPos()
{
	auto generateStep = []()
	{
		const int stepDirrection = std::rand() % 4;

		char moved;
		switch (stepDirrection)
		{
		case 0:moved = MOVE_UP; break;
		case 1:moved = MOVE_DOWN; break;
		case 2:moved = MOVE_LEFT; break;
		case 3:moved = MOVE_RIGHT; break;
		default:break;
		}

		return moved;
	};

	for (auto& player : m_bots)
		doStep(player, generateStep());
}

void Game::doPlayerStep()
{
	bool isStepPressed = false;

	do
	{
		if (!_kbhit())
			continue;

		isStepPressed = true;

		doStep(*m_player, static_cast<char>(_getch()));

	} while (!isStepPressed);

}
