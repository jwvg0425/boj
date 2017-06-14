#include<stdio.h>

int a[50];

int main(void)
{
	int T, n, cx, cy, r, x1, y1, x2, y2, i, d, k;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);

		k = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%d %d %d", &cx, &cy, &r);
			d = (cx - x1)*(cx - x1) + (cy - y1)*(cy - y1);
			if (d < r*r)a[i] = T+1;
			d = (cx - x2)*(cx - x2) + (cy - y2)*(cy - y2);
			if (d < r*r)
			{
				if (a[i] == T + 1)a[i] = 0;
				else a[i] = T + 1;
			}
		}
		
		for (i = 0; i < n; i++)
		{
			if(a[i] == T + 1) k++;
		}

		printf("%d\n", k);

	}
}