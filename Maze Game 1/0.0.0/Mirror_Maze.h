
// 这里是Maze_Game的第三章类定义 

#ifndef MIRROR_MAZE_H
#define MIRROR_MAZE_H 1

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
