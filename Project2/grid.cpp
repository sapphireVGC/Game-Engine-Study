#include "grid.h"
#include <string>

grid::grid() {
}


grid::~grid() {
}

void grid::GridScreen(int gridSize, int cellSize) {
	int total = gridSize * cellSize;
	char c;

	for (int i = 0; i <= total; i++) {
		for (int j = 0; j <= total; j++) {
			if (i % cellSize == 0 || j % cellSize == 0)
				c = '*';
			else
				c = ' ';

			cout << c;	
		}

		cout << endl;
	}
}