
// 这里是Maze_Game的迷宫读写 

#ifndef MAZE_WRITE_TO_BINARY_H
#define MAZE_WRITE_TO_BINARY_H 1

// 自定义.bimaze文件将会在1.x版本加入 
// 现在可以进行迷宫写入，但是得修改源代码，不建议。 

#ifdef MAZE_GAME_DEBUG

block_type fltw(const maze &m, int code)
{
	int len = code / m.length_of(), wid = code % m.length_of();
	return m.at(len, wid);
}

#endif

void fill_into(maze & m, block_type bt, const int code)
{
	int len = code / m.length_of(), wid = code % m.length_of();
	m.at(len, wid) = bt;
}

#ifdef MAZE_GAME_DEBUG

int block_to_int(const block_type bt)
{
	if (bt == no_entry)
		return 0;
	else
		return 1;
}

#endif

block_type int_to_block(const int it)
{
	if (it == 0)
		return no_entry;
	else
		return can_entry;
}

#ifdef MAZE_GAME_DEBUG

const std::string fold(const maze & m)
{
	int str_size = m.size();
	char c = 0;
	std::string result;
	
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

#endif

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

#ifdef MAZE_GAME_DEBUG

void write_maze(const maze & m, int chapter_count, int number_count)
{
	std::ofstream fout;
	std::string ss, bin;
	std::ostringstream outstr;
	
	outstr << chapter_count << "_" << number_count << ".bimaze";
	ss = outstr.str();
	
	fout.open(ss.c_str(), std::ios_base::out | std::ios_base::binary);
	fout.write((char *)&m, 6 * sizeof(int));
	fout.close();
	
	bin = fold(m);
	
	fout.open(ss.c_str(), std::ios_base::out | std::ios_base::app);
	fout << bin;
	fout.close();
	
	return;
}

#endif

void read_maze(maze & m, const int chapter_count, const int number_count)
{
	std::ifstream fin;
	std::string ss, bin;
	int tmp1, tmp2;
	std::ostringstream outstr;
	
	outstr << chapter_count << "_" << number_count << ".bimaze";
	ss = outstr.str();
	
	fin.open(ss.c_str(), std::ios_base::in | std::ios_base::binary);
	
	if (!fin.is_open())
	{
		std::cerr << "Cannot Find Maze File. Exit Failure!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	fin.read((char *)&tmp1, sizeof(int));
	fin.read((char *)&tmp2, sizeof(int));
	fin.read(((char *)&m) + 2 * sizeof(int), 4 * sizeof(int));
	
	m.reset_size(tmp1, tmp2);
	
	fin.close();
	
	fin.open(ss.c_str(), std::ios_base::in);
	fin.seekg(6 * sizeof(int));
	char ch;
	while (fin.get(ch))
		bin += ch;
	
	unfold(m, bin);
	
	fin.close();
	
	return;
}

#endif
