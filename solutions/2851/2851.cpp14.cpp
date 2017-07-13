#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		int score;

		scanf("%d", &score);

		if (abs(100 - sum) >= abs(100 - sum - score))
			sum += score;
		else
			break;
	}

	printf("%d", sum);

	return 0;
}