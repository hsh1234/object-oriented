#include "Paint.h"
#include "Scan.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
extern queue <string> Que;
extern stack <double> Num;
extern stack <string> Str;

void Paint::Printqueue()
{
	
		cout << Num.top() << endl;//打印队列最前面的元素
	

}