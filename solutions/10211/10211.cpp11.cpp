#include <stdio.h>
#include <algorithm>

void solve()
{
	int N;
	int max = 0;
	int maxAtHere = 0;

	scanf("%d", &N);
	scanf("%d", &max);
	maxAtHere = max;
	
	for (int i = 1; i < N; i++)
	{
		int x;
		
		scanf("%d", &x);

		maxAtHere = std::max(maxAtHere + x, x);
		max = std::max(max, maxAtHere);
	}

	printf("%d\n", max);
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