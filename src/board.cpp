#include "board.h"
#include "game_config.h"
#include <graphics.h>

static chesstype board[BOARD_SIZE][BOARD_SIZE] = { { chesstype::empty } ,{ chesstype::empty } };//initialize with full empty
static int move_count = 0;

void init_chesboard() {
	initgraph(CANVAS_WIDTH, CANVAS_HEIGHT);
	BeginBatchDraw();
	setbkcolor(RGB(247, 207, 122));
	cleardevice();
	FlushBatchDraw();
}

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
	FlushBatchDraw();
}

void close_chessboard(void) {
	EndBatchDraw();
	closegraph();
}

void draw_chess(int x, int y, chesstype color) {
	int row = (y - ORIGIN + CELL_SIZE / 2) / CELL_SIZE;
	int col = (x - ORIGIN + CELL_SIZE / 2) / CELL_SIZE;

	int cx = ORIGIN + col * CELL_SIZE;
	int cy = ORIGIN + row * CELL_SIZE;
	if (abs(x - cx) > CELL_SIZE / 2 || abs(y - cy) > CELL_SIZE / 2)
		return ;

	if (row<0 || row>BOARD_SIZE || col<0 || col>BOARD_SIZE || board[row][col] != chesstype::empty)
		return;

	switch (color) {
		case chesstype::black:
		{
			setfillcolor(BLACK);
			break;
		}
		case chesstype::white:
		{
			setfillcolor(WHITE);
			break;
		}
		default:return;
	}

	board[row][col] = color;
	move_count++;

	fillcircle(cx, cy, CHESS_R);
}

