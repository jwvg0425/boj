#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int N;

		scanf("%d", &N);

		int sum = 0;

		for (int j = 0; j < N; j++)
		{
			int s;
			scanf("%d", &s);
			sum += s;
		}

		printf("%d\n", sum);
	}
}