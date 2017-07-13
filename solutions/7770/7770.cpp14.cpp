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
	int count = 0;

	int n;
	int height = 0;
	scanf("%d", &n);

	int add = 1;

	while (count <= n)
	{
		height++;
		count += add;
		add += 4 * height;
	}

	printf("%d", height - 1);

	return 0;
}