
// ������Maze_Game����Ҳٿش� 

#ifndef PLAYER_MOVE_MAZE_H
#define PLAYER_MOVE_MAZE_H 1

enum toward {go_left = 0, go_right = 1, go_up = 2, go_down = 3};
enum block_type {no_entry = 0, can_entry = 1};

const int place[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class maze;
// ǰ����������֤user_controlor�����ʶ��maze�� 
// ���ཫ����0.x���루��ʱ��ʹ�ã� 
class user_controlor
{
	private:
		int user_x, user_y;
	
	public:
		user_controlor() : user_x(0), user_y(0) { }
		user_controlor(const maze &m);
		
		~user_controlor() { }
		
		void reshow(const maze &m, toward pos);
		// Ϊ�˲�ʹ�Թ����ص�����Ļ��˸ 
};

// user_controlor����������������maze��������ɺ��ٶ��塣
// Ϊ����������Ԫ��ϵ 

#endif

//������򽫻ᱻTemplate_Maze.h�������� 
