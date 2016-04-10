#include "Scan.h"
#include "regnize.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
void Scan::ToStringQueue(string input)
{
	double midnum=0;
	stringstream stream;
	int i, l;
	string str;
	Regnize Reg;
	l = input.size();//计算字符串的长度，在后面判断是否为输入字符串的最后一位有用到
	for (i = 0; i < l; i++)
	{
		if (input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') 
		{
				str = input[i];//当遇到符号便将符号赋给字符串变量，然后传入队列
				Que.push(str);
				str.clear();//是字符串变量内没有字符串
		}
		else if (input[i] == '-')
		{
			
			if (i == 0 || input[i-1]=='(' )//将负号找出 并与数字放在一起
			{
				str ="-" ;
			}
			else
			{
				str = input[i];
				Que.push(str);
				str.clear();
			}
		}
		else 
		{
			str += input[i];//C++中字符串可以直接用加法来连接
			
			if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i+1] == '(' || input[i+1] == ')' || i==l-1 ) 
			{
				if (str.size() <= 10) 
				{//若处理的数字不超过10位便传入队列
					Que.push(str);
					str.clear();//清空字符串变量
				}

				else
				{
					cout << "error" << endl;//当处理的数字超过10位便输出错误
					getchar();//避免接打印出后面的符号，是程序停留在错误
				}
			}

		}

	}
	
	Num.push(0);//初始化数字栈
	Str.push("+");//先将+存入符号栈，+是最小的符号

	while (!Que.empty())
	{
		if (Que.front() == "+" || Que.front() == "-" || Que.front() == "*" || Que.front() == "/" || Que.front() == "(" || Que.front() == ")" )
		{
			if (Reg.regnize(Str.top(), Que.front()))//遇到比栈顶符号优先级还小的便进入条件
			{
				if (Que.front() == ")")
				{
					while (Str.top()!="(")//将符号栈的元素 push出来 并结合数字栈最顶的三个数字进行计算
					{
						if (Str.top() == "+")
						{
							midnum = Num.top();
							Num.pop();
							midnum += Num.top();
							Num.pop();
							Num.push(midnum);
							
						}
						if (Str.top() == "-")
						{
							midnum = -1 * Num.top();
							Num.pop();
							midnum += Num.top();
							Num.pop();
							Num.push(midnum);
						}
						if (Str.top() == "*")
						{
							midnum = Num.top();
							Num.pop();
							midnum *= Num.top();
							Num.pop();
							Num.push(midnum);
						}
						if (Str.top() == "/")
						{
							midnum = 1 / Num.top();
							Num.pop();
							midnum *= Num.top();
							Num.pop();
							Num.push(midnum);
						}

						Str.pop();
					}
					Str.pop();
				}
				else
				{
					if (Str.top() == "*")
					{
						midnum = Num.top();
						Num.pop();
						midnum *= Num.top();
						Num.pop();
						Num.push(midnum);
					}
					if (Str.top() == "/")
					{
						midnum = 1 / Num.top();
						Num.pop();
						midnum *= Num.top();
						Num.pop();
						Num.push(midnum);
					}
					if (Str.top() == "-")
					{
						
						midnum = -1 * Num.top();
						Num.pop();
						midnum += Num.top();
						Num.pop();
						Num.push(midnum);
					}
						Str.pop();
						Str.push(Que.front());
				}
			}
			else Str.push(Que.front());
			
		}	
		else
		{
			stream << Que.front();
			stream >> midnum;
			Num.push(midnum);
			stream.clear();
			str.clear();
		}

		Que.pop();
	}
	while (Num.size()!=1)//做运算 直至数字栈中剩最后结果
	{
		if (Str.top() == "+")
		{
			midnum = Num.top();
			Num.pop();
			midnum += Num.top();
			Num.pop();
			Num.push(midnum);
		}
		if (Str.top() == "-")
		{
			midnum = -1 * Num.top();
			Num.pop();
			midnum += Num.top();
			Num.pop();
			Num.push(midnum);
		}
		if (Str.top() == "*")
		{
			midnum = Num.top();
			Num.pop();
			midnum *= Num.top();
			Num.pop();
			Num.push(midnum);
		}
		if (Str.top() == "/")
		{
			midnum = 1 / Num.top();
			Num.pop();
			midnum *= Num.top();
			Num.pop();
			Num.push(midnum);
		}
		Str.pop();
	}
}
