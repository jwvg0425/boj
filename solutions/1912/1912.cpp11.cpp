#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int main()
{
	int n;

	scanf("%d", &n);

	int max_here;
	int max_far;

	for (int i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);

		if (i == 0)
		{
			max_here = v;
			max_far = v;
			continue;
		}

		max_here = std::max(v, max_here + v);
		max_far = std::max(max_here, max_far);
	}

	printf("%d", max_far);
}