#pragma once

#ifdef GAMESKELETON_EXPORTS
#define GAMESKELETON_API __declspec(dllexport)
#else
#define GAMESKELETON_API __declspec(dllimport)
#endif

class GAMESKELETON_API Coords
{
public:
	Coords(int x = 1, int y = 1) :x{ x }, y{ y } {}

	Coords(const Coords& obj) { x = obj.x; y = obj.y; }
	Coords& operator=(const Coords& obj) = default;

	Coords(Coords&& obj) = default;
	Coords& operator=(Coords&& obj) = default;

	~Coords() = default;

	int x;
	int y;
};
