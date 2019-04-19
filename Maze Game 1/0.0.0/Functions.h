
// 这里是Maze_Game的辅助函数定义 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void reset_random()
{
	srand(time(NULL) * 32940087u + 92137u);
}

void clean_buf()
{
	while (kbhit())
		getch();
	return;
}

void time_stop(double seconds)
{
	clock_t begin = clock () + CLOCKS_PER_SEC * seconds;
	while (begin > clock ());
	return;
}

int ranged_rand(int begin_pos, int end_pos)
{
	srand(time(NULL));
	
	int right_pos = rand(), range_count = end_pos - begin_pos + 1;
	int smallest = RAND_MAX / range_count;
	smallest *= range_count;
	
	while ((right_pos = rand()) < smallest);
	
	int ans = (right_pos % range_count) + begin_pos;
	
	return ans;
}

bool random_true(double probability)
{
	reset_random();
	
	int k = rand();
	if ((double(k) / RAND_MAX) < probability)
		return true;
	else
		return false;
}

void goto_xy (int x, int y)
{
	COORD ps;
	ps.X = SHORT(x), ps.Y = SHORT(y); // 强制类型转换 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ps);
}

void set_text_color(int color_base, int color_look)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
						  , color_base * 16 + color_look);
}

void set_screen_color(int color_base, int color_look)
{
	char a;
	string command("COLOR ");
	
	if (color_base >= 10)
		a = 'a' + color_base - 10;
	else
		a = '0' + color_base;
	
	command += a;
	
	if (color_look >= 10)
		a = 'a' + color_look - 10;
	else
		a = '0' + color_look;
	
	command += a;
	
	system(command.c_str());
	
	return;
}

void cls()
{
	system("CLS");
	return;
}

#endif
