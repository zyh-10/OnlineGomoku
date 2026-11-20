#include <graphics.h>
#include <conio.h>
#include "game_config.h"
#include "board.h"

int main(int argc, char* argv[]) {
	initgraph(CANVAS_WIDTH, CANVAS_HEIGHT);
	setbkcolor(RGB(247, 207, 122));
	cleardevice();
	draw_chessboard();

	if (argc > 1 ) {
		if (strcmp(argv[1], "/client") == 0) {
			outtextxy(10, 10, L"Client mode selected");//use unicode string
		}
		else if (strcmp(argv[1], "/server") == 0){
			outtextxy(10, 10, L"Server mode selected");
		}
	}
	
	

	_getch();
	closegraph();
	return 0;
}
