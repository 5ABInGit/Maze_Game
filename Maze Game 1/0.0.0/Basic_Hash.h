
// 这里是Maze_Game的哈希函数定义 

#ifndef BASIC_HASH_H
#define BASIC_HASH_H 1

unsigned int basic_hashstr(const char * ptr)
{
	unsigned int val = 0, tmp;
	
	while (*ptr != '\0')
	{
		val = (val << 4) + (*ptr);
		
		if (tmp = (val & 0xf0000000))
		{
			val ^= (tmp >> 24);
			val ^= tmp;
		}
		
		ptr++;
	}
	
	return val;
}

#endif
