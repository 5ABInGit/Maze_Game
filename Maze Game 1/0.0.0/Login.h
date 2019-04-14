
// 这里是Maze_Game的登陆函数定义处 

#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
#include <conio.h>

#include "Log_Type.h"
#include "Basic_Hash.h"

#define WRONG_PASSWORD 1
#define WRONG_USERNAME 2
#define NO_PASSWORD    3
#define NO_USERNAME    4
#define USERNAME_USED  5 //（未开发）用户名已使用

using namespace std;
const int username_maxsize = 20, password_maxsize = 20;

int error_print (int type_of_error); 
	// 根据 type_of_error 输出错误信息
int check_nickname (char * name);
	// 检测昵称是否存在
int check_password (char * name, char * password);
	// 检测密码是否正确
void recent ();
	// （未开发） 注册新账号
inline int check_user (char * _username, char * _password);
	// 检测用户信息是否完备
bool read_username (char * _str);
	// 读取用户名，若读取成功，返回true，否则返回false，将用户名存储于_str内
bool read_password (char * _str);
	// 读取密码，若读取成功，返回true，否则返回false，将密码存储于_str内
void program_log (const string Log);
	// 记录程序日志
unsigned int hashstr(const char * str);
	// Hash
string login ();
	// 通过调用之前一系列函数完成登陆工作，返回用户名

unsigned int hashstr(const char * ptr)
{
	
}

int error_print (int type_of_error)
{
	cout << endl;
	switch (type_of_error)
	{
		case WRONG_USERNAME:
		case WRONG_PASSWORD:
			cout << "[System] 密码输入错误或用户名不存在！";
			break;
		
		case NO_PASSWORD:
			cout << "[System] 密码不能为空！请重新输入：";
			break;
		
		case NO_USERNAME:
			cout << "[System] 用户名不能为空！请重新输入：";
			break;
		
		default: break; 
	};
	
	return -1;
}

int check_nickname (char * name)
{
	FILE * f;
	char fname[51] = "Game_Data_Lib/Player_Info/";
	strcat (fname, name);
	strcat (fname, ".txt");
	
	if ((f = fopen (fname, "r")) == NULL)
		return -1;
	
	fclose (f);
	return 0;
}

int check_password (char * name, char * password)
{
	FILE * f;
	char fname[71] = "Game_Data_Lib/Player_Info/Password/";
	strcat (fname, name);
	strcat (fname, ".txt");
	
	if ((f = fopen (fname, "r")) == NULL)
	{
		return -1;
	}
	
	char pswd[password_maxsize + 1];
	fgets (pswd, password_maxsize, f);
	fclose (f);
	pswd[strlen (pswd) - 1] = '\0';
	
	if (strcmp (pswd, password) != 0)
		return -1;
	
	return 0;
}

void recent ()
{
	cout << "<------ 注册完成, 按任意键继续登陆 ------>";
	
	getch ();
	system ("CLS");
	return;
}

int check_user (char * _username, char * _password)
{
	system ("CLS");
	if (check_nickname (_username) != 0)
		return error_print (WRONG_USERNAME);
	if (check_password (_username, _password) != 0)
		return error_print (WRONG_PASSWORD);
	
	return 0;
}

bool read_username (char * _str)
{
	char *Username = _str, ch;
	int size = 0;
	
	while (size <= username_maxsize)
	{
		ch = getch (); // 使用getch()为了无缓冲输入,cin和scanf都得等换行 
		if (isprint (ch))
		{
			Username[size] = ch;
			size++;
			cout.put(ch);
		}
		else if (size > 0 && ch == '\b')
		{
			cout.write("\b \b", 3);
			size--;
		}
		else if (ch == '\n' || ch == '\r')
		{
			if (size == 0)
			{
				cout << "\n[System] 难道您没有用户名吗？"
					 << "再输入一个R来注册吧~~" << endl;
				
				do
				{
					ch = getch ();
				} while (ch == '\n' || ch == '\r');
				
				if (ch == 'R' || ch == 'r')
				{
					recent ();
					return false;
				}
				else
				{
					system ("CLS");
					cout << "[System] 请继续输入您的用户名：";
					return false;
				}
			}
			else
				return true;
		}
	}
	
	cout << endl << "[System] 用户名太长啦！是不是输错了？" << endl;
	cout << "[System] 再输一遍吧："; 
	return false; 
}

bool read_password (char * _str)
{
	char *Password = _str, ch;
	int size = 0;
	
	while (size <= password_maxsize)
	{
		ch = getch (); // 使用getch()为了无缓冲输入,cin和scanf都得等换行 
		
		if (isprint (ch))
		{
			Password[size] = ch;
			if (size == 0)
				cout.put(ch);
			else
			{
				cout.write("\b*", 2);
				cout.put(ch);
			}
			size++;
		}
		else if (size > 0 && ch == '\b')
		{
			cout.write("\b \b", 3);
			size--;
		}
		else if (ch == '\n' || ch == '\r')
		{
			if (size != 0)
			{
				putchar ('\b');
				putchar ('*');
				return true;
			}
			else
			{
				error_print (NO_PASSWORD);
				return false; 
			}
		}
	}
	
	cout << endl << "[System] 密码太长啦！是不是输错了？" << endl;
	cout << "[System] 再输一遍吧："; 
	return false;
}

void program_log (const string Log)
{
	ofstream log_st("Game_Data_Lib/Game_Log.logs", ios_base::out | ios_base::app);
	log_st << make_log(Log);
	log_st.close();
	return;
}

string login ()
{
	char username[username_maxsize] = {}, password[password_maxsize] = {};
	system("TITLE Maze_Game Login");
	system("CLS");
	
	do
	{
		cout << endl << "[System] 请输入您的用户名：";
		while (!read_username (username))
			memset (username, '\0', sizeof (username));
		
		cout << endl << "[System] 请输入您的密码：";
		while (!read_password (password))
			memset (password, '\0', sizeof (password));
		
	} while (check_user (username, password) == -1);
	
	string str (username);
	program_log(Login_log(str));
	return str;
}

#endif
