
// 这里是Maze_Game的主程序 
// 具体编译事项请看同目录下的Info.txt 

#include "Maze_Game_Public_Library.h"
using namespace std;

int main()
{
	graph_init();
	
	int cp;
	Page_Graph_Node * Np = Maze_Game_Page_Graph.first_page(), *Bef;
	
	while (true)
	{
		cp = Np->use_func();
		Bef = Np;
		Np = Maze_Game_Page_Graph.find_page(Np->Code, cp);
		
		if (Np == NULL)
		{
			_PG_NoPage();
			Np = Bef;
			continue;
		}
	}
	
	return 0;
}
