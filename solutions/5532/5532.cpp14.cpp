#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int main()
{
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

	int num1 = (a + c - 1) / c;
	int num2 = (b + d - 1) / d;

	l -= std::max(num1, num2);

	printf("%d", std::max(0, l));

	return 0;
}