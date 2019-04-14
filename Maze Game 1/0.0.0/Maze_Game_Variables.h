
#ifndef MAZE_GAME_VARIABLES_H
#define MAZE_GAME_VARIABLES_H

#include "Maze_Game_Macros.h"

struct ver_type
{
	int cal_one, cal_two, cal_thr;
};
ver_type V_Maze_Game_Ver;
unsigned long long Ver_Date = 20190205ull;

V_Maze_Game_Ver.cal_one = MAZE_GAME_VER_0;
V_Maze_Game_Ver.cal_two = MAZE_GAME_VER_1;
V_Maze_Game_Ver.cal_thr = MAZE_GAME_VER_2;

#endif
