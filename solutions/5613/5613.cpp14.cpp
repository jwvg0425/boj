#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int num;
	scanf("%d", &num);

	bool isOp = true;
	char op;

	while (true)
	{
		if (isOp)
		{
			std::string s;
			std::cin >> s;
			op = s[0];

			if (op == '=')
			{
				printf("%d", num);
				break;
			}
		}
		else
		{
			int k;
			scanf("%d", &k);

			switch (op)
			{
			case '+':
				num += k;
				break;
			case '-':
				num -= k;
				break;
			case '*':
				num *= k;
				break;
			case '/':
				num /= k;
				break;
			}
		}

		isOp = !isOp;
	}

	return 0;
}