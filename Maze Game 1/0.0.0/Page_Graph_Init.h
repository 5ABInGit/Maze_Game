
// ������Maze_Game����ҳ��ĺ������� 

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
	cout << "**           ��ӭ�����Թ���Ϸ��            **\n";
	cout << "**        �����ߣ�5AB���汾��v0.0.0        **\n";
	cout << "**           ���ڽ��г����ʼ��            **\n";
	cout << "*********************************************\n";
	cout << "**                                         **\b\b";
	
	for (int i = 0; i < 70; i++)
	{
		time_stop(0.06);
		
		if (i == 0)
			system("TITLE ���ڼ��ؽ��ȡ�����"); 
		else if (i == 13)
			system("TITLE ���ڼ����Թ����ݡ�����");
		else if (i == 37)
			system("TITLE ���ڼ���ҳ�档����");
		else if (i == 47)
			system("TITLE ������ɣ����ڽ�����Ϸ������");
		
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
	
	cout << "[System] ��½�ɹ���������ȡ�����Ϣ..." << endl;
	
	/* Get user's information */
	
	player::find_file(id, name);
	Player_data.reset_user(string(id), name);
	
	time_stop (1);
	cout << "[System] ��Ϣ��ȡ�ɹ������ڽ��г�ʼ��..." << endl;
	
	/* Initialization random algorithms */
	time_stop (1);
	cout << "[System] ��ʼ���ɹ�������������Ϸ..." << endl;
	
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
		cout << "��ã�" << Player_data.user_name() << endl << endl;
		
		is_choose(0, choose);
		cout << "������Ϸ" << endl;
		
		is_choose(1, choose);
		cout << "�˻�����" << endl;
		
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
		cout << "��ѡ��ƪ�£�" << endl << endl;
		
		
		is_choose(0, choose);
		cout << "��һ�£�����é®" << endl;
		
		is_choose(1, choose);
		cout << "�ڶ��£��ƶ�����" << endl;
		
		is_choose(2, choose);
		cout << "�����£�������Ե" << endl;
		
		is_choose(3, choose);
		cout << "�����£���������" << endl;
		
		is_choose(4, choose);
		cout << "�����£���Կ֮��" << endl;
		
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
		cout << "��ѡ���û����ã�" << endl << endl;
		
		is_choose(0, choose);
		cout << "1���û���Ϣ" << endl;
		
		is_choose(1, choose);
		cout << "2���޸��û���Ϣ" << endl;
		
		is_choose(2, choose);
		cout << "3��ע���˻�" << endl;
		
		is_choose(3, choose);
		cout << "4���˳���Ϸ" << endl;
		
		cout << endl;
		is_choose(4, choose);
		cout  << "�����Ͻ���" << endl;
		
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
	system("TITLE ��л���ٴ����棡");
	
	program_log(Logout_log(Player_data.user_name()));
	exit(EXIT_SUCCESS);
	return 0;
}

void _PG_NoPage()
{
	system("CLS");
	cout << "��û��Ȩ��ʹ�øù��ܻ�ý���δ������" << endl;
	cout << "3��󽫷�����һҳ..." << endl;
	
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
