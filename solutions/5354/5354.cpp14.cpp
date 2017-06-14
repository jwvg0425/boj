#include<stdio.h>
#include <queue>
#include <vector>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (x == 0 || y == 0 || x == n - 1 || y == n - 1)
					printf("#");
				else
					printf("J");
			}

			printf("\n");
		}

		printf("\n");
	}
	return 0;
}