
// 这里是Maze_Game的日志记录函数 

#ifndef LOG_TYPE_H
#define LOG_TYPE_H 1

const char * format_of_time = "%Y/%m/%d %H:%M:%S";

const std::string make_log(std::string orig)
{
	char mm[101] = {};
	
	time_t now;
	time(&now);
	strftime(mm, 100, format_of_time, localtime(&now));
	
	ostringstream outstr;
	outstr << "[" << mm << "] " << orig << endl;
	return outstr.str();
}

const std::string Login_log (std::string username)
{
	std::string info (username);
	info += " Login;";
	return info;
}

const std::string Logout_log (std::string username)
{
	std::string info (username);
	info += " Logout;";
	return info;
}

const std::string Pass_log (std::string username, int challenge)
{
	std::string info (username);
	info += " Pass The Challenge #;";
	return info;
}

const std::string Jump_log (std::string username, int challenge)
{
	std::string info (username);
	info += " Jump The Challenge #;";
	return info;
}

#endif 
