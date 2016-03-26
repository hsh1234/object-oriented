/******
filename：Caculater.cpp
author:031502512 date:2016.3.26
Function:分离一个四则运算式
******/

#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
#include "Paint.h"
#include "Scan.h"
using namespace std;
queue <string> Que;

int main()
{
	string input;
	Scan scan;
	Paint print;
	getline(cin, input);
	scan.ToStringQueue(input);
	print.Printqueue();
	return 0;
}

