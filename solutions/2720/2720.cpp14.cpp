#include<stdio.h>
#include <queue>
#include <vector>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int k;
		scanf("%d", &k);

		int q, d, n, p;
		q = k / 25;
		k -= q * 25;
		d = k / 10;
		k -= d * 10;
		n = k / 5;
		k -= n * 5;
		p = k;


		printf("%d %d %d %d\n", q, d, n, p);
	}
	return 0;
}