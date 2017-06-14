#include<stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int count[20001] = { 0, };

	for (int i = 1; i <= 10000; i++)
	{
		int k = i;
		int t = k;

		while (k > 0)
		{
			t += k % 10;
			k /= 10;
		}

		count[t]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (count[i] == 0)
			printf("%d\n", i);
	}

	return 0;
}