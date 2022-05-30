#pragma once

#ifdef GAMECORE_EXPORTS
#define GAMECORE_API __declspec(dllexport)
#else
#define GAMECORE_API __declspec(dllimport)
#endif

#include "AdditionalClasses.h"

class GAMECORE_API Player
{
public:
	const static char SKIN_PLAYER = 2;
	const static char SKIN_ENEMY = 1;
private:
	Coords m_position;
	char m_skin;
public:
	Player(char skin = Player::SKIN_ENEMY, Coords coords = Coords()) :m_skin{ skin }, m_position{ coords } {}

	char getSkin() const { return m_skin; }

	Coords getPosition() const { return m_position; }
	void setPosition(const Coords& pos) { m_position = pos; }

};
