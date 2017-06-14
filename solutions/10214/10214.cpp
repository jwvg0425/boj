
#include <stdio.h>

int main()
{
	int T;
	int y, k;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		y = k = 0;

		for (int j = 0; j < 9; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			y += a;
			k += b;
		}
		if (y > k)
			printf("Yonsei\n");
		else if (y == k)
			printf("Draw\n");
		else
			printf("Korea\n");
	}
}