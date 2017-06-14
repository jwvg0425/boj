#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("You get %d piece(s) and your dad gets %d piece(s).\n", a / b, a % b);
	}

	return 0;
}