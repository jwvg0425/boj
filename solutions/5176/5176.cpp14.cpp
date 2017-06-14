#include <stdio.h>
#include <memory.h>

void solve()
{
	int p, m;

	bool sit[501] = { false, };
	scanf("%d %d", &p, &m);

	int count = 0;

	for (int i = 0; i < p; i++)
	{
		int a;
		scanf("%d", &a);

		if (sit[a])
			count++;
		sit[a] = true;
	}

	printf("%d\n", count);
}

int main()
{
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		solve();
	}

	return 0;
}