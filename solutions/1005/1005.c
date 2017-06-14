#include<stdio.h>

int t, n, k, w, i, d[1001][1001], a[1001], x, y;
int s[1001];

int b(int c)
{
	if (s[c] != 0)return s[c];
	if (a[c] == 0)return d[c][0];

	int i, t = 0, k;

	for (i = 1; i <= a[c]; i++)
	{
		k = b(d[c][i]);
		if (k>t)t = k;
	}

	return s[c] = t + d[c][0];
}

int main(void)
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &d[i+1][0]);
			a[i+1] = 0;
			s[i+1] = 0;
		}
		for (i = 0; i < k; i++)
		{
			scanf("%d %d", &x, &y);
			d[y][++a[y]] = x;
		}
		scanf("%d", &w);
		printf("%d\n", b(w));
	}
}