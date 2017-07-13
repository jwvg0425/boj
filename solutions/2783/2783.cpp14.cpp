#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	float x, y;
	scanf("%f %f", &x, &y);

	float min = x * 1000.0f / y;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		float a, b;

		scanf("%f %f", &a, &b);

		min = std::min(min, a * 1000.0f / b);
	}

	printf("%f", min);

	return 0;
}