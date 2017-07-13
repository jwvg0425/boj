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
#define MAX 987654321

int main()
{
	while (true)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0)
			break;

		std::vector<int> cand;

		int c = 2 * a - b;

		if ((a >= c && a <= b) ||
			(a >= b && a <= c))
			cand.push_back(c);

		c = 2 * b - a;

		if ((b >= c && b <= a) ||
			(b >= a && b <= c))
			cand.push_back(c);

		c = (a + b) / 2;

		if (a + b % 2 == 0 &&
			((c >= a && c <= b) ||
			(c >= b && c <= a)))
			cand.push_back(c);

		printf("%d\n", *std::min(cand.begin(), cand.end()));
	}
	return 0;
}