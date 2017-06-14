#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>

int main()
{
	int t = 1;
	while (true)
	{
		std::string str;
		std::getline(std::cin, str);
		std::string op, num1, num2;

		int blanks[2];
		int idx = 0;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				blanks[idx] = i;
				idx++;
			}
		}

		num1 = str.substr(0, blanks[0]);
		op = str.substr(blanks[0] + 1, blanks[1] - blanks[0] - 1);
		num2 = str.substr(blanks[1] + 1);

		if (op == "E")
		{
			break;
		}

		int a = std::stoi(num1);
		int b = std::stoi(num2);
		bool res = false;

		if (op == "<")
		{
			res = a < b;
		}
		else if (op == "<=")
		{
			res = a <= b;
		}
		else if (op == "==")
		{
			res = a == b;
		}
		else if (op == ">=")
		{
			res = a >= b;
		}
		else if (op == ">")
		{
			res = a > b;
		}
		else if (op == "!=")
		{
			res = a != b;
		}

		printf("Case %d: %s\n", t, res ? "true" : "false");


		t++;
	}


	return 0;
}