
#ifndef MAZE_GAME_VARIABLES_H
#define MAZE_GAME_VARIABLES_H

struct ver_type
{
	int cal_one, cal_two, cal_thr;
	
	ver_type() : cal_one(MAZE_GAME_VER_0), cal_two(MAZE_GAME_VER_1)
			   , cal_thr(MAZE_GAME_VER_2) { }
};
const ver_type V_Maze_Game_Ver;
unsigned long long Ver_Date = 20190205ull;

#endif
