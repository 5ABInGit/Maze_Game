
// ������Maze_Game�ĵ������ඨ�� 

#ifndef MIRROR_MAZE_H
#define MIRROR_MAZE_H 1

#include "Template_Maze.h" 
#include <vector>

enum mirror_type {glass, mirror};

class mirror_maze : public maze
{
	std::vector<mirror_type> Mirror;
	
	public:
		
		virtual void show()
		{
			
		}
};

#endif
