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
	l = input.size();//�����ַ����ĳ��ȣ��ں����ж��Ƿ�Ϊ�����ַ��������һλ���õ�
	for (i = 0; i < l; i++)
	{
		if (input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') 
		{
				str = input[i];//���������ű㽫���Ÿ����ַ���������Ȼ�������
				Que.push(str);
				str.clear();//���ַ���������û���ַ���
		}
		else if (input[i] == '-')
		{
			
			if (i == 0 || input[i-1]=='(' )//�������ҳ� �������ַ���һ��
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
			str += input[i];//C++���ַ�������ֱ���üӷ�������
			
			if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i+1] == '(' || input[i+1] == ')' || i==l-1 ) 
			{
				if (str.size() <= 10) 
				{//����������ֲ�����10λ�㴫�����
					Que.push(str);
					str.clear();//����ַ�������
				}

				else
				{
					cout << "error" << endl;//����������ֳ���10λ���������
					getchar();//����Ӵ�ӡ������ķ��ţ��ǳ���ͣ���ڴ���
				}
			}

		}

	}
	
	Num.push(0);//��ʼ������ջ
	Str.push("+");//�Ƚ�+�������ջ��+����С�ķ���

	while (!Que.empty())
	{
		if (Que.front() == "+" || Que.front() == "-" || Que.front() == "*" || Que.front() == "/" || Que.front() == "(" || Que.front() == ")" )
		{
			if (Reg.regnize(Str.top(), Que.front()))//������ջ���������ȼ���С�ı��������
			{
				if (Que.front() == ")")
				{
					while (Str.top()!="(")//������ջ��Ԫ�� push���� ���������ջ����������ֽ��м���
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
	while (Num.size()!=1)//������ ֱ������ջ��ʣ�����
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
