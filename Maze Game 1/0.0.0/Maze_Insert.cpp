#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "Template_Maze.h"

using namespace std;

block_type fltw(const maze &m, int code)
{
	int len = code / m.length_of(), wid = code % m.length_of();
	return m.at(len, wid);
}

void fill_into(maze & m, block_type bt, const int code)
{
	int len = code / m.length_of(), wid = code % m.length_of();
	m.at(len, wid) = bt;
}

int block_to_int(const block_type bt)
{
	if (bt == no_entry)
		return 0;
	else
		return 1;
}

block_type int_to_block(const int it)
{
	if (it == 0)
		return no_entry;
	else
		return can_entry;
}

const string fold(const maze & m)
{
	int str_size = m.size();
	char c = 0;
	string result;
	
	for (int i = 0, j = 0; i < str_size; i++, j++)
	{
		if (j == 8)
		{
			j = 0;
			result += c;
			c = 0;
		}
		int f = block_to_int(fltw(m, i));
		c |= (f << j);
	}
	if (m.size() != 0)
		result += c;
	
	return result;
}

void unfold(maze & m, const std::string &str)
{
	int l = m.size(), tmpa, tmpb;
	
	for (int i = 0; i < l; i++)
	{
		tmpa = str[i / 8];
		fill_into(m, int_to_block((tmpa >> (i % 8)) & 1), i);
	}
	
	return;
}

void write_maze(const maze & m, int chapter_count, int number_count)
{
	std::ofstream fout;
	std::string ss = "Game_Data_Lib/Part/01/", bin;
	std::ostringstream outstr;
	int tmp1 = m.length_of(), tmp2 = m.width_of();
	
	outstr.fill('0');
	outstr.setf(ios_base::right, ios_base::adjustfield);
	outstr.width(2);
	outstr << chapter_count << "_" << number_count << ".bimaze";
	ss += outstr.str();
	
	fout.open(ss.c_str(), std::ios_base::out | std::ios_base::binary);
	fout.write((char *)&tmp1, sizeof(int));
	fout.write((char *)&tmp2, sizeof(int));
	
	fout.close();
	
	bin = fold(m);
	
	fout.open(ss.c_str(), std::ios_base::out | std::ios_base::app);
	fout << bin;
	fout.close();
	
	return;
}

void read_maze(maze & m, const int chapter_count, const int number_count)
{
	std::ifstream fin;
	std::string ss = "Game_Data_Lib/Part/01/", bin;
	int tmp1, tmp2;
	std::ostringstream outstr;
	
	outstr.fill('0');
	outstr.setf(ios_base::right, ios_base::adjustfield);
	outstr.width(2);
	outstr << chapter_count << "_" << number_count << ".bimaze";
	ss += outstr.str();
	
	fin.open(ss.c_str(), std::ios_base::in | std::ios_base::binary);
	
	if (!fin.is_open())
	{
		cerr << "Cannot Find Maze File. Exit Failure!" << endl;
		exit(EXIT_FAILURE);
	}
	
	fin.read((char *)&tmp1, sizeof(int));
	fin.read((char *)&tmp2, sizeof(int));
	
	cout << tmp1 << endl << tmp2 << endl;
	
	m.reset_size(tmp1, tmp2);
	
	cout << m.length_of() << endl;
	
	fin.close();
	
	fin.open(ss.c_str(), std::ios_base::in);
	fin.seekg(2 * sizeof(int));
	char ch;
	while (fin.get(ch))
		bin += ch;
	
	unfold(m, bin);
	
	fin.close();
	
	return;
}

int main()
{
	int x, y, tmp1, tmp2;
	
	cout << "Enter the chapter number:";
	cin >> tmp1;
	cout << "Enter the part number:";
	cin >> tmp2;
	
	cout << "Enter the maze size:" << endl;
	cout << " x:";
	cin >> x;
	cout << " y:";
	cin >> y;
	cout << "Enter any charactor..." << endl;
	
	maze m(x, y);
	char ch;
	
	do
		ch = cin.get();
	while (ch == '\n' || ch == '\r');
	
	bool is_changing = false;
	
	while (ch != '\n' && ch != '\r' && (ch != 'E' && ch != 'e'))
	{
		m.show();
		if (is_changing)
			m.make_ok();
		
		ch = getch();
		switch (ch)
		{
			case 'W':
			case 'w':
				m.move_user(go_up);
				break;
			
			case 'S':
			case 's':
				m.move_user(go_down);
				break;
			
			case 'A':
			case 'a':
				m.move_user(go_left);
				break;
			
			case 'D':
			case 'd':
				m.move_user(go_right);
				break;
			
			case 'Q':
			case 'q':
				is_changing = (!is_changing);
				break;
			
			default: break;
		}
		system("CLS");
	}
	
	system("COLOR 0F");
	
	write_maze(m, tmp1, tmp2);
	
	maze xy;
	
	/*
	char c;
	ifstream fin("2_2.bimaze", ios_base::in);
	while (fin.get(c))
		cout << int(c) << " ";
	cout << endl;
	//*/
	
	read_maze(xy, tmp1, tmp2);
	
	xy.show();
	
	return 0;
}
