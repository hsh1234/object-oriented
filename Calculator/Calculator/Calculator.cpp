#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
#include "Paint.h"
#include "Scan.h"
#include <stack>

using namespace std;
queue <string> Que;
stack <double> Num;
stack <string> Str;

int main(int argc, char* argv[])
{   

	string input;
	Scan scan;
	Paint print;

	if (argc == 2)
	{
		input = argv[1];
	}

	else  
	{
		input = argv[2];
	}

	scan.ToStringQueue(input);
	if (argc == 3) cout << input << "= ";
	print.Printqueue();
	return 0;
	
}

