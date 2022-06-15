#pragma once

#ifdef GAMECORE_EXPORTS
#define GAMECORE_API __declspec(dllexport)
#else
#define GAMECORE_API __declspec(dllimport)
#endif

#include <vector>
#include "MapProps.h"

using uchar = unsigned char;

class GAMECORE_API MapSketch
{
private:
	int m_rows;
	int m_columns;

	std::vector<std::vector<uchar>> m_map;
public:
	MapSketch(int rowCount, int columnCount);
	MapSketch(MapProps props);

	uchar at(int row, int column) const;

#ifdef _DEBUG
	void draw();
#endif // DEBUG

};
