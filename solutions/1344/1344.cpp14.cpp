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

int a, b;

double table[91][20][20];

double solve(int time, int ag, int bg)
{
	if (time == 0)
	{
		if (ag == 0 && bg == 0)
			return 1.0;

		return 0.0;
	}

	if (table[time][ag][bg] >= 0.0)
		return table[time][ag][bg];

	double& res = table[time][ag][bg];

	res = solve(time - 5, ag, bg) * (100 - a) * 0.01 * (100 - b) * 0.01;

	if (ag > 0)
		res += solve(time - 5, ag - 1, bg) * (a * 0.01) * (100 - b) * 0.01;

	if (bg > 0)
		res += solve(time - 5, ag, bg - 1) * (b * 0.01) * (100 - a) * 0.01;

	if (ag > 0 && bg > 0)
		res += solve(time - 5, ag - 1, bg - 1) * (a * 0.01) * (b * 0.01);

	return res;
}

int main()
{
	for (int i = 0; i < 91; i++)
		for (int j = 0; j < 20; j++)
			for (int k = 0; k < 20; k++)
				table[i][j][k] = -1.0;

	scanf("%d %d", &a, &b);

	std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

	double prob = 0.0;

	for (auto& p : primes)
	{
		for (int i = 0; i < 20; i++)
		{
			prob += solve(90, p, i);

			if (std::find(primes.begin(), primes.end(), i) == primes.end())
			{
				prob += solve(90, i, p);
			}
		}
	}

	printf("%lf", prob);

	return 0;
}