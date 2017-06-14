#include <stdio.h>
#include <algorithm>

int main()
{
	int scores[3] = { 0, };
	int counts[3][4] = { 0, };

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int points[3];
		scanf("%d %d %d", &points[0], &points[1], &points[2]);

		for (int j = 0; j < 3; j++)
		{
			scores[j] += points[j];
			counts[j][points[j]]++;
		}
	}

	int maxScore = std::max({ scores[0], scores[1], scores[2] });
	int maxCount = 0;
	int maxIndex = 0;

	for (int i = 0; i < 3; i++)
	{
		if (scores[i] == maxScore)
		{
			maxCount++;
			maxIndex = i;
		}
	}

	if (maxCount == 1)
	{
		printf("%d %d", maxIndex + 1, scores[maxIndex]);
		return 0;
	}

	int maxThreeCount = std::max({ counts[0][3], counts[1][3], counts[2][3] });
	maxCount = 0;

	for (int i = 0; i < 3; i++)
	{
		if (counts[i][3] == maxThreeCount)
		{
			maxCount++;
			maxIndex = i;
		}
	}

	if (maxCount == 1 && scores[maxIndex] == maxScore)
	{
		printf("%d %d", maxIndex + 1, scores[maxIndex]);
		return 0;
	}

	int maxTwoCount = std::max({ counts[0][2], counts[1][2], counts[2][2] });
	maxCount = 0;

	for (int i = 0; i < 3; i++)
	{
		if (counts[i][2] == maxTwoCount)
		{
			maxCount++;
			maxIndex = i;
		}
	}

	if (maxCount == 1 && scores[maxIndex ]== maxScore)
	{
		printf("%d %d", maxIndex + 1, scores[maxIndex]);
		return 0;
	}

	printf("0 %d", maxScore);

	return 0;
}