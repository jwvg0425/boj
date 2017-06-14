#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;
	int max = 0;
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int score;
		scanf("%d", &score);
		sum += score;
		max = std::max(max, score);
	}

	printf("%.2f", static_cast<float>(sum) / n / max * 100);
}