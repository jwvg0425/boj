#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	float nums[] =
	{
		(float)a/c + (float)b/d,
		(float)c/d + (float)a/b,
		(float)d/b + (float)c/a,
		(float)b/a + (float)d/c
	};

	int max = 0;

	for (int i = 1; i < 4; i++)
	{
		if (nums[max] < nums[i])
			max = i;
	}

	printf("%d", max);

	return 0;
}