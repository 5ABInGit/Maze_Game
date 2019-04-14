
// 这里是Maze_Game的页面关系布局 

#ifndef MAKE_GRAPH_H
#define MAKE_GRAPH_H

Page_Graph Maze_Game_Page_Graph;

static const int GRAPH_MATRIX_SIZE = 13;

bool is_connected[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE] = {
	
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	
};

void graph_structure_init()
{
	Page_Graph_Node * nd;
	for (int i = 0; i < GRAPH_MATRIX_SIZE; i++)
	{
		nd = new Page_Graph_Node;
		Maze_Game_Page_Graph.insert_page(nd);
	}
	
	for (int i = 0; i < GRAPH_MATRIX_SIZE; i++)
		for (int j = 0; j < GRAPH_MATRIX_SIZE; j++)
			if (is_connected[i][j])
				Maze_Game_Page_Graph.Graph_insert_edge(i, j);
}

#endif
