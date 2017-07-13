#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int table[100001][5][5];
std::vector<int> foot;

int force(int foot, int goal)
{
	if (foot == 0)
		return 2;
	else if (foot == goal)
		return 1;
	else if (abs(foot - goal) == 1 || abs(foot-goal) == 3)
		return 3;
	else
		return 4;
}

int solve(int idx, int left, int right)
{
	if (idx == foot.size())
		return 0;

	if (table[idx][left][right] != -1)
		return table[idx][left][right];

	int& res = table[idx][left][right];

	//왼발 맞추는 경우, 오른발 맞추는 경우 둘 중 더 작은 쪽
	int leftfit = force(left, foot[idx]) + solve(idx + 1, foot[idx], right);
	int rightfit = force(right, foot[idx]) + solve(idx + 1, left, foot[idx]);

	res = std::min(leftfit, rightfit);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;

	while (true)
	{
		scanf("%d", &n);

		if (n == 0)
			break;

		foot.push_back(n);
	}

	printf("%d", solve(0, 0, 0));
}