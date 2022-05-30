#pragma once

#ifdef GAMECORE_EXPORTS
#define GAMECORE_API __declspec(dllexport)
#else
#define GAMECORE_API __declspec(dllimport)
#endif

class GAMECORE_API MapProps
{
public:
	int m_rows;
	int m_columns;

	int m_vertical_space_count;
	int m_horizontal_space_count;

	const static char SPACE_SYMBOL = ' ';
	const static char WALL_SYMBOL = '#';

	const static char HERO_SYMBOL = 2;
	const static char ENEMY_SYMBOL = 1;

	MapProps(int rows, int columns, int verticalSpace, int horizontalSpace)
		: m_rows{ rows }
		, m_columns{ columns }
		, m_vertical_space_count{ verticalSpace }
		, m_horizontal_space_count{ horizontalSpace }
	{}
};
