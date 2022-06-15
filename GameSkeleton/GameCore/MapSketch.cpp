#ifdef _DEBUG
#include <iostream>
#endif // DEBUG

#include "MapSketch.h"

MapSketch::MapSketch(int rowCount, int columnCount) :
	m_rows{ rowCount },
	m_columns{ columnCount }
{
	m_map.resize(m_rows);

	m_map.front() = std::vector<uchar>(m_columns, MapProps::WALL_SYMBOL);
	m_map.back() = std::vector<uchar>(m_columns, MapProps::WALL_SYMBOL);

	for (int i = 1; i < m_rows - 1; i++)
	{
		std::vector<uchar> tempVec(m_columns, MapProps::SPACE_SYMBOL);
		tempVec.front() = MapProps::WALL_SYMBOL;
		tempVec.back() = MapProps::WALL_SYMBOL;

		m_map[i] = std::move(tempVec);
	}
}

MapSketch::MapSketch(MapProps props) :
	MapSketch(props.m_rows, props.m_columns)
{}

uchar MapSketch::at(int row, int column) const
{
	return m_map[row][column];
}

#ifdef _DEBUG
void MapSketch::draw()
{
	for (const auto& row : m_map)
	{
		for (const auto symbol : row)
			std::cout << symbol;

		std::cout << std::endl;
	}
}
#endif // DEBUG
