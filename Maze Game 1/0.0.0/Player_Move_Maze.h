
// 这里是Maze_Game的玩家操控处 

#ifndef PLAYER_MOVE_MAZE_H
#define PLAYER_MOVE_MAZE_H 1

enum toward {go_left = 0, go_right = 1, go_up = 2, go_down = 3};
enum block_type {no_entry = 0, can_entry = 1};

const int place[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// 前置声明，保证user_controlor类可以识别到maze类 
// 该类将会在0.x加入（暂时不使用） 
class user_controlor
{
	private:
		maze *m;
	
	public:
		user_controlor() : m(NULL) { }
		user_controlor(maze *_m)
			{ m = _m; }
		
		~user_controlor() { }
		
		void reconnect(maze *_m)
			{ m = _m; }
		
		void reshow(toward pos);
		// 为了不使迷宫加载导致屏幕闪烁 
};

// user_controlor其余两个方法放在maze类声明完成后再定义。
// 为的是声明友元关系 

#endif

//这个程序将会被Template_Maze.h所包含。 
