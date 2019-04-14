
// 这里是Maze_Game的页面结构的结构体 & 类 

#ifndef PAGE_H
#define PAGE_H

#include <vector>
#include <cstddef>

using std::vector;

typedef struct
{
	int (*page_func)(void);
} page;

typedef struct
{
	page Pg;
	int Code;
	
	int use_func()
		{ return Pg.page_func(); }
} Page_Graph_Node;

class Page_Graph
{
	private:
		int node_count;
		vector<Page_Graph_Node *> nodes;
		vector<vector<bool> > Graph_Connect;
	
	public:
		Page_Graph() { node_count = 0; }
		~Page_Graph()
		{
			for (int i = 0; i < node_count; i++)
				delete nodes[i];
		}
		
		Page_Graph_Node * find_page(const int orig_code, const int cp) 
		{
			if (!Graph_Connect[orig_code][cp])
				return NULL;
			else
				return nodes[cp];
		}
		
		void set_page_func(const int page_code, int (*pf)(void))
		{
			nodes[page_code]->Pg.page_func = pf;
			return;
		}
		
		void insert_page(Page_Graph_Node * Nd)
		{
			vector<bool> v;
			for (int i = 0; i < node_count; i++)
				v.push_back(false);
			Graph_Connect.push_back(v);
			for (int i = 0; i <= node_count; i++)
				Graph_Connect[i].push_back(false);
			
			Nd->Code = node_count;
			nodes.push_back(Nd);
			node_count++;
			
			return;
		}
		
		void insert_page(const int will_connect, const int set_cp, Page_Graph_Node * Nd) 
		{
			insert_page(Nd);
			
			Nd->Code = node_count - 1;
			Graph_Connect[will_connect][Nd->Code] = true;
			return;
		}
		
		void Graph_insert_edge(const int from, const int to)
		{
			Graph_Connect[from][to] = true;
			return;
		}
		
		Page_Graph_Node * first_page() const
			{ return nodes[0]; }
};

#endif
