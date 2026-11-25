#include <Windows.h>
#include <graphics.h>
#include <conio.h>
#include "game_config.h"
#include "board.h"

int main(int argc, char* argv[]) {
	init_chesboard();
	draw_chessboard();

	if (argc > 1 ) {
		if (strcmp(argv[1], "/client") == 0) {
			outtextxy(10, 10, L"Client mode selected");//use unicode string
		}
		else if (strcmp(argv[1], "/server") == 0){
			outtextxy(10, 10, L"Server mode selected");
		}
	}

	while (1) {
		if(MouseHit()) {
			MOUSEMSG mousemsg = GetMouseMsg();
			if (mousemsg.uMsg == WM_LBUTTONUP) {
				draw_chess(mousemsg.x, mousemsg.y, chesstype::black);
				FlushBatchDraw();
			}
		}
		Sleep(10);
	}	
	close_chessboard();

	return 0;
}
