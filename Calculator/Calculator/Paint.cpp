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
		cout << Que.front() << endl;//��ӡ������ǰ���Ԫ��
		Que.pop();//��������ǰ���Ԫ��ɾ��
	}

}