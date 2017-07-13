#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int counts[81] = { 0, };

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			for (int k = 1; k <= c; k++)
			{
				counts[i + j + k]++;
			}
		}
	}

	int max = 0;

	for (int i = 0; i <= a + b + c; i++)
	{
		if (counts[i] > counts[max])
			max = i;
	}

	printf("%d", max);

	return 0;
}