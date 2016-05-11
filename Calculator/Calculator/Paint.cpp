#include "Paint.h"
#include "Scan.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

extern queue <string> Que;
extern stack <double> Num;
extern stack <string> Str;
extern int flag;
extern string ssss;
extern ofstream fout;

void Paint::Printqueue()
{
	if (flag<=3)
		cout << Num.top() << endl;//打印队列最前面的元素
	else
	{
		
		if (fout.is_open())
			fout << Num.top() << endl;
		   
	}
	Num.pop();
}