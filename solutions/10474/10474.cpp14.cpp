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
	while (true)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0)
			break;

		printf("%d %d / %d\n", a / b, a%b, b);
	}

	return 0;
}