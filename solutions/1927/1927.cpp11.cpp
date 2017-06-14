#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <functional>

int main()
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if (a == 0)
		{
			if (q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else
		{
			q.push(a);
		}
	}
}