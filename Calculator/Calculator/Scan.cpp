#include "Scan.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;
void Scan::ToStringQueue(string input){
	int i, l;
	string str;
	l = input.size();//计算字符串的长度，在后面判断是否为输入字符串的最后一位有用到
	for (i = 0; i < l; i++){
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') {
				str = input[i];//当遇到符号便将符号赋给字符串变量，然后传入队列
				Que.push(str);
				str.clear();//是字符串变量内没有字符串
		}
		else {
			str += input[i];//C++中字符串可以直接用加法来连接
			if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i+1] == '(' || input[i+1] == ')' || i==l-1 ) {
				if (str.size() <= 10) {//若处理的数字不超过10位便传入队列
					Que.push(str);
					str.clear();//清空字符串变量
				}
				else{
					cout << "error" << endl;//当处理的数字超过10位便输出错误
					getchar();//避免接打印出后面的符号，是程序停留在错误
				}
			}
		}
	}
}
