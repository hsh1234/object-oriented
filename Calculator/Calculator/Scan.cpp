#include "Scan.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;
void Scan::ToStringQueue(string input){
	int i, l;
	string str;
	l = input.size();//�����ַ����ĳ��ȣ��ں����ж��Ƿ�Ϊ�����ַ��������һλ���õ�
	for (i = 0; i < l; i++){
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') {
				str = input[i];//���������ű㽫���Ÿ����ַ���������Ȼ�������
				Que.push(str);
				str.clear();//���ַ���������û���ַ���
		}
		else {
			str += input[i];//C++���ַ�������ֱ���üӷ�������
			if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i+1] == '(' || input[i+1] == ')' || i==l-1 ) {
				if (str.size() <= 10) {//����������ֲ�����10λ�㴫�����
					Que.push(str);
					str.clear();//����ַ�������
				}
				else{
					cout << "error" << endl;//����������ֳ���10λ���������
					getchar();//����Ӵ�ӡ������ķ��ţ��ǳ���ͣ���ڴ���
				}
			}
		}
	}
}
