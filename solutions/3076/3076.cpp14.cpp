#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, int>;

int main()
{
	int r, c, a, b;
	scanf("%d %d %d %d", &r, &c, &a, &b);

	for (int y = 0; y < r*a; y++)
	{
		for (int x = 0; x < c*b; x++)
		{
			int xk = (x / b) % 2;
			int yk = (y / a) % 2;

			if ((xk + yk) % 2 == 0)
			{
				printf("X");
			}
			else
			{
				printf(".");
			}
		}

		printf("\n");
	}

	return 0;
}