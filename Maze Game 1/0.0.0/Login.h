
// ������Maze_Game�ĵ�½�������崦 

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
#define USERNAME_USED  5 //��δ�������û�����ʹ��

using namespace std;
const int username_maxsize = 20, password_maxsize = 20;

int error_print (int type_of_error); 
	// ���� type_of_error ���������Ϣ
int check_nickname (char * name);
	// ����ǳ��Ƿ����
int check_password (char * name, char * password);
	// ��������Ƿ���ȷ
void recent ();
	// ��δ������ ע�����˺�
inline int check_user (char * _username, char * _password);
	// ����û���Ϣ�Ƿ��걸
bool read_username (char * _str);
	// ��ȡ�û���������ȡ�ɹ�������true�����򷵻�false�����û����洢��_str��
bool read_password (char * _str);
	// ��ȡ���룬����ȡ�ɹ�������true�����򷵻�false��������洢��_str��
void program_log (const string Log);
	// ��¼������־
unsigned int hashstr(const char * str);
	// Hash
string login ();
	// ͨ������֮ǰһϵ�к�����ɵ�½�����������û���

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
			cout << "[System] �������������û��������ڣ�";
			break;
		
		case NO_PASSWORD:
			cout << "[System] ���벻��Ϊ�գ����������룺";
			break;
		
		case NO_USERNAME:
			cout << "[System] �û�������Ϊ�գ����������룺";
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
	cout << "<------ ע�����, �������������½ ------>";
	
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
		ch = getch (); // ʹ��getch()Ϊ���޻�������,cin��scanf���õȻ��� 
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
				cout << "\n[System] �ѵ���û���û�����"
					 << "������һ��R��ע���~~" << endl;
				
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
					cout << "[System] ��������������û�����";
					return false;
				}
			}
			else
				return true;
		}
	}
	
	cout << endl << "[System] �û���̫�������ǲ�������ˣ�" << endl;
	cout << "[System] ����һ��ɣ�"; 
	return false; 
}

bool read_password (char * _str)
{
	char *Password = _str, ch;
	int size = 0;
	
	while (size <= password_maxsize)
	{
		ch = getch (); // ʹ��getch()Ϊ���޻�������,cin��scanf���õȻ��� 
		
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
	
	cout << endl << "[System] ����̫�������ǲ�������ˣ�" << endl;
	cout << "[System] ����һ��ɣ�"; 
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
		cout << endl << "[System] �����������û�����";
		while (!read_username (username))
			memset (username, '\0', sizeof (username));
		
		cout << endl << "[System] �������������룺";
		while (!read_password (password))
			memset (password, '\0', sizeof (password));
		
	} while (check_user (username, password) == -1);
	
	string str (username);
	program_log(Login_log(str));
	return str;
}

#endif
