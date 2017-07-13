#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <math.h>
#include <map>

std::map<int, int> visited;

int main()
{
	int a, p;

	scanf("%d %d", &a, &p);
	int idx = 0;

	visited[a] = idx;

	while (true)
	{
		int next = 0;

		while (a > 0)
		{
			int digit = a % 10;
			int k = 1;

			for (int i = 0; i < p; i++)
				k *= digit;

			next += k;
			a /= 10;
		}

		a = next;

		if (visited.find(a) != visited.end())
		{
			printf("%d", visited[a]);
			break;
		}

		idx++;
		visited[a] = idx;
	}

	return 0;
}