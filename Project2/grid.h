#pragma once
#include <iostream>
#include <string>

using namespace std;

class grid final {
public:
	grid();
	~grid();

	void GridScreen(int gridSize, int cellSize);
};

