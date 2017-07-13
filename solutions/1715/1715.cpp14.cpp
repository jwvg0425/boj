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

int main()
{
	int n;
	scanf("%d", &n);

	std::priority_queue<int> q;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		q.push(-k);
	}

	int count = 0;

	while (q.size() > 1)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		count -= a + b;

		q.push(a + b);
	}

	printf("%d", count);

	return 0;
}