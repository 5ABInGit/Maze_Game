
// ������Maze_Game��¼�����Ϣ���ඨ�� 

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <conio.h>

enum User_Type {Common_user = 0, Administrator = 1};
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
		
		struct basic_player
		{
			char         username[21];
			char         password[21];
			User_Type    user_type;
			Exp_Type     user_xp;
			unsigned int money;
			Card_State   cards[100];
			Random_Type  rands;
			int          mob_diff;
			bool         decision[100];
		};
		
		basic_player bp;
	
	public:
		
		void reset_user(const string & finfo)
		{
			std::istringstream istr(finfo);
			istr.read((char *)&bp, sizeof(bp));
			return;
		}
		
		player(const string & finfo)
			{ reset_user(finfo); }
		
		player() { }
		
		~player() { }
		
		static void find_file (char * info, const string & uname)
		{
			string filename = "Game_Data_Lib/Player_Info/" + uname + ".txt";
			FILE * file_to_user;
			if ((file_to_user = std::fopen (filename.c_str(), "r")) == NULL)
			{
				cerr << "[System] Error: �޷��������Ϣ�ļ�λ�� "
					 << filename << endl;
				
				std::exit (EXIT_FAILURE);
			}
			std::fgets (info, 101, file_to_user);
			std::fclose (file_to_user);
		}
		
		const string user_name () const
		{ return bp.username; }
		
		const Exp_Type xp () const
		{ return bp.user_xp; }
		
		const unsigned int user_money () const
		{ return bp.money; }
		
		const bool is_passed (int card_index) const
		{
			if (card_index < 0 || card_index >= 100)
				return false;
			
			if (bp.cards[card_index] == Passed)
				return true;
			return false;
		}
		
		const bool is_jumped (int card_index) const
		{
			if (card_index < 0 || card_index >= 100)
				return false;
			
			if (bp.cards[card_index] == Jumped)
				return true;
			return false;
		}
		
		const Random_Type rand_type() const
		{ return bp.rands; }
		
		const int mob_difficult () const
		{ return bp.mob_diff; }
		
		friend std::ostream & operator<< (std::ostream & os, const player & pl)
		{
			system("CLS");
			
			os << "[System] ����Ϊ" << pl.bp.username << "���û���Ϣ" << endl;
			os << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			os << "[System] �û����ͣ�";
			
			if (pl.bp.user_type == Administrator)
				os << "����Ա" << endl;
			else
				os << "��ͨ�û�" << endl;
			
			os << "[System] ��Ҿ��飺" << pl.bp.user_xp.tier << "��" << endl;
			os << "[System] ��Ǯ��    " << pl.bp.money << "$" << endl << endl;
			os << "[System] �������������һҳ..." << endl;
			
			getch();
			return (os);
		}
};

player Player_data;

#endif
