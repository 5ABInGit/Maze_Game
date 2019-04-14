
// 这里是Maze_Game进行玩游戏的函数定义 

#ifndef PART_INIT_H
#define PART_INIT_H 1

#include <cstdlib>
#include <iostream>

#include "Random_Maze.h"
#include "Hidden_Maze.h"
#include "Mirror_Maze.h"
#include "Player.h"
#include "Functions.h"

const char cards[5][11] = {
	"  ■■■",
	"■■■■■",
	"■■  ■■",
	"■■■■■",
	"  ■■■"
};

void play_part(const maze &m)
{
	
}

int basic_play_chapter(int chapter)
{
	system("CLS");
	
	for (int i = 0; i < 5; i++)
		cout << cards[i] << endl;
	
	int choose_maze = 1;
	char ch;
	
	while (true)
	{
		do
		{
			goto_xy(6, 3);
			cout << fixed << left;
			cout.fill('0');
			cout.width(2);
			cout << choose_maze;
			
			ch = getch();
			if (GetAsyncKeyState(VK_LEFT) && choose_maze != 1)
				choose_maze--;
			if (GetAsyncKeyState(VK_RIGHT) && choose_maze != mazes_each_chapter)
				choose_maze++;
			
			if (ch == '\n' || ch == '\r')
			{
				if (choose_maze == 1)
					break;
				if (Player_data.is_passed(choose_maze - 2))
					break;
			}
			
			time_stop(0.1);
		} while (true);
		
		char tmp[3];
		if (ch == '\r')
			cin.getline(tmp, 3);
		
		maze m;
		read_maze(m, chapter, choose_maze);
		
		if ()
		play_part(m);
		
	}
}

int _PG_4()
{
	return basic_play_chapter(1);
}

int _PG_5()
{
	return basic_play_chapter(2);
}

int _PG_6()
{
	return basic_play_chapter(3);
}

int _PG_7()
{
	return basic_play_chapter(4);
}

int _PG_8()
{
	return basic_play_chapter(5);
}

#endif
