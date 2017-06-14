#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int n;
int missions[21][21];

double table[1 << 20];

//미션이 cleared 만큼 해결됐을 때 최대 확률
//1~cleared개수만큼 순서대로 미션 해결에 할당됐다고 생각
double solve(int cleared)
{
	//base case - all clear
	if (cleared == (1 << n) - 1)
		return 1.0;

	if (table [cleared] >= 0.0)
		return table[cleared];

	double& res = table[cleared];

	res = 0.0;

	int k = std::bitset<32>(cleared).count();

	for (int i = 0; i < n; i++)
	{
		if ((cleared & (1 << i)) != 0)
			continue;

		double prob = static_cast<double>(missions[k][i]) / 100.0;

		res = std::max(res, prob * solve(cleared | (1 << i)));
	}

	return res;
}


int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &missions[i][j]);
		}
	}

	for (int i = 0; i < (1 << n); i++)
		table[i] = -1.0;

	printf("%lf", solve(0) * 100.0);

	return 0;
}