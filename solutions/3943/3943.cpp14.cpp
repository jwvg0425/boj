#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);

	int res = n;

	while (n != 1)
	{
		if (n % 2 == 1)
		{
			n = n * 3 + 1;
		}
		else
		{
			n = n / 2;
		}

		res = max(n, res);
	}

	printf("%d\n", res);
}

int main()
{
	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		solve();
	}
	return 0;
}