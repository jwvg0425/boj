#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;
int table[1001];
std::vector<int> scores;

int solve(int idx)
{
	if (idx == scores.size())
		return 0;

	if (table[idx] != -1)
		return table[idx];

	int& res = table[idx];
	res = 0;
	int min = scores[idx];
	int max = scores[idx];

	for (int j = idx; j < scores.size(); j++)
	{
		max = std::max(max, scores[j]);
		min = std::min(min, scores[j]);
		res = std::max(res, max - min + solve(j + 1));
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int score;
		scanf("%d", &score);
		scores.push_back(score);
	}

	printf("%d", solve(0));


	return 0;
}