#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, int>;

int sum(int n)
{
	int res = 0;

	int nowNum = 1;
	int nowCount = 0;

	for (int i = 0; i < n; i++)
	{
		res += nowNum;
		nowCount++;
		if (nowCount == nowNum)
		{
			nowNum++;
			nowCount = 0;
		}
	}

	return res;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", sum(b) - sum(a - 1));

	return 0;
}