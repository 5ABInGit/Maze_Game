
// ������Maze_Game�������� 
// ������������뿴ͬĿ¼�µ�Info.txt 

#include <cstddef>

#include "Page.h"
#include "Page_Graph_Init.h"

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
