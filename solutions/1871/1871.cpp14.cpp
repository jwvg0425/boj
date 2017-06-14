#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		int front = (str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + (str[2] - 'A');
		int back = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');

		if (abs(front - back) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}

	return 0;
}