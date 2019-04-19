
#ifndef MAZE_GAME_VARIABLES_H
#define MAZE_GAME_VARIABLES_H

// 这里是Maze_Game公共全局变量声明处 

struct ver_type
{
	int cal_one, cal_two, cal_thr;
	
	ver_type() : cal_one(MAZE_GAME_VER_0), cal_two(MAZE_GAME_VER_1)
			   , cal_thr(MAZE_GAME_VER_2) { }
};
const ver_type V_Maze_Game_Ver;
unsigned long long Ver_Date = 20190205ull;

HWND con;
HANDLE inp, outp;

class maze;
class player;
class user_controlor;
class Page_Graph;

#endif
