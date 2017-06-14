#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>

int main()
{
	std::stack<int> s;

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int a;

		scanf("%d", &a);

		if (a == 0)
			s.pop();
		else
			s.push(a);
	}

	int sum = 0;

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	printf("%d", sum);

	return 0;
}