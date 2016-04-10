#include <iostream>
#include "regnize.h"
using namespace std;
bool Regnize::regnize(string c1, string c2)//规定+ - * / （ ） 的优先级
{
	if (c1 == "*" || c1== "/")
	{
		if (c2 == "+" || c2 == "-" || c2== ")")
		{
			return 1;
		}
		else return 0;
	}
	if (c1 == "(")
	{
		if (c2 == ")")
		{
			return 1;
		}
		else return 0;
	}
	if (c1 == "+" )
	{
		if (c2 == ")") return 1;
		else return 0;
	}
	if (c1 == "-")
	{
		if (c2 == ")") return 1;
		if (c2 == "+") return 1;
		else return 0;
	}
	else return 0;
}