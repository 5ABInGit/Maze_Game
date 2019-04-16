
// 这里是Maze_Game各个页面的函数定义 

#ifndef PAGE_GRAPH_INIT_H
#define PAGE_GRAPH_INIT_H 1

#include <iostream>
#include <cstdlib>
#include <string>

#include "Make_Graph.h"
#include "Login.h"
#include "Player.h"
#include "Page.h"
#include "Functions.h"
#include "Part_Init.h"

void is_choose(const int will_be, const int now)
{
	if (now == will_be)
		cout << ">>>|";
	else
		cout << "   |";
}

void cprt()
{
	cout << "*********************************************\n";
	cout << "**           欢迎来到迷宫游戏！            **\n";
	cout << "**        发布者：5AB。版本：v0.0.0        **\n";
	cout << "**           正在进行程序初始化            **\n";
	cout << "*********************************************\n";
	cout << "**                                         **\b\b";
	
	for (int i = 0; i < 70; i++)
	{
		time_stop(0.06);
		
		if (i == 0)
			system("TITLE 正在加载进度。。。"); 
		else if (i == 13)
			system("TITLE 正在加载迷宫内容。。。");
		else if (i == 37)
			system("TITLE 正在加载页面。。。");
		else if (i == 47)
			system("TITLE 加载完成，正在进入游戏。。。");
		
		for (int ttt = 0; ttt < 2 * 20; ttt++)
			cout << '\b';
		
		for (int j = 0; j < 20; j++)
			cout << (((i - j) % 13 == 0)? "0":"o") << " ";
	}
}

int _PG_0()
{
	string name = login ();
	char id[101] = {};
	
	cout << "[System] 登陆成功！正在提取玩家信息..." << endl;
	
	/* Get user's information */
	
	player::find_file(id, name);
	Player_data.reset_user(string(id));
	
	time_stop (1);
	cout << "[System] 信息提取成功，正在进行初始化..." << endl;
	
	/* Initialization random algorithms */
	time_stop (1);
	cout << "[System] 初始化成功，正在启动游戏..." << endl;
	
	/* Initialization Cards and Screens */
	time_stop (2);
	system ("CLS");
	
	return 1;
}

int _PG_1()
{
	int choose = 0;
	char ch;
	system("TITLE Maze_Game Choosing");
	
	do {
		system("CLS");
		cout << "你好！" << Player_data.user_name() << endl << endl;
		
		is_choose(0, choose);
		cout << "进入游戏" << endl;
		
		is_choose(1, choose);
		cout << "账户设置" << endl;
		
		ch = getch();
		if (GetAsyncKeyState(VK_UP) && choose == 1)
			choose = 0;
		else if (GetAsyncKeyState(VK_DOWN) && choose == 0)
			choose = 1;
		
	} while (ch != '\n' && ch != '\r');
	
	return choose + 2;
}

int _PG_2()
{
	int choose = 0;
	char ch;
	system("TITLE Maze_Game Choosing");
	
	do {
		
		system("CLS");
		cout << "请选择篇章：" << endl << endl;
		
		
		is_choose(0, choose);
		cout << "第一章：初出茅庐" << endl;
		
		is_choose(1, choose);
		cout << "第二章：移动世界" << endl;
		
		is_choose(2, choose);
		cout << "第三章：镜中奇缘" << endl;
		
		is_choose(3, choose);
		cout << "第四章：迷雾重重" << endl;
		
		is_choose(4, choose);
		cout << "第五章：密钥之巅" << endl;
		
		ch = getch();
		if (GetAsyncKeyState(VK_UP) && choose != 0)
			choose--;
		else if (GetAsyncKeyState(VK_DOWN) && choose != 4)
			choose++;
		else
			continue;
		
		time_stop(0.1);
		
	} while (ch != '\n' && ch != '\r');
	
	return choose + 4;
}

int _PG_3()
{
	int choose = 0;
	char ch;
	system("TITLE Maze_Game Choosing");
	
	do {
		
		system("CLS");
		cout << "请选择用户设置：" << endl << endl;
		
		is_choose(0, choose);
		cout << "1、用户信息" << endl;
		
		is_choose(1, choose);
		cout << "2、修改用户信息" << endl;
		
		is_choose(2, choose);
		cout << "3、注销账户" << endl;
		
		is_choose(3, choose);
		cout << "4、退出游戏" << endl;
		
		cout << endl;
		is_choose(4, choose);
		cout  << "返回上界面" << endl;
		
		ch = getch();
		if (GetAsyncKeyState(VK_UP) && choose != 0)
			choose--;
		else if (GetAsyncKeyState(VK_DOWN) && choose != 4)
			choose++;
		else
			continue;
		
		time_stop(0.1);
		
	} while (ch != '\n' && ch != '\r');
	
	return ((choose == 4)? 1:(choose + 9));
}

int _PG_9()
{
	system("TITLE Maze_Game Choosing");
	
	cout << Player_data << endl;
	return 3;
}

int _PG_10()
{
	system("TITLE Maze_Game Choosing");
	
	return 3;
}

int _PG_11()
{
	system("TITLE Maze_Game Choosing");
	
	return 0;
}

int _PG_12()
{
	system("TITLE 感谢您再次游玩！");
	
	program_log(Logout_log(Player_data.user_name()));
	exit(EXIT_SUCCESS);
	return 0;
}

void _PG_NoPage()
{
	system("CLS");
	cout << "您没有权限使用该功能或该界面未开发。" << endl;
	cout << "3秒后将返回上一页..." << endl;
	
	time_stop(3.0);
	return;
}

void graph_init()
{
	graph_structure_init();
	
	Maze_Game_Page_Graph.set_page_func(0, _PG_0);
	Maze_Game_Page_Graph.set_page_func(1, _PG_1);
	Maze_Game_Page_Graph.set_page_func(2, _PG_2);
	Maze_Game_Page_Graph.set_page_func(3, _PG_3);
	Maze_Game_Page_Graph.set_page_func(4, _PG_4);
	Maze_Game_Page_Graph.set_page_func(5, _PG_5);
	Maze_Game_Page_Graph.set_page_func(6, _PG_6);
	Maze_Game_Page_Graph.set_page_func(7, _PG_7);
	Maze_Game_Page_Graph.set_page_func(8, _PG_8);
	Maze_Game_Page_Graph.set_page_func(9, _PG_9);
	Maze_Game_Page_Graph.set_page_func(10, _PG_10);
	Maze_Game_Page_Graph.set_page_func(11, _PG_11);
	Maze_Game_Page_Graph.set_page_func(12, _PG_12);
	
	cprt();
	return;
}

#endif 
