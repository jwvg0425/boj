#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		float sum = 0.0f;

		scanf("%d", &n);

		int k = 0;

		for (int j = 0; j < n; j++)
		{
			int c;
			float g;
			scanf("%d %f", &c, &g);
			sum += c * g;
			k += c;
		}

		printf("%d %.1f\n", k, sum / k);

	}

	return 0;
}