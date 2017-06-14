#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int main()
{
	int n;
	scanf("%d", &n);

	int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		if (x == 0 || y == 0)
			axis++;
		else if (x > 0 && y > 0)
			q1++;
		else if (x < 0 && y > 0)
			q2++;
		else if (x < 0 && y < 0)
			q3++;
		else
			q4++;
	}

	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", q1, q2, q3, q4, axis);

	return 0;
}