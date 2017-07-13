#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	std::priority_queue<int> leftQ, rightQ;

	int n;
	scanf("%d", &n);

	leftQ.push(-10001);
	rightQ.push(-10001);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		int rt = -rightQ.top();

		if (k <= rt)
			leftQ.push(k);
		else
			rightQ.push(-k);

		if (rightQ.size() > leftQ.size())
		{
			int rt = -rightQ.top();
			leftQ.push(rt);
			rightQ.pop();
		}

		if (leftQ.size() == rightQ.size() + 2)
		{
			int lt = leftQ.top();
			rightQ.push(-lt);
			leftQ.pop();
		}

		printf("%d\n", leftQ.top());
	}

	return 0;
}