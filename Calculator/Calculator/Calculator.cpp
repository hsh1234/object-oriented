#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
#include "Paint.h"
#include "Scan.h"
#include <stack>
#include <fstream>

using namespace std;
queue <string> Que;
stack <double> Num;
stack <string> Str;
int flag = 3;
string ssss;
ofstream fout;

int main(int argc, char* argv[])
{   
	string input;
	Scan scan;
	Paint print;

	

	if (argc == 2)//��-a -f
	{
		
		input = argv[1];
		scan.ToStringQueue(input);
		print.Printqueue();
	}

	else if (argc == 3 )//�ڶ�������-a
	{
		input = argv[2];
		cout << input << " ";
		scan.ToStringQueue(input);
		print.Printqueue();
	}
	
	else// -f�����
	{
		
		fout.open(argv[3]);
		flag = 4;
		ifstream fin;
		fin.open(argv[2]);
		if (fin.is_open())
		{

			while (fin.good() && !fin.eof())//��ȡ���ļ�βֹͣ����
			{
				
				string message;//�Ƚ�����ʽ����message ��ת����input���в���
				fin >> message;
				input = message;
				ssss = argv[3];
				scan.ToStringQueue(input);
				print.Printqueue();

			}
		}	
	}
	system("pause");
	return 0;
	
}

