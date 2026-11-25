#ifndef BOARD_H
#define BOARD_H

#include "game_config.h"

void init_chesboard();
void draw_chessboard(void);
void close_chessboard(void);
void draw_chess(int x, int y, chesstype color);

#endif

