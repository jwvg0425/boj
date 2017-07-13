#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int main()
{
	int n, p;
	std::stack<int> fingers[7];
	
	scanf("%d %d", &n, &p);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int line, pos;
		scanf("%d %d", &line, &pos);

		while (!fingers[line].empty() && fingers[line].top() > pos)
		{
			fingers[line].pop();
			count++;
		}

		if (!fingers[line].empty() && fingers[line].top() == pos)
			continue;

		fingers[line].push(pos);
		count++;
	}

	printf("%d", count);

	return 0;
}