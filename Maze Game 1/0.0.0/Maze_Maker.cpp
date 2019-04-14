#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "Template_Maze.h"
#include "Maze_Write_To_Binary.h"

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	
	maze m(x, y);
	
	char ch;
	
	do
		ch = cin.get();
	while (ch == '\n' || ch == '\r');
	
	bool is_changing = false;
	
	while (ch != '\n' && ch != '\r')
	{
		m.show();
		if (is_changing)
			m.make_ok();
		
		ch = getch();
		switch (ch)
		{
			case 'W':
			case 'w':
				m.move_user(go_up);
				break;
			
			case 'S':
			case 's':
				m.move_user(go_down);
				break;
			
			case 'A':
			case 'a':
				m.move_user(go_left);
				break;
			
			case 'D':
			case 'd':
				m.move_user(go_right);
				break;
			
			case 'Q':
				is_changing = (!is_changing);
				break;
			
			default: break;
		}
		system("CLS");
	}
	return 0;
}
