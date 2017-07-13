#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	std::vector<int> scores;

	for (int i = 0; i < n; i++)
	{
		int score1, score2;
		scanf("%d.%d", &score1, &score2);

		scores.push_back(score1 * 10 + score2);
	}

	std::sort(scores.begin(), scores.end());

	int sum = 0;

	for (int i = k; i < n - k; i++)
	{
		sum += scores[i];
	}

	int sum2 = sum + scores[k] * k + scores[n - k - 1] * k;

	printf("%.2lf\n%.2lf", sum * 0.1 / (n - 2 * k) + 1e-6, sum2 * 0.1 / n + 1e-6);

	return 0;
}