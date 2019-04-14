
// 这里是Maze_Game记录玩家信息的类定义 

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <conio.h>

enum User_Type {Common_user = 0, Administator = 1};
enum Card_State {Not_Passed = 0, Passed = 1, Jumped = 2};
enum Random_Type {not_open, simple, easy, normal, hard, difficult, evolution};

typedef struct
{
	unsigned short tier, less;
	unsigned int total;
	
	void calculate_total()
	{
		
	}
	
} Exp_Type;

using std::string;
using std::FILE;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

string default_name("Admin");
class player
{
	private:
		
		string       username;
		User_Type    user_type;
		Exp_Type     user_xp;
		unsigned int money;
		Card_State   cards[100];
		Random_Type  rands;
		int          mob_diff;
		bool         is_open_surprise[5];
	
	public:
		
		player(const string & finfo, const string & name = default_name)
		{
			reset_user(finfo, name);
		}
		
		player() { }
		
		~player() { }
		
		void reset_user(const string & finfo, const string & name = default_name)
		{
			memset(cards, 0, sizeof(cards));
			username = name;
			
			char s;
			int tmp1;
			istringstream instr(finfo);
			
			instr >> tmp1;
			if (tmp1 == 0)
				user_type = Common_user;
			else
				user_type = Administator;
			instr.get();
			
			if (user_type = Common_user)
			{
				instr >> tmp1;
				user_xp.tier = tmp1;
				instr.get();
				
				instr >> tmp1;
				user_xp.less = tmp1;
				instr.get();
				
				user_xp.calculate_total();
			}
			
			instr >> money;
			instr.get();
			
			instr >> tmp1;
			for (int i = 0; i < tmp1; i++)
				cards[i] = Passed;
			instr.get();
			while (instr >> tmp1)
				cards[tmp1] = Jumped;
			instr.get();
		}
		
		static void find_file (char * info, const string & uname)
		{
			string filename = "Game_Data_Lib/Player_Info/" + uname + ".txt";
			FILE * file_to_user;
			if ((file_to_user = std::fopen (filename.c_str(), "r")) == NULL)
			{
				cerr << "[System] Error: 无法打开玩家信息文件位于 "
					 << filename << endl;
				
				std::exit (EXIT_FAILURE);
			}
			std::fgets (info, 101, file_to_user);
			std::fclose (file_to_user);
		}
		
		const string user_name () const
		{ return username; }
		
		const Exp_Type xp () const
		{ return user_xp; }
		
		const int user_money () const
		{ return money; }
		
		const bool is_passed (int card_index) const
		{
			if (card_index < 0 || card_index >= 100)
				return false;
			
			if (cards[card_index] == Passed)
				return true;
			return false;
		}
		
		const bool is_jumped (int card_index) const
		{
			if (card_index < 0 || card_index >= 100)
				return false;
			
			if (cards[card_index] == Jumped)
				return true;
			return false;
		}
		
		const Random_Type rand_type() const
		{ return rands; }
		
		const int mob_difficult () const
		{ return mob_diff; }
		
		friend std::ostream & operator<< (std::ostream & os, const player & pl)
		{
			system("CLS");
			
			os << "[System] 以下为" << pl.username << "的用户信息" << endl;
			os << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			os << "[System] 用户类型：";
			
			if (pl.user_type == Administator)
				os << "管理员" << endl;
			else
				os << "普通用户" << endl;
			
			os << "[System] 玩家经验：" << pl.user_xp.tier << "级" << endl;
			os << "[System] 金钱：    " << pl.money << "$" << endl << endl;
			os << "[System] 按任意键返回上一页..." << endl;
			
			getch();
			return (os);
		}
};

player Player_data;

#endif
