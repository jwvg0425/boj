#include <stdio.h>

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	if (N == 1)
	{
		printf("1");
	}
	else if (N == 2)
	{
		int c = (M + 1) / 2;

		if (c >= 4)
			c = 4;

		printf("%d", c);
	}
	else
	{
		switch (M)
		{
		case 1:
			printf("1");
			break;
		case 2:
			printf("2");
			break;
		case 3:
			printf("3");
			break;
		case 4:
		case 5:
			printf("4");
			break;
		default:
			printf("%d", M - 2);
			break;
		}
	}
}