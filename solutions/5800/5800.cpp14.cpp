#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int main()
{
	int k;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int n; 
		scanf("%d", &n);

		std::vector<int> scores;

		for (int j = 0; j < n; j++)
		{
			int score;
			scanf("%d", &score);
			scores.push_back(score);
		}

		std::sort(scores.begin(), scores.end());

		int gap = 0;

		for (int j = 1; j < n; j++)
		{
			gap = std::max(gap, scores[j] - scores[j - 1]);
		}

		printf("Class %d\n", i + 1);
		printf("Max %d, Min %d, Largest gap %d\n", scores.back(), scores[0], gap);
	}

	return 0;
}