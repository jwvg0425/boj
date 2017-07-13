#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int counts[100001];

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 2; i <= b; i++)
	{
		if (counts[i] != 0)
			continue;

		counts[i] = 1;

		for (int j = i * 2; j <= b; j += i)
		{
			int jcopy = j;

			while (jcopy % i == 0)
			{
				counts[j]++;
				jcopy /= i;
			}
		}
	}

	int c = 0;
	for (int i = a; i <= b; i++)
	{
		if (counts[counts[i]] == 1)
			c++;
	}

	printf("%d", c);

	return 0;
}