#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	int n;
	scanf("%d", &n);

	std::priority_queue<int> q;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		if (k == 0)
		{
			if (q.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else
		{
			q.push(k);
		}
	}

	return 0;
}