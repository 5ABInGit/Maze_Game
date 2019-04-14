
// 这里是Maze_Game迷宫的基类定义 

#ifndef TEMPLATE_MAZE_H
#define TEMPLATE_MAZE_H 1

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

#include "Player_Move_Maze.h"
#include "Functions.h"

using std::vector;

const int mazes_each_chapter = 20;
typedef vector<block_type> line_type;

struct basic_maze
{
	int len, wid;
	int user_x, user_y;
	int end_x, end_y;
	
	vector<line_type> m_state;
	
	basic_maze (int l = 1, int w = 1, int ux = 0, int uy = 0, int ex = 0, int ey = 0)
	{
		vector<block_type> mm;
		for (int i = 0; i < l; i++)
			mm.push_back(no_entry);
		
		for (int i = 0; i < w; i++)
			m_state.push_back(mm);
		
		len = l, wid = w, user_x = ux, user_y = uy, end_x = ex, end_y = ey;
	}
	
	bool move_user (toward pos)
	{
		user_x += place[pos][0];
		if (user_x < 0 || user_x >= wid)
		{
			user_x -= place[pos][0];
			return false;
		}
		
		user_y += place[pos][1];
		if (user_y < 0 || user_y >= len)
		{
			user_y -= place[pos][1];
			return false;
		}
		
		return true;
	}
	
	void reset_size(const int lenh, const int widh)
	{
		len = lenh;
		wid = widh;
		
		line_type lt;
		m_state.assign(widh, lt);
		
		for (vector<line_type>::iterator it = m_state.begin(); it < m_state.end(); it++)
			(*it).assign(lenh, no_entry);
		
		return;
	}
	
	bool is_at_end() const
	{
		if (user_x != end_x)
			return false;
		if (user_y != end_y)
			return false;
		
		return true;
	}
};

extern void write_maze(const maze &m, int chapter_count, int number_count);

class maze
{
	public:
		friend void user_controlor::reshow(const maze &m, toward pos);
		friend void write_maze(const maze &m, int chapter_count, int number_count);
		friend user_controlor::user_controlor(const maze &m);
	
	// 声明友元关系 
	
	private:
		basic_maze m_bm;
	
	public:
		
		maze(int l = 1, int w = 1, int ux = 0, int uy = 0, int ex = 0, int ey = 0)
		   : m_bm(l, w, ux, uy, ex, ey) { }
		
		maze(const maze & m) : m_bm(m.m_bm) { }
		
		~maze () { }
		
		void add_line(int line_count)
		{
			line_type lt;
			
			for (int i = 0; i < m_bm.m_state[0].size(); i++)
				lt.push_back(no_entry);
			
			for (int i = 0; i < line_count; i++)
				m_bm.m_state.push_back(lt);
		}
		
		void add_row(int row_count)
		{
			for (int ct = 0; ct < m_bm.m_state.size(); ct++)
				for (int i = 0; i < row_count; i++)
					m_bm.m_state[ct].push_back(no_entry);
		}
		
		const int length_of() const
			{ return m_bm.len; }
		const int width_of() const
			{ return m_bm.wid; }
		
		const int size() const
			{ return m_bm.len * m_bm.wid; }
		
		bool move_user(toward pos)
			{ return m_bm.move_user(pos); }
		
		void change_pos (int x, int y, block_type will_change)
			{ m_bm.m_state[x][y] = will_change; return; }
		
		void make_ok()
			{ change_pos(m_bm.user_x, m_bm.user_y, can_entry); }
		
		void change_pos (int x, int y)
		{
			if (m_bm.m_state[x][y] == no_entry)
				change_pos(x, y, can_entry);
			else
				change_pos(x, y, no_entry);
		}
		
		void change_pos()
			{ change_pos(m_bm.user_x, m_bm.user_y); }
		
		block_type & at (int x, int y)
			{ return m_bm.m_state[x][y]; }
		
		const block_type & at(int x, int y) const
			{ return m_bm.m_state[x][y]; }
		
		void reset_size(const int len, const int wid)
			{ m_bm.reset_size(len, wid); }
		
		bool is_at_end() const
			{ return m_bm.is_at_end(); }
		
		virtual void show() // 其余迷宫输出方法不同所以定义成虚函数 
		{
			for (int i = 0; i < m_bm.len; i++)
			{
				for (int j = 0; j < m_bm.wid; j++)
				{
					if (i == m_bm.user_x && j == m_bm.user_y)
					{
						set_text_color((m_bm.m_state[i][j] == no_entry)? 1:7, 6);
						std::printf("●");
					}
					else if (m_bm.m_state[i][j] == no_entry)
					{
						set_text_color(1, 1);
						std::putchar(' '); std::putchar(' ');
					}
					else
					{
						set_text_color(7, 7);
						std::putchar(' '); std::putchar(' ');
					}
				}
				
				set_text_color(0, 15);
				std::putchar('\n');
			}
		}
};

// user_controlor的剩余两个方法的定义 

user_controlor::user_controlor(const maze &m)
{
	user_x = m.m_bm.user_x; // 因为声明了友元所以可以直接访问 
	user_y = m.m_bm.user_y;
}

void user_controlor::reshow(const maze &m, toward pos)
{
	
}

#endif
