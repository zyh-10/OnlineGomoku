#include "board.h"
#include "game_config.h"
#include <graphics.h>

void draw_chessboard(void) {
	setcolor(BLACK);
	for (int i = 0;i < BOARD_SIZE;i++) {
		line(ORIGIN, ORIGIN + i * CELL_SIZE, ORIGIN + (BOARD_SIZE - 1) * CELL_SIZE, ORIGIN + i * CELL_SIZE);// horizontal lines
		line(ORIGIN + i * CELL_SIZE, ORIGIN, ORIGIN + i * CELL_SIZE, ORIGIN + (BOARD_SIZE - 1) * CELL_SIZE);// vertical lines
	}

	setfillcolor(BLACK);
	int stars[][2] = {
		{ 3, 3 },{ 3, 11 },{ 7, 7 },{ 11, 3 },{ 11, 11 }
	};
	for (auto& s : stars) {
		int x = ORIGIN + s[0] * CELL_SIZE;
		int y = ORIGIN + s[1] * CELL_SIZE;
		fillcircle(x, y, 4);  // radius: 4 pixels
	}
}