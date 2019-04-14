#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <new>
using namespace std;

struct no_memory
{
	int len, wid;
	
	int a[0];
};

int main()
{
	ostringstream ostr;
	ofstream fout;
	string ss;
	ostr.str(ss);
	no_memory * nm = (no_memory *)::operator new((2 + 10 * 10) * sizeof(int));
	
	delete nm;
	
	return 0;
}
