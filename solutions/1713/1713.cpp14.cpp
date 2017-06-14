#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

struct State
{
	int n, s, t;
};

State a[20];
int n, m, u, s, i, j, k;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 0; i<m; i++)
	{
		scanf("%d", &s);

		for (j = 0; j<n; j++)
		{
			if (a[j].n == s)
			{
				a[j].s++;
				break;
			}
		}

		if (j == n)
		{
			for (j = 0; j<n; j++)
			{
				if ((a[j].s == a[k].s&&a[j].t<a[k].t) || a[j].s<a[k].s)
					k = j;
			}
			a[k].n = s;
			a[k].s = 1;
			a[k].t = i;
		}
	}

	std::sort(a, a + n, [](const State& l, const State& r)
	{
		return l.n < r.n;
	});

	for (i = 0; i<n; i++)
	{
		if (a[i].n != 0)
			printf("%d ", a[i].n);
	}
}