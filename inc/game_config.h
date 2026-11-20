#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

/*configuration of chessboard*/
constexpr int CANVAS_WIDTH = 640;  // window width
constexpr int CANVAS_HEIGHT = 640; // window height
constexpr int BOARD_SIZE = 15;   // 15×15 chessboard
constexpr int CELL_SIZE = 40;   // pixel size of each cell
constexpr int ORIGIN = 40;	  // pixel coordinate of the origin point

/*configuration of game*/
enum class chesstype{empty=0,black,white};
enum class gamestate{playing=0,black_win,white_win};

#endif // GAME_CONFIG_H
