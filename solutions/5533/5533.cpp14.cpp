#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	int n;
	int scores[201][3];
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &scores[i][0], &scores[i][1], &scores[i][2]);
	}

	for (int i = 0; i < n; i++)
	{
		int score = 0;

		for (int j = 0; j < 3; j++)
		{
			bool isSame = false;

			for (int k = 0; k < n; k++)
			{
				if (i == k)
					continue;

				if (scores[i][j] == scores[k][j])
				{
					isSame = true;
					break;
				}
			}

			if (!isSame)
				score += scores[i][j];
		}

		printf("%d\n", score);
	}

	return 0;
}