#include <stdio.h>

void solve()
{
	int N;

	scanf("%d", &N);

	if (N <= 3 || N == 6)
		printf("0\n");
	else if (N == 4)
		printf("2\n");
	else
		printf("1\n");
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		solve();
	}
}