#include "Paint.h"
#include "Scan.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;
extern queue <string> Que;

void Paint::Printqueue()
{
	while (!Que.empty())
	{
		cout << Que.front() << endl;//打印队列最前面的元素
		Que.pop();//将队列最前面的元素删除
	}

}