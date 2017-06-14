#include <stdio.h>
#include <algorithm>

int main()
{
	int d, k;

	scanf("%d %d", &d, &k);

	int sa = 1;
	int sb = 1;

	while (true)
	{
		int a = sa;
		int b = sb;
		for (int i = 0; i < d - 2; i++)
		{
			std::swap(a, b);
			b += a;
		}

		if (b == k)
		{
			printf("%d\n%d", sa, sb);
			break;
		}
		else if (b < k)
		{
			sb++;
		}
		else
		{
			sa++;
			sb = 1;
		}
	}

	return 0;
}